#the Makefile for emulator85
#change these defines to reflect your enviorment
CC= gcc
CFLAGS= -pg -ggdb3 -pipe -Wall -pedantic
OBJS= emul.o eprintf.o doops.o opmap.o 

e85 : $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o sim85

clean: 
	rm -fv *.o GEN OP

tar:	sim85 clean
	cp -r . ../sim85-`./e85 -Vh 2>/dev/null |grep Version|cut -d ' ' -f 2`
	mv ../sim85-`./e85 -Vh 2>/dev/null |grep Version|cut -d ' ' -f 2` .
	rm -rvf sim85-`./e85 -Vh 2>/dev/null |grep Version|cut -d ' ' -f 2`/CVS
	tar -czvf ../sim85-`./e85 -Vh 2>/dev/null |grep Version|cut -d ' ' -f 2`.src.tar.gz sim85-`./e85 -Vh 2>/dev/null |grep Version|cut -d ' ' -f 2`
	rm -rf sim85-`./e85 -Vh 2>/dev/null |grep Version|cut -d ' ' -f 2`	

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $< 
# to run the scripts
GEN: gencode.py 
	./gencode.py -c > opmap.c
	cproto opmap.c -o mapdecl.h
	touch GEN

OP: doops.c Makefile
	cproto -D AS_GEN_DECL doops.c -o opfuncdecl.h
	touch OP

# dependency lists
doops.o: doops.c top.h  OP eprintf.h
emul.o: emul.c eprintf.h top.h OP mapdecl.h instrtable.c GEN Makefile
eprintf.o: eprintf.c Makefile
opmap.o: opmap.c top.h GEN OP Makefile
testframe.o: testframe.c top.h OP Makefile
mapdecl.h: opmap.c GEN Makefile
