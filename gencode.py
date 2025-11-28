#!/usr/bin/python3
#***************************************************************************
#                         gencode.py  -  generate opmapping code
#    copyright            : (C) 2000 by aaditya sood
#    email                : aaditya@users.sourceforge.net
#***************************************************************************
import sys
list1=["B","C","D","E","H","L","M"]
list2=["B","C","D","E","H","L","M","A"]
list4=["A","B","C","D","E","H","L","M"]
list5=[0x3c,0x04,0x0c,0x14,0x1c,0x24,0x2c,0x34]
list7=["B","D","H"]
list8=["C","E","L"]
list9=[0x03,0x13,0x23,0x33]
list10=[0x0b,0x1b,0x2b,0x3b]
list11=[0xc3,0xc2,0xca,0xda,0xd2,0xf2,0xfa,0xea,0xe2]
list12=[0x3e,0x06,0x0e,0x16,0x1e,0x26,0x2e,0x36]
list13=[0xc5,0xd5,0xe5]
list14=[0xc1,0xd1,0xe1]
comment1="/*****************************************************/"
comment2="/******************************************************"
comment3="******************************************************/"

declcomment="/***************************************************************************\n                     handleop.c  -  set handler code pointers at runtime.\n                             -------------------\n    copyright            : (C) 2000 by aaditya sood\n    email                : aaditya@users.sourceforge.net\n ***************************************************************************/\n\n"

codecomment="/***************************************************************************\n                     opmap.c  -  set handler code pointers at runtime.\n                             -------------------\n    copyright            : (C) 2000 by aaditya sood\n    email                : aaditya@users.sourceforge.net\n ***************************************************************************/\n\n"

if sys.argv[1]=="-d":
  print("%s" % (declcomment))
  val=64
  for x in list1:
    for y in list2:
      if x=="M" and y=="A":
        val=val+1
      if x!="M" or y!="M":
          print("handleop[0x%X] = (void (*)(void*)) (doMOV%X);\t/* MOV %s,%s */" % (val,val,x,y))
          val=val+1


  print("\n%s\n/* ADD */" % (comment1))
  val=0x80
  for x in list2:
    print('handleop[0x%X] = (void (*)(void*)) (doADD%X);\t/* ADD %s */' % (val,val,x))
    val=val+1

  print("\n%s\n/* ADC */" % (comment1))
  val=0x88
  for x in list2:
    print('handleop[0x%X] = (void (*)(void*)) (doADC%X);\t/* ADC %s */' % (val,val,x))
    val=val+1

  print("\n%s\n/* SUB */" % (comment1))
  val=0x90
  for x in list2:
    print('handleop[0x%X] = (void (*)(void*)) (doSUB%X);\t/* SUB %s */' % (val,val,x))
    val=val+1

  print("\n%s\n/* SBB */" % (comment1))
  val=0x98
  for x in list2:
    print('handleop[0x%X] = (void (*)(void*)) (doSBB%X);\t/* SBB %s */' % (val,val,x))
    val=val+1
    
  print('\n%s\n/* CMP */' % (comment1))
  val=0xb8;
  for x in list2:
    print('handleop[0x%X]=(void (*)(void*)) (doCMP%X);\t/* CMP %s */' % (val,val,x))
    val=val+1

  print('\n%s\n/* INR */' % (comment1))
  for x in range(len(list4)):
    print('handleop[0x%X]=(void (*)(void*)) (doINR%02X);\t/* INR %s */' % (list5[x],list5[x],list4[x]))
    
  print('\n%s\n/* DCR */' % (comment1))
  for x in range(len(list4)):
    print('handleop[0x%X]=(void (*)(void*)) (doDCR%02X);\t/* DCR %s */' % (list5[x]+1,list5[x]+1,list4[x]))
    
  print('\n%s\n/* INX */' %(comment1) )
  for x in range(len(list7)):
    print('handleop[0x%X] = (void (*)(void*)) (doINX%02X);\t/* INX %s:%s */' %(list9[x],list9[x],list7[x],list8[x]))
    
  print('\n%s\n/* DCX */' %(comment1))
  for x in range(len(list7)):
    print('handleop[0x%X] = (void (*)(void*)) (doDCX%02X);\t/* DCX %s:%s */' %(list10[x],list10[x],list7[x],list8[x]))

  print('\n%s\n/* INX SP */' %(comment1))
  print('handleop[0x33] = (void (*)(void*)) (doINX33);\t/* INX SP */' )

  print('\n%s\n/* DCX SP */' %(comment1))
  print('handleop[0x3B] = (void (*)(void*)) (doDCX3B);\t/* DCX SP */')
  
  print('\n%s\n/* JMPS*/' % (comment1))
  for x in range(len(list11)):
    print('handleop[0x%X]=(void (*)(void*)) (doJMP);\t/* JMP  */' % (list11[x]))

  print('\n%s\n/* RET  */' %(comment1))
  print('handleop[0xc9]=(void (*)(void*)) (doRETC9);\t/* RET  */' )
  
  
  print('\n%s\n/* SHLD */' %(comment1))
  print('handleop[0x22]=(void (*)(void*)) (doSHLD22);\t/* SHLD  */' )
  
  print('\n%s\n/* SIM  */' %(comment1))
  print('handleop[0x30]=(void (*)(void*)) (doSIM30);\t/* SIM  */' )

  print('\n%s\n/* STC */' %(comment1))
  print('handleop[0x37]=(void (*)(void*)) (doSTC37);\t/* STC  */')
  
  print("\n%s\n/* MVI */" %(comment1))
  for x in range(len(list4)):
    print('handleop[0x%02X]=(void (*)(void*)) (doMVI%02X);\t/* MVI %s */'% (list12[x],list12[x],list4[x]))

  print("\n%s\n/* PUSH */" %(comment1))
  for x in range(len(list7)):
    print('handleop[0x%X]=(void (*)(void*)) (doPUSH%X);\t/* PUSH %s:%s */'% (list13[x],list13[x],list7[x],list8[x]))
    
  print("\n%s\n/* POP */" %(comment1))
  for x in range(len(list7)):
    print('handleop[0x%X]=(void (*)(void*)) (doPOP%X);\t/* POP %s:%s */'% (list14[x],list14[x],list7[x],list8[x]))

  print('\n%s\n/* LDA */' %(comment1))
  print('handleop[0x3A]=(void (*)(void*)) (doLDA3A);\t/* LDA  */')

  print('\n%s\n/* LXI SP */' %(comment1))
  print('handleop[0x31]=(void (*)(void*)) (doLXISP31);\t/* LXI SP */')

  print('\n%s\n/* SPHL */' %(comment1))
  print('handleop[0xF9]=(void (*)(void*)) (doSPHLF9);\t/* SPHL */')

  print('\n%s\n/* STA */' %(comment1))
  print('handleop[0x32]=(void (*)(void*)) (doSTA32);\t/* STA  */')

  print('\n%s\n/* XCHG */' %(comment1))
  print('handleop[0xEB]=(void (*)(void*)) (doXCHGEB);\t/* XCHG */')

  tlist=[0x0a,0x1a]
  print('\n%s\n/* LDAX */' % (comment1))
  for x in range(len(tlist)):
    print('handleop[0x%02X]=(void(*)(void*)) (doLDAX%02X);\t/* LDAX %s:%s */' % (tlist[x],tlist[x],list7[x],list8[x]))

  tlist=[0x01,0x11,0x21]
  print('\n%s\n/* LXI */' % (comment1))
  for x in range(len(tlist)):
    print('handleop[0x%02X]=(void(*)(void*)) (doLXI%02X);\t/* LXI %s:%s */' % (tlist[x],tlist[x],list7[x],list8[x]))

  tlist=[0x02,0x12]
  print('\n%s\n/* STAX */' % (comment1))
  for x in range(len(tlist)):
    print('handleop[0x%02X]=(void(*)(void*)) (doSTAX%02X);\t/* STAX %s:%s */' % (tlist[x],tlist[x],list7[x],list8[x]))

  val=0xA8
  print('\n%s\n/* XRA */' % (comment1))
  for x in range(len(list2)):
    print('handleop[0x%02X]=(void(*)(void*)) (doXRA%02X);\t/* XRA %s */' % (val,val,list2[x]))
    val=val+1

  print('\n%s\n/* CALL */' % (comment1))
  print('handleop[0xCD]=(void(*)(void*)) (doCALLCD);\t/* CALL */')


#===================================================================
#=========================CODE GENERATION===========================
#===================================================================
elif sys.argv[1]=="-c":
  print("%s" % (codecomment))
  print("#include\"top.h\"\n#include\"opfuncdecl.h\"\n\n")


  print("\n%s\n MOV\n%s" % (comment2,comment3))
  val=64
  for x in list1:
    for y in  list2:
      if x=="M" and y=="A":
        val=val+1
      if x!="M" or y!="M":
        print("\nvoid doMOV%X(task85 *t){\t/* MOV %s,%s */\n   t->M=t->memory[((t->H)<<8)+t->L];\n   doMOV(&(t->%s),&(t->%s),REG_STATE);\n   t->memory[((t->H)<<8)+t->L]=t->M;\n   return;\n}" % (val,x,y,x,y))
        val=val+1

  val=0x78
  for y in  list2:
    print("\nvoid doMOV%X(task85 *t){\t/* MOV A,%s */\n   t->M=t->memory[((t->H)<<8)+t->L];\n   doMOV(&(t->A),&(t->%s),REG_STATE);\n   t->memory[((t->H)<<8)+t->L]=t->M;\n   return;\n}" % (val,y,y))
    val=val+1


  print("\n%s\n ADD\n%s" % (comment2,comment3))
  val=0x80
  for x in list2:
    print('\nvoid doADD%X(task85 *t){\t /* ADD %s */\n   t->M=t->memory[((t->H)<<8)+t->L];\n   doADD(&(t->%s),REG_STATE);\n   t->memory[((t->H)<<8)+t->L]=t->M;\n   return;\n}' % (val,x,x))
    val=val+1


  print("\n%s\n ADC\n%s" % (comment2,comment3))
  val=0x88
  for x in list2:
    print('\nvoid doADC%X(task85 *t){\t /* ADC %s */ \n   t->M=t->memory[((t->H)<<8)+t->L];\n   doADC(&(t->%s),REG_STATE);\n   t->memory[((t->H)<<8)+t->L]=t->M;\n   return;\n}' % (val,x,x))
    val=val+1

  print("\n%s\n SUB\n%s" %(comment2,comment3))
  val=0x90
  for x in list2:
    print('\nvoid doSUB%X(task85 *t){\t/* SUB %s */\n   t->M=t->memory[((t->H)<<8)+t->L];\n   doSUB(&(t->%s),REG_STATE);\n   t->memory[((t->H)<<8)+t->L]=t->M;\n   return;\n}' % (val,x,x))
    val=val+1


  print("\n%s\n SBB\n%s" %(comment2,comment3))
  val=0x98
  for x in list2:
    print('\nvoid doSBB%X(task85 *t){\t/* SBB %s */\n   t->M=t->memory[((t->H)<<8)+t->L];\n   doSBB(&(t->%s),REG_STATE);\n   t->memory[((t->H)<<8)+t->L]=t->M;\n   return;\n}' % (val,x,x))
    val=val+1

  val=0xb8;
  print("\n%s\n CMP\n%s" %(comment2,comment3))
  for x in list2:
    print('\nvoid doCMP%X(task85 *t){\t/* CMP %s */\n   t->M=t->memory[((t->H)<<8)+t->L];\n   doCMP(&(t->%s),REG_STATE);\n   t->memory[((t->H)<<8)+t->L]=t->M;\n   return;\n}' % (val,x,x))
    val=val+1


  print("\n%s\n INR \n%s" %(comment2,comment3))
  for x in range(len(list4)):
    print('\nvoid doINR%02X(task85 *t){\t/* INR %s */\n   t->M=t->memory[((t->H)<<8)+t->L];\n   doINR(&(t->%s),REG_STATE);\n   t->memory[((t->H)<<8)+t->L]=t->M;\n   return;\n}' % (list5[x],list4[x],list4[x]))
    
  print('\n%s\n DCR\n%s' %(comment2,comment3))
  for x in range(len(list4)):
    print('\nvoid doDCR%02X(task85 *t){\t/* DCR %s */\n   t->M=t->memory[((t->H)<<8)+t->L];\n   doDCR(&(t->%s),REG_STATE);\n   t->memory[((t->H)<<8)+t->L]=t->M;\n   return;\n}' % (list5[x]+1,list4[x],list4[x]))
    
  print('\n%s\n INX\n%s' %(comment2,comment3))
  for x in range(len(list7)):
    print('\nvoid doINX%02X(task85 *t){\t/* INX %s:%s */\n   doINX(&(t->%s),&(t->%s),REG_STATE);\n   return;\n}' %(list9[x],list7[x],list8[x],list7[x],list8[x]))
    
  print('\n%s\n DCX\n%s' %(comment2,comment3))
  for x in range(len(list7)):
    print('\nvoid doDCX%02X(task85 *t){\t/* DCX %s :%s */\n   doDCX(&(t->%s),&(t->%s),REG_STATE);\n   return;\n}' %(list10[x],list7[x],list8[x],list7[x],list8[x]))
    
  print('\n%s\n DCX SP\n%s' %(comment2,comment3))
  print('\nvoid doDCX3B(task85 *t){\t/* DCX SP */\n   doDCXSP(&(t->SP),REG_STATE);\n   return;\n}' )
  
  print('\n%s\n INX SP\n%s' %(comment2,comment3))
  print('\nvoid doINX33(task85 *t){\t/* INX SP */\n   doINXSP(&(t->SP),REG_STATE);\n   return;\n}' )

  print('\n%s\n JMP\n%s' %(comment2,comment3))
  print('\nvoid doJMP(task85 *t){\t/* JMP */\n   doJMPS(REG_STATE);\n   return;\n}' )
  
  print('\n%s\n RET\n%s' %(comment2,comment3))
  print('\nvoid doRETC9(task85 *t){\t/* RET */\n   doRET(REG_STATE);\n   return;\n}' )
  
  print('\n%s\n SHLD\n%s' %(comment2,comment3))
  print('\nvoid doSHLD22(task85 *t){\t/* SHLD */\n   doSHLD(REG_STATE);\n   return;\n}' )
  
  print('\n%s\n SIM\n%s' %(comment2,comment3))
  print('\nvoid doSIM30(task85 *t){\t/* SIM */\n   doSIM(REG_STATE);\n   return;\n}' )

  print('\n%s\n STC\n%s' %(comment2,comment3))
  print('\nvoid doSTC37(task85 *t){\t/* STC */\n   doSTC(REG_STATE);\n   return;\n}' )
  
  print("\n%s\n MVI \n%s" %(comment2,comment3))
  for x in range(len(list4)):
    print('\nvoid doMVI%02X(task85 *t){\t/* MVI %s */\n   t->M=t->memory[((t->H)<<8)+t->L];\n   doMVI(&(t->%s),REG_STATE);\n   t->memory[((t->H)<<8)+t->L]=t->M;\n   return;\n}' % (list12[x],list4[x],list4[x]))

  print("\n%s\n PUSH\n%s" %(comment2,comment3))
  for x in range(len(list7)):
    print('\nvoid doPUSH%X(task85 *t){\t/* PUSH %s:%s*/\n   doPUSH(&(t->%s),&(t->%s),REG_STATE);\n   return;\n}' %(list13[x],list7[x],list8[x],list7[x],list8[x]))
    
  print("\n%s\n POP\n%s" %(comment2,comment3))
  for x in range(len(list7)):
    print('\nvoid doPOP%X(task85 *t){\t/* POP %s:%s */\n   doPOP(&(t->%s),&(t->%s),REG_STATE);\n   return;\n}' %(list14[x],list7[x],list8[x],list7[x],list8[x]))
  

  print('\n%s\n LDA\n%s' %(comment2,comment3))
  print('\nvoid doLDA3A(task85 *t){\t/* LDA */\n   doLDA(REG_STATE);\n   return;\n}' )

  print('\n%s\n LXI SP\n%s' %(comment2,comment3))
  print('\nvoid doLXISP31(task85 *t){\t/* LXI SP */\n   doLXISP(&(t->SP),REG_STATE);\n   return;\n}' )

  print('\n%s\n SPHL\n%s' %(comment2,comment3))
  print('\nvoid doSPHLF9(task85 *t){\t/* SPHL */\n   doSPHL(REG_STATE);\n   return;\n}' )

  print('\n%s\n STA\n%s' %(comment2,comment3))
  print('\nvoid doSTA32(task85 *t){\t/* STA */\n   doSTA(REG_STATE);\n   return;\n}' )

  print('\n%s\n XCHG\n%s' %(comment2,comment3))
  print('\nvoid doXCHGEB(task85 *t){\t/* XCHG */\n   doXCHG(REG_STATE);\n   return;\n}' )

  tlist=[0x0a,0x1a]
  print('\n%s\n LDAX\n%s' % (comment2,comment3))
  for x in range(len(tlist)):
    print('\nvoid doLDAX%02X(task85 *t){\t/* LDAX %s:%s */\n   doLDAX(&(t->%s),&(t->%s),REG_STATE);\n   return;\n}' % (tlist[x],list7[x],list8[x],list7[x],list8[x]))
    

  tlist=[0x01,0x11,0x21]
  print('\n%s\n LXI\n%s' % (comment2,comment3))
  for x in range(len(tlist)):
    print('\nvoid doLXI%02X(task85 *t){\t/* LXI %s:%s */\n   doLXI(&(t->%s),&(t->%s),REG_STATE);\n   return;\n}' % (tlist[x],list7[x],list8[x],list7[x],list8[x]))

  tlist=[0x02,0x12]
  print('\n%s\n STAX\n%s' % (comment2,comment3))
  for x in range(len(tlist)):
    print('\nvoid doSTAX%02X(task85 *t){\t/* STAX %s:%s */\n   doSTAX(&(t->%s),&(t->%s),REG_STATE);\n   return;\n}' % (tlist[x],list7[x],list8[x],list7[x],list8[x]))
   
    
    
  val=0xA8
  print('\n%s\n XRA\n%s' % (comment2,comment3))
  for x in range(len(list2)):
    print('\nvoid doXRA%02X(task85 *t){\t/* XRA %s */\n   doXRA(&(t->%s),REG_STATE);\n   return;\n}' % (val,list2[x],list2[x]))
    val=val+1

  
  print('\n%s\n CALL \n%s' % (comment2,comment3))
  print('\nvoid doCALLCD(task85 *t){\t /* CALL */\n   doCALL(REG_STATE);\n   return;\n}')

