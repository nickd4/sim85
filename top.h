/***************************************************************************
                     top.h  -  universal header file for emulator.     
                             -------------------
    copyright            : (C) 2000 by aaditya sood
    email                : aaditya@users.sourceforge.net
 ***************************************************************************/

#ifndef _TOP_H_
#define _TOP_H_

#define UINT unsigned int
#define UCHAR unsigned char

/*these ugly defines are needed to pass all context from middle level handler
  in opmap.c to "real" emulating functions in doops.c */
#define REG_STATE &(t->A),&(t->B),&(t->C),&(t->D),&(t->E),\
        &(t->H),&(t->L),&(t->M),&(t->PC),&(t->SP),\
        &(t->PF),&(t->CF),&(t->SF),&(t->ZF),&(t->AC),t->memory

#define REG_STATE_2 UCHAR *A,UCHAR *B,UCHAR *C,UCHAR *D,UCHAR *E,\
        UCHAR *H,UCHAR *L,UCHAR *M,UINT *PC,UINT *SP,\
        UCHAR *PF,UCHAR *CF,UCHAR *SF,UCHAR *ZF,UCHAR *AC,UCHAR *memory

/*ideally should be adjustable between different threads but right
now needs recompilation to change these constants.*/
enum {
	MEMSIZE = 0x8000,	/*max memory */
	USRSTART = 0x4100,	/*user space start address */
	USREND = 0x6000		/*user space end address */
};

/*an 8085 task context.contains all the registers,memory,handler addresses
for one single thread.Can be used to run several 8085s together.*/
typedef struct {
	unsigned int PC, SP;
	unsigned char A, B, C, D, E, H, L, M;
	unsigned char PF, CF, SF, ZF, AC;	/* use as boolean flags */
	unsigned char *memory;
	void (*handleop[256]) (void *t);	/* op emulator functions */
	char **opname;		/* name table for opcodes */
} task85;

/*an 8085 instruction context. contains the handler and name for the instruction, later could also be modified ro conatin instruction length:)*/
typedef struct {
	void (*ophandler) (task85 * t);
	char *opname;
} instr85;

#endif
