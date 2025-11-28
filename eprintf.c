// some error wrapper functions, from k&p tpop
// thanx...

#include<stdio.h>
#include<stdarg.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

static char *name = NULL;

//progname: return stored name of program
char *progname(void)
{
	return name;
}

// eprintf: print error message and exit
void eprintf(char *fmt, ...)
{
	va_list args;

	fflush(stdout);
	if (progname() != NULL)
		fprintf(stderr, "%s:", progname());
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);

	if (fmt[0] != '\0' && fmt[strlen(fmt) - 1] == ':')
		fprintf(stderr, "%s", strerror(errno));

	fprintf(stderr, "\n");
	exit(2);		// conventional value for failed execution 
}

// weprintf: print warning message and return
void weprintf(char *fmt, ...)
{
	va_list args;

	fflush(stdout);
	if (progname() != NULL)
		fprintf(stderr, "%s:", progname());
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);

	if (fmt[0] != '\0' && fmt[strlen(fmt) - 1] == ':')
		fprintf(stderr, "%s", strerror(errno));

	fprintf(stderr, "\n");
	return;
}

// estrdup: duplicate a string, report on error
char *estrdup(char *s)
{
	char *t;

	t = (char *) malloc(strlen(s) + 1);
	if (t == NULL)
		eprintf("estrdup(\"%.20s\") failed:", s);
	strcpy(t, s);
	return t;
}



// setprogname: set stored name of program
void setprogname(char *str)
{
	name = estrdup(str);
}

