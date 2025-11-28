/***************************************************************************
                          emul.c  -  main file for emulator.
                             -------------------
    copyright            : (C) 2000 by aaditya sood
    email                : aaditya@users.sourceforge.net
 ***************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>
#include"eprintf.h"
#include"top.h"
#include"opfuncdecl.h"
#include"mapdecl.h"
#include"instrtable.c"	/*the instruction table with ophandler address and name */

void printtask(task85 * t);
void runtask(task85 * t);
task85 *inittask(void);
void deinittask(task85 * t);
void buildtask(FILE * fp, task85 * t);
void inithandle(void (*handleop[])(void *t));
void buildhandle(void (*handleop[])(void *t));
void printhandle(task85 * t);
void def_handle(task85 * t);

/*set to 1-4 for lot of info(but can be overriden through cmd line)*/
unsigned int e85debug = 1;
/*set to 1 for lot of verbose output*/
unsigned int e85verbose = 1;



const char emuldate[] = __DATE__;
const char emultime[] = __TIME__;
const char emulId[] = "e85 8085 emulator.\n(c)2000 aaditya sood \
  <aaditya@users.sourceforge.net>\nCVS Log $Date: 2001/02/09 03:34:15 $ $Revision: 1.25 $.\nVersion 0.81";
const char emulHelp[] =
    " Usage: e85 [-d num] [-v] [-V] [-f file] [-h]\n\t-f file :read input from file instead of standard input\n\t-v \
:enable verbose output\n\t-V :show version info\n\t-d :enable debugging output at num level(1-4)\n\t-h :show this help message and quit";

/*main: process switches, read the data, setup task, execute it and 
 * then deinit(destroy) task                                      */
int main(int argc, char **argv)
{
	extern int optind;
	extern char *optarg;

	int c, quit = 0;
	FILE *fp = NULL;
	task85 *t = NULL;

	setprogname("e85");	/* from tpop, see eprintf.c */
	e85debug = 0;
	e85verbose = 0;
	fp = stdin;

	while ((c = getopt(argc, argv, "d:vhHVf:")) != EOF)
		switch (c) {
		case 'v':
			e85verbose = 1;
			break;
		case 'd':
			e85debug = atoi(optarg);
			break;
		case 'V':
			printf("%s Compiled at %s on %s\n\n", emulId,
			       emultime, emuldate);
			break;
		case 'f':
			if ((fp = fopen(optarg, "r")) == NULL) {
				perror(optarg);
				quit = 1;
			}
			break;
		case 'h':
		case 'H':
		default:
			weprintf("%s", emulHelp);
			quit = 1;
			break;
		}


	if (quit)
		exit(1);
	t = inittask();
	if (e85debug)
		printtask(t);

	buildtask(fp, t);
	if (e85debug)
		printtask(t);
	if (e85debug > 1)
		printhandle(t);

	runtask(t);
	deinittask(t);

	exit(0);
}

/*runtask: execute the task calling each handler. stop on "nop" - so if we
 * run into unintialized memory(very common) we won't swamp the user with
 * bogus register results. Technically *NOT* correct: should be changed -
 * ideally have a switch controlling this behaviour */
void runtask(task85 * t)
{
	for (; t->memory[t->PC];) {
		if (e85debug || e85verbose)
			printtask(t);
		t->handleop[t->memory[t->PC]] (t);
	}
	printtask(t);

	return;
}

/*inittask: allocate and setup default values for a task. Have a sane
 * value for all the registers/flags/pointers.                               */
task85 *inittask(void)
{
	int i;
	task85 *t;

	if ((t = malloc(sizeof(task85))) == NULL)
		eprintf("inittask:no mem for task85");
	t->memory = malloc(MEMSIZE * sizeof(unsigned char));
	if (t->memory == NULL)
		eprintf("inittask:no memory for data");

	for (i = 0; i < MEMSIZE; i++)
		t->memory[i] = 0;
	t->PC = USRSTART;
	t->SP = t->A = t->B = t->C = t->D = t->E = t->H = t->L = t->M =
	    t->CF = t->ZF = t->PF = t->AC = t->SF = 0;

	inithandle(t->handleop);	/* initialize handlers */

	if ((t->opname = (char **) malloc(sizeof(char *) * 0xFF + 1)) ==
	    NULL) eprintf("inittask:no memory for opnames");
	for (i = 0; i <= 0xFF; i++)
		t->opname[i] = estrdup(instrtable[i].opname);

	//t->opname = opnames;  /* set op-name table */
	if (e85debug > 1)
		for (i = 0; i <= 0xFF; i++)
			weprintf("%02X -> %s", i, t->opname[i]);
	return t;
}

/*deinittask: deinit task - free all memory in it taking care if non NULL.
 * so calling twice will not be an error(ANSI C allows that but prudence...)*/
void deinittask(task85 * t)
{
	int i;
	if (t->memory)
		free(t->memory);

	for (i = 0; i <= 0xFF; i++)
		if (t->opname[i])
			free(t->opname[i]);

	if (t)
		free(t);
	t = NULL;
	return;
}

/*buildtask: read the opcodes into a task from fp until EOF/error/USREND
 * comes up. USRSTART onwards (by default on the 8085 kit I work on).  */
void buildtask(FILE * fp, task85 * t)
{
	unsigned int op = 0;
	int i;

	for (i = USRSTART; (fscanf(fp, "%X", &op) == 1) && (i < USREND);
	     i++)
		(t->memory)[i] = (unsigned char) (op);

	buildhandle(t->handleop);	/* build handlers */
	return;
}

/*inithandle: set handle to def_handle for all opcodes initially. So we
 * don't get any core dumps ;)                                       */
void inithandle(void (*handleop[0xFF]) (void *t))
{
	int i;
	for (i = 0; i < 256; i++)
		handleop[i] = (void (*)(void *)) def_handle;
	return;
}

/*printtask: print all registers, flags, op name for a task */
void printtask(task85 * t)
{
	fprintf(stdout,
		"PC:%04X SP:%04X  A:%X B:%X C:%X D:%X E:%X H:%X L:%X \
M:%X  CF:%01X ZF:%01X PF:%01X  op:%02X %s\n", t->PC, t->SP, t->A, t->B, t->C, t->D, t->E, t->H, t->L, t->M, t->CF, t->ZF, t->PF, t->memory[t->PC], t->opname[t->memory[t->PC]]);
	return;
}

/*printhandle: print the handler address table for a task except for 
 * default handler def_handle                                       */
void printhandle(task85 * t)
{
	int i;
	for (i = 0; i <= 0xFF; i++)
		if (t->handleop[i] != (void (*)(void *)) def_handle)
			weprintf("%X->%p", i,
				 (void (*)()) (t->handleop[i]));
	return;
}


/*buildhandle: set the differnt handles for different opcodes
 * handleop.c is generated by gencode.py with -d                */
void buildhandle(void (*handleop[0xFF]) (void *t))
{
	int i;
	for (i = 0; i <= 0xFF; i++)
		handleop[i] = (void (*)(void *)) instrtable[i].ophandler;
	return;
}

