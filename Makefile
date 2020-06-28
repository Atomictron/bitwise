all:	Bitwise

Bitwise:	Bitwise.o
	gcc Bitwise.c -o bitops

clean:
	rm *.o 

