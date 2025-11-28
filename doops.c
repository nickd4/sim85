/***************************************************************************
                          doops.cpp  -  actually emulate instructions.
                             -------------------
    copyright            : (C) 2000 by aaditya sood
    email                : aaditya@users.sourceforge.net
 ***************************************************************************/
/*implement the "real" emulation functions. All the intelligence is here. 
 *centralized management (one MOV instead of ~30!). All generic code should
 *be added here and then corresponding mapping handler and declaration
 *should be added to gencode.py. This way the makefile can cope with the 
 *complexity and the structure remains intact for others to _understand_ 
 *your work. :-)
 */
#ifndef AS_GEN_DECL		/*define for generating prototypes with cproto */
#include<stdio.h>
#endif
#include"top.h"
#include"opfuncdecl.h"
#include"eprintf.h"

void doADD(unsigned char *reg, REG_STATE_2)
{				/* ADD reg to A */
	*(CF) = 0;
	if ((*(A) + *reg) > 0xFF)
		*(CF) = 1;
	*(A) = *(A) + (*reg);
	(*PC)++;
	return;
}

void doADC(unsigned char *reg, REG_STATE_2)
{				/* ADD with carry */
	if ((*(A) + *reg + *(CF)) > 0xFF) {
		*(A) = *(A) + *reg + *(CF);
		*(CF) = 1;
	} else {
		*(A) = *(A) + *reg + *(CF);
		*(CF) = 0;
	}
	(*PC)++;
	return;
}

void doSUB(unsigned char *reg, REG_STATE_2)
{				/* SUB reg from A */
	*(CF) = 0;
	if (*reg > *(A))
		*(CF) = 1;
	*(A) -= *reg;
	(*PC)++;
	return;
}

void doSBB(unsigned char *reg, REG_STATE_2)
{				/* SUB with borrow reg from A */
	if (*(A) < (*reg + *(CF))) {
		*(A) = *(A) - *reg - *(CF);
		*(CF) = 1;
	} else {
		*(A) = *(A) - *reg - *(CF);
		*(CF) = 0;
	}
	(*PC)++;
	return;
}

void doMOV(unsigned char *reg1, unsigned char *reg2, REG_STATE_2)
{				/* MOV reg2 to reg1 */
	*reg1 = *reg2;
	(*PC)++;
	return;
}

void doINX(unsigned char *regh, unsigned char *regl, REG_STATE_2)
{				/*inc pair regh:regl */
	*(CF) = 0;
	if ((*regl == 0xFF) && (*regl == 0xFF))
		*(CF) = 1;
	if (*regl == 0xFF)
		(*regh)++;
	(*regl)++;
	(*PC)++;
	return;
}

void doINXSP(unsigned int *sp, REG_STATE_2)
{				/* increment SP */
	*(CF) = 0;
	if (*sp == 0xFFFF)
		*(CF) = 1;
	(*sp)++;
	return;
}

void doDCX(unsigned char *regh, unsigned char *regl, REG_STATE_2)
{				/*dec pair regh:regl */
	*(CF) = 0;
	if ((*regl == 0) && (*regh == 0))
		*(CF) = 1;
	if (*regl == 0)
		(*regh)--;
	(*regl)--;
	(*PC)++;
	return;
}

void doDCXSP(unsigned int *sp, REG_STATE_2)
{				/* decrement SP */
	*(CF) = 0;
	if (*sp == 0)
		*(CF) = 1;
	(*sp)++;
	return;
}

void doINR(unsigned char *reg, REG_STATE_2)
{				/* increment reg */
	*(CF) = 0;
	if (*reg == 0xFF)
		*(CF) = 1;
	(*reg)++;
	(*PC)++;
	return;
}

void doDCR(unsigned char *reg, REG_STATE_2)
{				/* decrement reg */
	*(CF) = 0;
	if (*reg == 0)
		*(CF) = 1;
	(*reg)--;
	(*PC)++;
	return;
}

void doCMP(unsigned char *reg, REG_STATE_2)
{				/* compare with A */
	if (*(A) < *reg) {
		*(CF) = 1;
		*(ZF) = 0;
	}
	if (*(A) == *reg) {
		*(CF) = 0;
		*(ZF) = 1;
	}
	if (*(A) > *reg) {
		*(CF) = 0;
		*(ZF) = 0;
	}
	*(PF) = !(((*(A)
		    >> 7) ^ (*(A) >> 6) ^ (*(A) >> 5) ^ (*(A) >> 4) ^ (*(A)
								       >>
								       3) ^
		   (*(A) >> 2) ^ (*(A) >> 1) ^ (*(A))) & 1);
	(*PC)++;
	return;
}


void doANA(unsigned char *reg, REG_STATE_2)
{				/* AND reg with A  */
	*AC = 1;
	(*CF) = (*SF) = 0;
	(*A) = (*A) & *reg;
	(*ZF) = !(*A);
	if ((*A) > 127)
		(*SF) = 1;
	(*PF) = !((((*A)
		    >> 7) ^ ((*A) >> 6) ^ ((*A) >> 5) ^ ((*A) >> 4) ^ ((*A)
								       >>
								       3) ^
		   ((*A) >> 2) ^ ((*A) >> 1) ^ ((*A))) & 1);
	(*PC)++;
	return;
}

void doXRA(unsigned char *reg, REG_STATE_2)
{				/* XOR reg with A */
	*(CF) = (*AC) = *(SF) = 0;
	*(A) ^= *reg;
	if (*(A) > 127)
		*(SF) = 1;
	*(ZF) = !(*(A));
	*(PF) = !(((*(A)
		    >> 7) ^ (*(A) >> 6) ^ (*(A) >> 5) ^ (*(A) >> 4) ^ (*(A)
								       >>
								       3) ^
		   (*(A) >> 2) ^ (*(A) >> 1) ^ (*(A))) & 1);
	(*PC)++;
	return;
}


void doMVI(unsigned char *reg, REG_STATE_2)
{				/* MOV immediate */
	*reg = memory[(*PC) + 1];
	(*PC) += 2;
	return;
}

void doJMPS(REG_STATE_2)
{				/* jump to address */
	unsigned int newPC = 0;
	newPC = (memory[(*PC) + 2] << 8) + memory[(*PC) + 1];

	switch (memory[(*PC)]) {
	case 0xc3:		/* JMP */
		(*PC) = newPC;
		break;
	case 0xc2:		/* JNZ */
		if (*(ZF) == 0)
			(*PC) = newPC;
		else
			(*PC) += 3;
		break;
	case 0xca:		/* JZ */
		if (*(ZF) == 1)
			(*PC) = newPC;
		else
			(*PC) += 3;
		break;
	case 0xda:		/* JC */
		if (*(CF) == 1)
			(*PC) = newPC;
		else
			(*PC) += 3;
		break;
	case 0xd2:		/* JNC */
		if (*(CF) == 0)
			(*PC) = newPC;
		else
			(*PC) += 3;
		break;
	case 0xf2:		/* JP */
		if (*(SF) == 0)
			(*PC) = newPC;
		else
			(*PC) += 3;
		break;
	case 0xfa:		/* JN */
		if (*(SF) == 1)
			(*PC) = newPC;
		else
			(*PC) += 3;
		break;
	case 0xea:		/* JPE */
		if (*(PF) == 1)
			(*PC) = newPC;
		else
			(*PC) += 3;
		break;
	case 0xe2:		/* JPO */
		if (*(PF) == 0)
			(*PC) = newPC;
		else
			(*PC) += 3;
		break;
	default:		/* oops! */
		eprintf("%02X handled to doJMPS() at %04X newPC:%04X\n",
			memory[(*PC)], (*PC), newPC);
		break;
	}
	return;
}

void doLXI(unsigned char *regh, unsigned char *regl, REG_STATE_2)
{				/* load immediate regh:regl */
	*regl = memory[(*PC) + 1];
	*regh = memory[(*PC) + 2];
	(*PC) += 3;
	return;
}

void doLXISP(unsigned int *sp, REG_STATE_2)
{				/* load immediate SP */
	*sp = (memory[(*PC) + 2] << 8) + memory[(*PC) + 1];
	(*PC) += 3;
	return;
}

void doLDA(REG_STATE_2)
{
	*(A) = memory[(memory[(*PC) + 2] << 8) + memory[(*PC) + 1]];
	(*PC) += 3;
	return;
}

void doLDAX(unsigned char *regh, unsigned char *regl, REG_STATE_2)
{				/*load ax indirect */
	*(A) = memory[((*regh) << 8) + *regl];
	(*PC)++;
	return;
}

void doSTAX(unsigned char *regh, unsigned char *regl, REG_STATE_2)
{				/*store ax indirect */
	memory[((*regh) << 8) + *regl] = *(A);
	(*PC)++;
	return;
}

void doSTA(REG_STATE_2)
{				/* store ax direct */
	memory[(memory[(*PC) + 2] << 8) + memory[(*PC) + 1]] = *(A);
	(*PC) += 3;
	return;
}

void doPUSH(unsigned char *regh, unsigned char *regl, REG_STATE_2)
{				/* PUSH regh:regl */
	if ((*SP) <= 1)
		fprintf(stderr, "warning: SP=%04X\n", *(SP));
	(*SP)--;
	memory[(*SP)] = *regh;
	(*SP)--;
	memory[(*SP)] = *regl;
	(*PC)++;
	return;
}

void doPOP(unsigned char *regh, unsigned char *regl, REG_STATE_2)
{				/* POP regh:regl */
	*regl = memory[*(SP)];
	(*SP)++;
	*regh = memory[*(SP)];
	(*SP)++;
	(*PC)++;
	return;
}

void doXCHG(REG_STATE_2)
{				/*XCHG H:L and D:E */
	unsigned char t1, t2;
	t1 = *H;
	t2 = *L;
	*H = *D;
	*L = *E;
	*D = t1;
	*E = t2;
	return;
}

void doRET(REG_STATE_2)
{				/* do a RET */
	int newPC;
	if (*SP < 0 || *SP > USREND)
		eprintf("error: RET PC:%04X SP:%04X out of bounds\n", *PC,
			*SP);

	newPC = memory[*SP];
	(*SP)++;
	newPC += (memory[*SP] << 8);
	(*SP)++;
	*PC = newPC + 3;
	return;
}

void doSTC(REG_STATE_2)
{				/*do STC  */
	*CF = 1;
	return;
}

void doSPHL(REG_STATE_2)
{				/*load H:L into SP */
	*SP = ((*H) << 8) + *L;
	return;
}


void doSIM(REG_STATE_2)
{				/*emulate SIM  */
	/*we do not (yet) emulate SIM */
	weprintf("SIM not emulated");
	return;
}

void doSHLD(REG_STATE_2)
{				/*store L:H  */
	char *addr;
	addr = (char *) ((memory[(*PC) + 2] << 8) + memory[(*PC) + 1]);
	*addr = *L;
	*(addr + 1) = *H;
	return;
}

/*do a CALL: if *SP goes below 0 we might have a SIGSEGV, 
  so abort(what 8085 does? i don't know yet!)    */
void doCALL(REG_STATE_2)
{
	int newPC;
	if ((*SP) < 2)
		eprintf("error: CALL PC:%04X SP=%04X out of bound:)\n",
			*PC, *SP);

	(*SP)--;
	memory[*SP] = ((*PC) >> 8) & 0xFF;
	(*SP)--;
	memory[*SP] = (*PC) & 0xFF;
	newPC = memory[(*PC) + 1] + ((memory[(*PC) + 2]) << 8);
	*PC = newPC;
	return;
}
