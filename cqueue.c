/*	This is an implementation of a circular buffer. It uses a circular queue as 
	the underlying data structure. It only accepts integers for now. You may 
	create only one queue at a time.

 */
#include <stdio.h>
#include <stdlib.h>
#include "cqueue.h"

static int cq_next(cqueue *q, int x) {
	if(x == q->size - 1) return 0;
	else return x + 1;		
}

int cq_init(cqueue *q, const int size) {
	q->size = size;
	q->queue = malloc(sizeof(int) * size);
	if(!q->queue) {
		printf("ERROR: Failed to allocate memory for queue.\n");
		return -1;
	}
	q->head = q->tail = 0;
	q->items = 0;
	return 0;
}

int cq_enqueue(cqueue *q, const int obj) {
	int *internal_queue = q->queue;
	int index;

	if(q->items == q->size) {
		printf("WARN: Queue is full. Item dropped.\n");
		return -1;
	}

	if(q->items == 0) {
		internal_queue[q->head] = obj;
		q->head = q->tail;
		q->items++;
		return 0;
	}

	index = cq_next(q, q->tail);
	internal_queue[index] = obj;
	q->tail = index;
	q->items++;
	return 0;

}

int cq_dequeue(cqueue *q, int *buf) {
	int *internal_queue = q->queue;

	if(q->items == 0) {
		printf("WARN: Queue is empty. Nothing to dequeue.");
		return -1;
	}

	*buf = internal_queue[q->head];
	if(q->items > 1) {
		q->head = cq_next(q,q->head);
	}
	q->items--;
	return 0;
}

int cq_destroy(cqueue *q) {
	free(q->queue);
	q->size = 0;
	q->head = 0;
	q->tail = 0;
	q->items = 0;
	q->size = 0;
	return 0;
}

int cq_print(cqueue *q) {
	int index;
	index = q->head;
	while(index != q->tail) {
		printf("%d->", q->queue[index]);
		index = cq_next(q, index);
	}
	printf("%d\n", q->queue[q->tail]);
	return 0;
}
