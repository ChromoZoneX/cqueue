CC=gcc
CFLAGS=-Wall
LD=gcc
LDFLAGS=

DEBUG=-g

OBJS=main.o cqueue.o

all: main.out

main.out: $(OBJS) 
	$(LD) $(LDFLAGS) $(DEBUG) -o $@ $(OBJS) 

main.o: main.c 
	$(CC) $(CFLAGS) $(DEBUG) -c main.c 

cqueue.o: cqueue.c
	$(CC) $(CFLAGS) $(DEBUG) -c cqueue.c

.PHONY: clean
clean:
	rm -f *.o *.out main

rebuild:
	make clean
	make
