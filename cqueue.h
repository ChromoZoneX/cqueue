#ifndef QUEUE_H
#define QUEUE_H

// Do not overwrite the values in this structure externally.
typedef struct _cqueue {
	int *queue;
	int head;
	int tail;
	int size;
} cqueue;

// Function prototypes
int cq_init(cqueue *q, int size);
int cq_enqueue(cqueue *q, int obj);
int cq_dequeue(cqueue *q, int ret);
int cq_destroy(cqueue *q, int obj);

#endif