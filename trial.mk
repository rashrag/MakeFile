read: read.o mainread.o 
	gcc -c mainread.c read.c
	gcc -o read mainread.o read.o
read.o: read.c read.h
	gcc -c read.c
mainread.o: mainread.c read.h
	gcc -c mainread.c
testread.o:  testread.c
	gcc -c testread.c
