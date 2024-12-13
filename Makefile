CC=gcc

all: main.o dict.o
	$(CC) -o main main.o dict.o

main.o: main.c dict.h
	$(CC) -c main.c

dict.o: dict.c dict.h
	$(CC) -c -O3 dict.c
 
clean:
	rm main main.o dict.o
