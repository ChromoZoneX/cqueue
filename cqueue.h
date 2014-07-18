#ifndef QUEUE_H
#define QUEUE_H

// Do not overwrite the values in this structure externally.
typedef struct _cqueue {
	int *queue;
	int head;
	int tail;
	int size;
} cqueue;

#endif