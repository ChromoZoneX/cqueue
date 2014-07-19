CC=gcc
CFLAGS=-Wall
LD=gcc
LDFLAGS=

#DEBUG=-g

OBJS=cqueue.o

all: produce

produce: $(OBJS) 
	$(LD) $(LDFLAGS) $(DEBUG) -o $@ $(OBJS) 

main.o: processes.c 
	$(CC) $(CFLAGS) $(DEBUG) -c processes.c 

.PHONY: clean
clean:
	rm -f *.o *.out produce

rebuild:
	make clean
	make
