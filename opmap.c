/***************************************************************************
                     opmap.c  -  set handler code pointers at runtime.
                             -------------------
    copyright            : (C) 2000 by aaditya sood
    email                : aaditya@users.sourceforge.net
 ***************************************************************************/


#include"top.h"
#include"opfuncdecl.h"



/******************************************************
 MOV
******************************************************/

void doMOV40(task85 *t){	/* MOV B,B */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->B),&(t->B),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV41(task85 *t){	/* MOV B,C */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->B),&(t->C),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV42(task85 *t){	/* MOV B,D */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->B),&(t->D),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV43(task85 *t){	/* MOV B,E */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->B),&(t->E),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV44(task85 *t){	/* MOV B,H */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->B),&(t->H),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV45(task85 *t){	/* MOV B,L */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->B),&(t->L),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV46(task85 *t){	/* MOV B,M */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->B),&(t->M),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV47(task85 *t){	/* MOV B,A */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->B),&(t->A),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV48(task85 *t){	/* MOV C,B */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->C),&(t->B),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV49(task85 *t){	/* MOV C,C */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->C),&(t->C),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV4A(task85 *t){	/* MOV C,D */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->C),&(t->D),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV4B(task85 *t){	/* MOV C,E */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->C),&(t->E),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV4C(task85 *t){	/* MOV C,H */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->C),&(t->H),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV4D(task85 *t){	/* MOV C,L */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->C),&(t->L),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV4E(task85 *t){	/* MOV C,M */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->C),&(t->M),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV4F(task85 *t){	/* MOV C,A */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->C),&(t->A),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV50(task85 *t){	/* MOV D,B */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->D),&(t->B),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV51(task85 *t){	/* MOV D,C */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->D),&(t->C),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV52(task85 *t){	/* MOV D,D */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->D),&(t->D),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV53(task85 *t){	/* MOV D,E */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->D),&(t->E),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV54(task85 *t){	/* MOV D,H */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->D),&(t->H),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV55(task85 *t){	/* MOV D,L */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->D),&(t->L),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV56(task85 *t){	/* MOV D,M */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->D),&(t->M),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV57(task85 *t){	/* MOV D,A */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->D),&(t->A),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV58(task85 *t){	/* MOV E,B */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->E),&(t->B),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV59(task85 *t){	/* MOV E,C */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->E),&(t->C),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV5A(task85 *t){	/* MOV E,D */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->E),&(t->D),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV5B(task85 *t){	/* MOV E,E */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->E),&(t->E),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV5C(task85 *t){	/* MOV E,H */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->E),&(t->H),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV5D(task85 *t){	/* MOV E,L */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->E),&(t->L),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV5E(task85 *t){	/* MOV E,M */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->E),&(t->M),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV5F(task85 *t){	/* MOV E,A */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->E),&(t->A),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV60(task85 *t){	/* MOV H,B */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->H),&(t->B),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV61(task85 *t){	/* MOV H,C */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->H),&(t->C),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV62(task85 *t){	/* MOV H,D */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->H),&(t->D),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV63(task85 *t){	/* MOV H,E */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->H),&(t->E),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV64(task85 *t){	/* MOV H,H */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->H),&(t->H),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV65(task85 *t){	/* MOV H,L */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->H),&(t->L),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV66(task85 *t){	/* MOV H,M */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->H),&(t->M),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV67(task85 *t){	/* MOV H,A */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->H),&(t->A),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV68(task85 *t){	/* MOV L,B */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->L),&(t->B),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV69(task85 *t){	/* MOV L,C */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->L),&(t->C),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV6A(task85 *t){	/* MOV L,D */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->L),&(t->D),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV6B(task85 *t){	/* MOV L,E */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->L),&(t->E),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV6C(task85 *t){	/* MOV L,H */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->L),&(t->H),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV6D(task85 *t){	/* MOV L,L */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->L),&(t->L),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV6E(task85 *t){	/* MOV L,M */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->L),&(t->M),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV6F(task85 *t){	/* MOV L,A */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->L),&(t->A),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV70(task85 *t){	/* MOV M,B */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->M),&(t->B),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV71(task85 *t){	/* MOV M,C */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->M),&(t->C),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV72(task85 *t){	/* MOV M,D */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->M),&(t->D),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV73(task85 *t){	/* MOV M,E */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->M),&(t->E),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV74(task85 *t){	/* MOV M,H */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->M),&(t->H),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV75(task85 *t){	/* MOV M,L */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->M),&(t->L),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV77(task85 *t){	/* MOV M,A */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->M),&(t->A),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV78(task85 *t){	/* MOV A,B */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->A),&(t->B),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV79(task85 *t){	/* MOV A,C */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->A),&(t->C),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV7A(task85 *t){	/* MOV A,D */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->A),&(t->D),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV7B(task85 *t){	/* MOV A,E */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->A),&(t->E),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV7C(task85 *t){	/* MOV A,H */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->A),&(t->H),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV7D(task85 *t){	/* MOV A,L */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->A),&(t->L),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV7E(task85 *t){	/* MOV A,M */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->A),&(t->M),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMOV7F(task85 *t){	/* MOV A,A */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMOV(&(t->A),&(t->A),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

/******************************************************
 ADD
******************************************************/

void doADD80(task85 *t){	 /* ADD B */
   t->M=t->memory[((t->H)<<8)+t->L];
   doADD(&(t->B),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doADD81(task85 *t){	 /* ADD C */
   t->M=t->memory[((t->H)<<8)+t->L];
   doADD(&(t->C),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doADD82(task85 *t){	 /* ADD D */
   t->M=t->memory[((t->H)<<8)+t->L];
   doADD(&(t->D),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doADD83(task85 *t){	 /* ADD E */
   t->M=t->memory[((t->H)<<8)+t->L];
   doADD(&(t->E),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doADD84(task85 *t){	 /* ADD H */
   t->M=t->memory[((t->H)<<8)+t->L];
   doADD(&(t->H),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doADD85(task85 *t){	 /* ADD L */
   t->M=t->memory[((t->H)<<8)+t->L];
   doADD(&(t->L),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doADD86(task85 *t){	 /* ADD M */
   t->M=t->memory[((t->H)<<8)+t->L];
   doADD(&(t->M),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doADD87(task85 *t){	 /* ADD A */
   t->M=t->memory[((t->H)<<8)+t->L];
   doADD(&(t->A),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

/******************************************************
 ADC
******************************************************/

void doADC88(task85 *t){	 /* ADC B */ 
   t->M=t->memory[((t->H)<<8)+t->L];
   doADC(&(t->B),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doADC89(task85 *t){	 /* ADC C */ 
   t->M=t->memory[((t->H)<<8)+t->L];
   doADC(&(t->C),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doADC8A(task85 *t){	 /* ADC D */ 
   t->M=t->memory[((t->H)<<8)+t->L];
   doADC(&(t->D),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doADC8B(task85 *t){	 /* ADC E */ 
   t->M=t->memory[((t->H)<<8)+t->L];
   doADC(&(t->E),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doADC8C(task85 *t){	 /* ADC H */ 
   t->M=t->memory[((t->H)<<8)+t->L];
   doADC(&(t->H),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doADC8D(task85 *t){	 /* ADC L */ 
   t->M=t->memory[((t->H)<<8)+t->L];
   doADC(&(t->L),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doADC8E(task85 *t){	 /* ADC M */ 
   t->M=t->memory[((t->H)<<8)+t->L];
   doADC(&(t->M),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doADC8F(task85 *t){	 /* ADC A */ 
   t->M=t->memory[((t->H)<<8)+t->L];
   doADC(&(t->A),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

/******************************************************
 SUB
******************************************************/

void doSUB90(task85 *t){	/* SUB B */
   t->M=t->memory[((t->H)<<8)+t->L];
   doSUB(&(t->B),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doSUB91(task85 *t){	/* SUB C */
   t->M=t->memory[((t->H)<<8)+t->L];
   doSUB(&(t->C),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doSUB92(task85 *t){	/* SUB D */
   t->M=t->memory[((t->H)<<8)+t->L];
   doSUB(&(t->D),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doSUB93(task85 *t){	/* SUB E */
   t->M=t->memory[((t->H)<<8)+t->L];
   doSUB(&(t->E),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doSUB94(task85 *t){	/* SUB H */
   t->M=t->memory[((t->H)<<8)+t->L];
   doSUB(&(t->H),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doSUB95(task85 *t){	/* SUB L */
   t->M=t->memory[((t->H)<<8)+t->L];
   doSUB(&(t->L),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doSUB96(task85 *t){	/* SUB M */
   t->M=t->memory[((t->H)<<8)+t->L];
   doSUB(&(t->M),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doSUB97(task85 *t){	/* SUB A */
   t->M=t->memory[((t->H)<<8)+t->L];
   doSUB(&(t->A),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

/******************************************************
 SBB
******************************************************/

void doSBB98(task85 *t){	/* SBB B */
   t->M=t->memory[((t->H)<<8)+t->L];
   doSBB(&(t->B),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doSBB99(task85 *t){	/* SBB C */
   t->M=t->memory[((t->H)<<8)+t->L];
   doSBB(&(t->C),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doSBB9A(task85 *t){	/* SBB D */
   t->M=t->memory[((t->H)<<8)+t->L];
   doSBB(&(t->D),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doSBB9B(task85 *t){	/* SBB E */
   t->M=t->memory[((t->H)<<8)+t->L];
   doSBB(&(t->E),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doSBB9C(task85 *t){	/* SBB H */
   t->M=t->memory[((t->H)<<8)+t->L];
   doSBB(&(t->H),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doSBB9D(task85 *t){	/* SBB L */
   t->M=t->memory[((t->H)<<8)+t->L];
   doSBB(&(t->L),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doSBB9E(task85 *t){	/* SBB M */
   t->M=t->memory[((t->H)<<8)+t->L];
   doSBB(&(t->M),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doSBB9F(task85 *t){	/* SBB A */
   t->M=t->memory[((t->H)<<8)+t->L];
   doSBB(&(t->A),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

/******************************************************
 CMP
******************************************************/

void doCMPB8(task85 *t){	/* CMP B */
   t->M=t->memory[((t->H)<<8)+t->L];
   doCMP(&(t->B),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doCMPB9(task85 *t){	/* CMP C */
   t->M=t->memory[((t->H)<<8)+t->L];
   doCMP(&(t->C),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doCMPBA(task85 *t){	/* CMP D */
   t->M=t->memory[((t->H)<<8)+t->L];
   doCMP(&(t->D),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doCMPBB(task85 *t){	/* CMP E */
   t->M=t->memory[((t->H)<<8)+t->L];
   doCMP(&(t->E),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doCMPBC(task85 *t){	/* CMP H */
   t->M=t->memory[((t->H)<<8)+t->L];
   doCMP(&(t->H),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doCMPBD(task85 *t){	/* CMP L */
   t->M=t->memory[((t->H)<<8)+t->L];
   doCMP(&(t->L),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doCMPBE(task85 *t){	/* CMP M */
   t->M=t->memory[((t->H)<<8)+t->L];
   doCMP(&(t->M),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doCMPBF(task85 *t){	/* CMP A */
   t->M=t->memory[((t->H)<<8)+t->L];
   doCMP(&(t->A),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

/******************************************************
 INR 
******************************************************/

void doINR3C(task85 *t){	/* INR A */
   t->M=t->memory[((t->H)<<8)+t->L];
   doINR(&(t->A),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doINR04(task85 *t){	/* INR B */
   t->M=t->memory[((t->H)<<8)+t->L];
   doINR(&(t->B),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doINR0C(task85 *t){	/* INR C */
   t->M=t->memory[((t->H)<<8)+t->L];
   doINR(&(t->C),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doINR14(task85 *t){	/* INR D */
   t->M=t->memory[((t->H)<<8)+t->L];
   doINR(&(t->D),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doINR1C(task85 *t){	/* INR E */
   t->M=t->memory[((t->H)<<8)+t->L];
   doINR(&(t->E),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doINR24(task85 *t){	/* INR H */
   t->M=t->memory[((t->H)<<8)+t->L];
   doINR(&(t->H),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doINR2C(task85 *t){	/* INR L */
   t->M=t->memory[((t->H)<<8)+t->L];
   doINR(&(t->L),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doINR34(task85 *t){	/* INR M */
   t->M=t->memory[((t->H)<<8)+t->L];
   doINR(&(t->M),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

/******************************************************
 DCR
******************************************************/

void doDCR3D(task85 *t){	/* DCR A */
   t->M=t->memory[((t->H)<<8)+t->L];
   doDCR(&(t->A),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doDCR05(task85 *t){	/* DCR B */
   t->M=t->memory[((t->H)<<8)+t->L];
   doDCR(&(t->B),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doDCR0D(task85 *t){	/* DCR C */
   t->M=t->memory[((t->H)<<8)+t->L];
   doDCR(&(t->C),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doDCR15(task85 *t){	/* DCR D */
   t->M=t->memory[((t->H)<<8)+t->L];
   doDCR(&(t->D),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doDCR1D(task85 *t){	/* DCR E */
   t->M=t->memory[((t->H)<<8)+t->L];
   doDCR(&(t->E),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doDCR25(task85 *t){	/* DCR H */
   t->M=t->memory[((t->H)<<8)+t->L];
   doDCR(&(t->H),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doDCR2D(task85 *t){	/* DCR L */
   t->M=t->memory[((t->H)<<8)+t->L];
   doDCR(&(t->L),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doDCR35(task85 *t){	/* DCR M */
   t->M=t->memory[((t->H)<<8)+t->L];
   doDCR(&(t->M),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

/******************************************************
 INX
******************************************************/

void doINX03(task85 *t){	/* INX B:C */
   doINX(&(t->B),&(t->C),REG_STATE);
   return;
}

void doINX13(task85 *t){	/* INX D:E */
   doINX(&(t->D),&(t->E),REG_STATE);
   return;
}

void doINX23(task85 *t){	/* INX H:L */
   doINX(&(t->H),&(t->L),REG_STATE);
   return;
}

/******************************************************
 DCX
******************************************************/

void doDCX0B(task85 *t){	/* DCX B :C */
   doDCX(&(t->B),&(t->C),REG_STATE);
   return;
}

void doDCX1B(task85 *t){	/* DCX D :E */
   doDCX(&(t->D),&(t->E),REG_STATE);
   return;
}

void doDCX2B(task85 *t){	/* DCX H :L */
   doDCX(&(t->H),&(t->L),REG_STATE);
   return;
}

/******************************************************
 DCX SP
******************************************************/

void doDCX3B(task85 *t){	/* DCX SP */
   doDCXSP(&(t->SP),REG_STATE);
   return;
}

/******************************************************
 INX SP
******************************************************/

void doINX33(task85 *t){	/* INX SP */
   doINXSP(&(t->SP),REG_STATE);
   return;
}

/******************************************************
 JMP
******************************************************/

void doJMP(task85 *t){	/* JMP */
   doJMPS(REG_STATE);
   return;
}

/******************************************************
 RET
******************************************************/

void doRETC9(task85 *t){	/* RET */
   doRET(REG_STATE);
   return;
}

/******************************************************
 SHLD
******************************************************/

void doSHLD22(task85 *t){	/* SHLD */
   doSHLD(REG_STATE);
   return;
}

/******************************************************
 SIM
******************************************************/

void doSIM30(task85 *t){	/* SIM */
   doSIM(REG_STATE);
   return;
}

/******************************************************
 STC
******************************************************/

void doSTC37(task85 *t){	/* STC */
   doSTC(REG_STATE);
   return;
}

/******************************************************
 MVI 
******************************************************/

void doMVI3E(task85 *t){	/* MVI A */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMVI(&(t->A),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMVI06(task85 *t){	/* MVI B */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMVI(&(t->B),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMVI0E(task85 *t){	/* MVI C */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMVI(&(t->C),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMVI16(task85 *t){	/* MVI D */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMVI(&(t->D),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMVI1E(task85 *t){	/* MVI E */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMVI(&(t->E),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMVI26(task85 *t){	/* MVI H */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMVI(&(t->H),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMVI2E(task85 *t){	/* MVI L */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMVI(&(t->L),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

void doMVI36(task85 *t){	/* MVI M */
   t->M=t->memory[((t->H)<<8)+t->L];
   doMVI(&(t->M),REG_STATE);
   t->memory[((t->H)<<8)+t->L]=t->M;
   return;
}

/******************************************************
 PUSH
******************************************************/

void doPUSHC5(task85 *t){	/* PUSH B:C*/
   doPUSH(&(t->B),&(t->C),REG_STATE);
   return;
}

void doPUSHD5(task85 *t){	/* PUSH D:E*/
   doPUSH(&(t->D),&(t->E),REG_STATE);
   return;
}

void doPUSHE5(task85 *t){	/* PUSH H:L*/
   doPUSH(&(t->H),&(t->L),REG_STATE);
   return;
}

/******************************************************
 POP
******************************************************/

void doPOPC1(task85 *t){	/* POP B:C */
   doPOP(&(t->B),&(t->C),REG_STATE);
   return;
}

void doPOPD1(task85 *t){	/* POP D:E */
   doPOP(&(t->D),&(t->E),REG_STATE);
   return;
}

void doPOPE1(task85 *t){	/* POP H:L */
   doPOP(&(t->H),&(t->L),REG_STATE);
   return;
}

/******************************************************
 LDA
******************************************************/

void doLDA3A(task85 *t){	/* LDA */
   doLDA(REG_STATE);
   return;
}

/******************************************************
 LXI SP
******************************************************/

void doLXISP31(task85 *t){	/* LXI SP */
   doLXISP(&(t->SP),REG_STATE);
   return;
}

/******************************************************
 SPHL
******************************************************/

void doSPHLF9(task85 *t){	/* SPHL */
   doSPHL(REG_STATE);
   return;
}

/******************************************************
 STA
******************************************************/

void doSTA32(task85 *t){	/* STA */
   doSTA(REG_STATE);
   return;
}

/******************************************************
 XCHG
******************************************************/

void doXCHGEB(task85 *t){	/* XCHG */
   doXCHG(REG_STATE);
   return;
}

/******************************************************
 LDAX
******************************************************/

void doLDAX0A(task85 *t){	/* LDAX B:C */
   doLDAX(&(t->B),&(t->C),REG_STATE);
   return;
}

void doLDAX1A(task85 *t){	/* LDAX D:E */
   doLDAX(&(t->D),&(t->E),REG_STATE);
   return;
}

/******************************************************
 LXI
******************************************************/

void doLXI01(task85 *t){	/* LXI B:C */
   doLXI(&(t->B),&(t->C),REG_STATE);
   return;
}

void doLXI11(task85 *t){	/* LXI D:E */
   doLXI(&(t->D),&(t->E),REG_STATE);
   return;
}

void doLXI21(task85 *t){	/* LXI H:L */
   doLXI(&(t->H),&(t->L),REG_STATE);
   return;
}

/******************************************************
 STAX
******************************************************/

void doSTAX02(task85 *t){	/* STAX B:C */
   doSTAX(&(t->B),&(t->C),REG_STATE);
   return;
}

void doSTAX12(task85 *t){	/* STAX D:E */
   doSTAX(&(t->D),&(t->E),REG_STATE);
   return;
}

/******************************************************
 XRA
******************************************************/

void doXRAA8(task85 *t){	/* XRA B */
   doXRA(&(t->B),REG_STATE);
   return;
}

void doXRAA9(task85 *t){	/* XRA C */
   doXRA(&(t->C),REG_STATE);
   return;
}

void doXRAAA(task85 *t){	/* XRA D */
   doXRA(&(t->D),REG_STATE);
   return;
}

void doXRAAB(task85 *t){	/* XRA E */
   doXRA(&(t->E),REG_STATE);
   return;
}

void doXRAAC(task85 *t){	/* XRA H */
   doXRA(&(t->H),REG_STATE);
   return;
}

void doXRAAD(task85 *t){	/* XRA L */
   doXRA(&(t->L),REG_STATE);
   return;
}

void doXRAAE(task85 *t){	/* XRA M */
   doXRA(&(t->M),REG_STATE);
   return;
}

void doXRAAF(task85 *t){	/* XRA A */
   doXRA(&(t->A),REG_STATE);
   return;
}

/******************************************************
 CALL 
******************************************************/

void doCALLCD(task85 *t){	 /* CALL */
   doCALL(REG_STATE);
   return;
}
