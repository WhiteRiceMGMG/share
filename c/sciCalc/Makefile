CC = gcc
CFLAGS = -Wall

all: calc

calc: main.o parser.o evaluator.o
	$(CC) $(CFLAGS) -o calc main.o parser.o evaluator.o

main.o: main.c parser.h evaluator.h
parser.o: parser.c parser.h
evaluator.o: evaluator.c evaluator.h parser.h

clean:
	rm -f *.o calc
