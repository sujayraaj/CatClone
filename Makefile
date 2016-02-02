all: cb

cb: main.o
	gcc main.o -o cb

main.o:
	gcc -c main.c -o main.o

clean:
	rm main.o cb
