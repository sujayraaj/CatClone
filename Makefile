all: cb

cb: utility.o main.o
	gcc utility.o main.o -o cb

utility.o:
	gcc -c utility.c -o utility.o

main.o:
	gcc -c main.c -o main.o

clean:
	rm  *.o cb
