
/*def_handle: serve as a filler for handlers, do nothing :-)*/
void def_handle(task85 * t)
{
	weprintf("WARNING:0x%02X(%s) at %04X not yet emulated!",
		 t->memory[t->PC], t->opname[t->memory[t->PC]], t->PC);
	(t->PC)++;
	return;
}

instr85 instrtable[] = {
	{def_handle, "nop"}
	,			/* 00 */
	{doLXI01, "lxi B"}
	,			/* 01 */
	{doSTAX02, "stax B"}
	,			/* 02 */
	{doINX03, "inx B"}
	,			/* 03 */
	{doINR04, "inr B"}
	,			/* 04 */
	{doDCR05, "dcr B"}
	,			/* 05 */
	{doMVI06, "mvi B"}
	,			/* 06 */
	{def_handle, "rlc"}
	,			/* 07 */
	{def_handle, "INVALID"}
	,			/* 08 */
	{def_handle, "dad B"}
	,			/* 09 */
	{doLDAX0A, "ldax B"}
	,			/* 0A */
	{doDCX0B, "dcx B"}
	,			/* 0B */
	{doINR0C, "inr C"}
	,			/* 0C */
	{doDCR0D, "dcr C"}
	,			/* 0D */
	{doMVI0E, "mvi C"}
	,			/* 0E */
	{def_handle, "rrc"}
	,			/* 0F */
	{def_handle, "INVALID"}
	,			/* 10 */
	{doLXI11, "lxi D"}
	,			/* 11 */
	{doSTAX12, "stax D"}
	,			/* 12 */
	{doINX13, "inx D"}
	,			/* 13 */
	{doINR14, "inr D"}
	,			/* 14 */
	{doDCR15, "dcr D"}
	,			/* 15 */
	{doMVI16, "mvi D"}
	,			/* 16 */
	{def_handle, "ral"}
	,			/* 17 */
	{def_handle, "INVALID"}
	,			/* 18 */
	{def_handle, "dad D"}
	,			/* 19 */
	{doLDAX1A, "ldax D"}
	,			/* 1A */
	{doDCX1B, "dcx D"}
	,			/* 1B */
	{doINR1C, "inr E"}
	,			/* 1C */
	{doDCR1D, "dcr E"}
	,			/* 1D */
	{doMVI1E, "mvi E"}
	,			/* 1E */
	{def_handle, "rar"}
	,			/* 1F */
	{def_handle, "rim"}
	,			/* 20 */
	{doLXI21, "lxi H"}
	,			/* 21 */
	{doSHLD22, "shld"}
	,			/* 22 */
	{doINX23, "inx H"}
	,			/* 23 */
	{doINR24, "inr H"}
	,			/* 24 */
	{doDCR25, "dcr H"}
	,			/* 25 */
	{doMVI26, "mvi H"}
	,			/* 26 */
	{def_handle, "daa"}
	,			/* 27 */
	{def_handle, "INVALID"}
	,			/* 28 */
	{def_handle, "dad H"}
	,			/* 29 */
	{def_handle, "lhld"}
	,			/* 2A */
	{doDCX2B, "dcx H"}
	,			/* 2B */
	{doINR2C, "inr L"}
	,			/* 2C */
	{doDCR2D, "dcr L"}
	,			/* 2D */
	{doMVI2E, "mvi L"}
	,			/* 2E */
	{def_handle, "cma"}
	,			/* 2F */
	{doSIM30, "sim"}
	,			/* 30 */
	{doLXISP31, "lxi SP"}
	,			/* 31 */
	{doSTA32, "sta"}
	,			/* 32 */
	{doINX33, "inx SP"}
	,			/* 33 */
	{doINR34, "inx M"}
	,			/* 34 */
	{doDCR35, "inr M"}
	,			/* 35 */
	{doMVI36, "dcr M"}
	,			/* 36 */
	{doSTC37, "mvi M"}
	,			/* 37 */
	{def_handle, "stc"}
	,			/* 38 */
	{def_handle, "dad SP"}
	,			/* 39 */
	{doLDA3A, "lda"}
	,			/* 3A */
	{doDCX3B, "dcx SP"}
	,			/* 3B */
	{doINR3C, "inr A"}
	,			/* 3C */
	{doDCR3D, "dcr A"}
	,			/* 3D */
	{doMVI3E, "mvi A"}
	,			/* 3E */
	{doINX03, "cmc"}
	,			/* 3F */
	{doMOV40, "mov B,B"}
	,			/* 40 */
	{doMOV41, "mov B,C"}
	,			/* 41 */
	{doMOV42, "mov B,D"}
	,			/* 42 */
	{doMOV43, "mov B,E"}
	,			/* 43 */
	{doMOV44, "mov B,H"}
	,			/* 44 */
	{doMOV45, "mov B,L"}
	,			/* 45 */
	{doMOV46, "mov B,M"}
	,			/* 46 */
	{doMOV47, "mov B,A"}
	,			/* 47 */
	{doMOV48, "mov C,B"}
	,			/* 48 */
	{doMOV49, "mov C,C"}
	,			/* 49 */
	{doMOV4A, "mov C,D"}
	,			/* 4A */
	{doMOV4B, "mov C,E"}
	,			/* 4B */
	{doMOV4C, "mov C,H"}
	,			/* 4C */
	{doMOV4D, "mov C,L"}
	,			/* 4D */
	{doMOV4E, "mov C,M"}
	,			/* 4E */
	{doMOV4F, "mov C,A"}
	,			/* 4F */
	{doINR04, "mov D,B"}
	,			/* 50 */
	{doMOV50, "mov D,C"}
	,			/* 51 */
	{doMOV51, "mov D,D"}
	,			/* 52 */
	{doMOV52, "mov D,E"}
	,			/* 53 */
	{doMOV53, "mov D,H"}
	,			/* 54 */
	{doMOV54, "mov D,L"}
	,			/* 55 */
	{doMOV55, "mov D,M"}
	,			/* 56 */
	{doMOV56, "mov D,A"}
	,			/* 57 */
	{doMOV57, "mov E,B"}
	,			/* 58 */
	{doMOV58, "mov E,C"}
	,			/* 59 */
	{doMOV59, "mov E,D"}
	,			/* 5A */
	{doMOV5A, "mov E,E"}
	,			/* 5B */
	{doMOV5B, "mov E,H"}
	,			/* 5C */
	{doMOV5C, "mov E,L"}
	,			/* 5D */
	{doMOV5D, "mov E,M"}
	,			/* 5E */
	{doMOV5E, "mov E,A"}
	,			/* 5F */
	{doMOV5F, "mov H,B"}
	,			/* 60 */
	{doDCR05, "mov H,C"}
	,			/* 61 */
	{doMOV60, "mov H,D"}
	,			/* 62 */
	{doMOV61, "mov H,E"}
	,			/* 63 */
	{doMOV62, "mov H,H"}
	,			/* 64 */
	{doMOV63, "mov H,L"}
	,			/* 65 */
	{doMOV64, "mov H,M"}
	,			/* 66 */
	{doMOV65, "mov H,A"}
	,			/* 67 */
	{doMOV66, "mov L,B"}
	,			/* 68 */
	{doMOV67, "mov L,C"}
	,			/* 69 */
	{doMOV68, "mov L,D"}
	,			/* 6A */
	{doMOV69, "mov L,E"}
	,			/* 6B */
	{doMOV6A, "mov L,H"}
	,			/* 6C */
	{doMOV6B, "mov L,L"}
	,			/* 6D */
	{doMOV6C, "mov L,M"}
	,			/* 6E */
	{doMOV6D, "mov L,A"}
	,			/* 6F */
	{doMOV6E, "mov M,B"}
	,			/* 70 */
	{doMOV6F, "mov M,C"}
	,			/* 71 */
	{doMOV70, "mov M,D"}
	,			/* 72 */
	{doMOV71, "mov M,E"}
	,			/* 73 */
	{doMOV72, "mov M,H"}
	,			/* 74 */
	{doMOV73, "mov M,L"}
	,			/* 75 */
	{doMOV74, "hlt"}
	,			/* 76 */
	{doMOV75, "mov M,A"}
	,			/* 77 */
	{doMOV78, "mov A,B"}
	,			/* 78 */
	{doMOV79, "mov A,C"}
	,			/* 79 */
	{doMOV7A, "mov A,D"}
	,			/* 7A */
	{doMOV7B, "mov A,E"}
	,			/* 7B */
	{doMOV7C, "mov A,H"}
	,			/* 7C */
	{doMOV7D, "mov A,L"}
	,			/* 7D */
	{doMOV7E, "mov A,M"}
	,			/* 7E */
	{doMOV7F, "mov A,A"}
	,			/* 7F */
	{doADD80, "add B"}
	,			/* 80 */
	{doADD81, "add C"}
	,			/* 81 */
	{doADD82, "add D"}
	,			/* 82 */
	{doADD83, "add E"}
	,			/* 83 */
	{doADD84, "add H"}
	,			/* 84 */
	{doADD85, "add L"}
	,			/* 85 */
	{doADD86, "add M"}
	,			/* 86 */
	{doADD87, "add A"}
	,			/* 87 */
	{doADC88, "adc B"}
	,			/* 88 */
	{doADC89, "adc C"}
	,			/* 89 */
	{doADC8A, "adc D"}
	,			/* 8A */
	{doADC8B, "adc E"}
	,			/* 8B */
	{doADC8C, "adc H"}
	,			/* 8C */
	{doADC8D, "adc L"}
	,			/* 8D */
	{doADC8E, "adc M"}
	,			/* 8E */
	{doADC8F, "adc A"}
	,			/* 8F */
	{doSUB90, "sub B"}
	,			/* 90 */
	{doSUB91, "sub C"}
	,			/* 91 */
	{doSUB92, "sub D"}
	,			/* 92 */
	{doSUB93, "sub E"}
	,			/* 93 */
	{doSUB94, "sub H"}
	,			/* 94 */
	{doSUB95, "sub L"}
	,			/* 95 */
	{doSUB96, "sub M"}
	,			/* 96 */
	{doSUB97, "sub A"}
	,			/* 97 */
	{doSBB98, "sbb B"}
	,			/* 98 */
	{doSBB99, "sbb C"}
	,			/* 99 */
	{doSBB9A, "sbb D"}
	,			/* 9A */
	{doSBB9B, "sbb E"}
	,			/* 9B */
	{doSBB9C, "sbb H"}
	,			/* 9C */
	{doSBB9D, "sbb L"}
	,			/* 9D */
	{doSBB9E, "sbb M"}
	,			/* 9E */
	{doSBB9F, "sbb A"}
	,			/* 9F */
	{def_handle, "ana B"}
	,			/* A0 */
	{def_handle, "ana C"}
	,			/* A1 */
	{def_handle, "ana D"}
	,			/* A2 */
	{def_handle, "ana E"}
	,			/* A3 */
	{def_handle, "ana H"}
	,			/* A4 */
	{def_handle, "ana L"}
	,			/* A5 */
	{def_handle, "ana M"}
	,			/* A6 */
	{def_handle, "ana A"}
	,			/* A7 */
	{doXRAA8, "xra B"}
	,			/* A8 */
	{doXRAA9, "xra C"}
	,			/* A9 */
	{doXRAAA, "xra D"}
	,			/* AA */
	{doXRAAB, "xra E"}
	,			/* AB */
	{doXRAAC, "xra H"}
	,			/* AC */
	{doXRAAD, "xra L"}
	,			/* AD */
	{doXRAAE, "xra M"}
	,			/* AE */
	{doXRAAF, "xra A"}
	,			/* AF */
	{def_handle, "ora B"}
	,			/* B0 */
	{def_handle, "ora C"}
	,			/* B1 */
	{def_handle, "ora D"}
	,			/* B2 */
	{def_handle, "ora E"}
	,			/* B3 */
	{def_handle, "ora H"}
	,			/* B4 */
	{def_handle, "ora L"}
	,			/* B5 */
	{def_handle, "ora M"}
	,			/* B6 */
	{def_handle, "ora A"}
	,			/* B7 */
	{doCMPB8, "cmp B"}
	,			/* B8 */
	{doCMPB9, "cmp C"}
	,			/* B9 */
	{doCMPBA, "cmp D"}
	,			/* BA */
	{doCMPBB, "cmp E"}
	,			/* BB */
	{doCMPBC, "cmp H"}
	,			/* BC */
	{doCMPBD, "cmp L"}
	,			/* BD */
	{doCMPBE, "cmp M"}
	,			/* BE */
	{doCMPBF, "cmp A"}
	,			/* BF */
	{doDCX0B, "rnz"}
	,			/* C0 */
	{doPOPC1, "pop B"}
	,			/* C1 */
	{doJMP, "jnz"}
	,			/* C2 */
	{doJMP, "jmp"}
	,			/* C3 */
	{def_handle, "cnz"}
	,			/* C4 */
	{doPUSHC5, "push B"}
	,			/* C5 */
	{def_handle, "adi"}
	,			/* C6 */
	{def_handle, "rst 0"}
	,			/* C7 */
	{def_handle, "rz"}
	,			/* C8 */
	{doRETC9, "ret"}
	,			/* C9 */
	{doJMP, "jz"}
	,			/* CA */
	{def_handle, "INVALID"}
	,			/* CB */
	{def_handle, "cz"}
	,			/* CC */
	{doCALLCD, "call"}
	,			/* CD */
	{doINR0C, "aci"}
	,			/* CE */
	{def_handle, "rst 1"}
	,			/* CF */
	{def_handle, "rnc"}
	,			/* D0 */
	{doPOPD1, "pop D"}
	,			/* D1 */
	{doJMP, "jnc"}
	,			/* D2 */
	{def_handle, "out"}
	,			/* D3 */
	{def_handle, "cnc"}
	,			/* D4 */
	{doPUSHD5, "push D"}
	,			/* D5 */
	{doJMP, "sui"}
	,			/* D6 */
	{doDCR0D, "rst 2"}
	,			/* D7 */
	{def_handle, "rc"}
	,			/* D8 */
	{def_handle, "INVALID"}
	,			/* D9 */
	{def_handle, "jc"}
	,			/* DA */
	{def_handle, "in"}
	,			/* DB */
	{def_handle, "cc"}
	,			/* DC */
	{def_handle, "INVALID"}
	,			/* DD */
	{def_handle, "sbi"}
	,			/* DE */
	{def_handle, "rst 3"}
	,			/* DF */
	{def_handle, "rpo"}
	,			/* E0 */
	{doPOPE1, "pop H"}
	,			/* E1 */
	{doJMP, "jpo"}
	,			/* E2 */
	{def_handle, "xthl"}
	,			/* E3 */
	{def_handle, "cpo"}
	,			/* E4 */
	{doPUSHE5, "push H"}
	,			/* E5 */
	{doJMP, "ani"}
	,			/* E6 */
	{def_handle, "rst 4"}
	,			/* E7 */
	{def_handle, "rpe"}
	,			/* E8 */
	{def_handle, "pchl"}
	,			/* E9 */
	{def_handle, "jpe"}
	,			/* EA */
	{doXCHGEB, "xchg"}
	,			/* EB */
	{doJMP, "cpe"}
	,			/* EC */
	{def_handle, "INVALID"}
	,			/* ED */
	{def_handle, "xri"}
	,			/* EE */
	{def_handle, "rst 5"}
	,			/* EF */
	{def_handle, "rp"}
	,			/* F0 */
	{def_handle, "pop PSW"}
	,			/* F1 */
	{def_handle, "jp"}
	,			/* F2 */
	{def_handle, "di"}
	,			/* F3 */
	{def_handle, "cp"}
	,			/* F4 */
	{def_handle, "push PSW"}
	,			/* F5 */
	{def_handle, "ori"}
	,			/* F6 */
	{def_handle, "rst 6"}
	,			/* F7 */
	{def_handle, "rm"}
	,			/* F8 */
	{doSPHLF9, "sphl"}
	,			/* F9 */
	{doJMP, "jm"}
	,			/* FA */
	{def_handle, "??"}
	,			/* FB */
	{def_handle, "??"}
	,			/* FC */
	{def_handle, "??"}
	,			/* FD */
	{def_handle, "??"}
	,			/* FE */
	{def_handle, "??"}
				/* FF */
};
