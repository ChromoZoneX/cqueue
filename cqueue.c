/*	This is an implementation of a circular buffer. It uses a circular queue as 
	the underlying data structure. It only accepts integers for now. You may 
	create only one queue at a time.

	Author: Huzefa Fatakdawala
 */
#include "cqueue.h"

int cq_init(cqueue *q, int size) {
	int *internal_queue = q->queue;
	int i;

}

int cq_isfull(cqueue *q) {
	if (q->full) return 1;
	else return 0;
}

int cq_enqueue(cqueue *q, int obj) {
	
}

int cq_dequeue(cqueue *q, int obj) {
	
}

int cq_destroy(cqueue *q, int obj) {
	
}

int cq_next(cqueue *q, int x) {
	if(x == q->size - 1)
		return 0;
	else
		return x + 1;
}

int cq_prev(cqueue *q, int x) {
	if(x == 0)
		return q->size - 1;
	else
		return x - 1; 
}

// #include <sys/queue.h>

// // Head structure
// CIRCLEQ_HEAD(circleq, int) head;

// typedef struct entry {
// 	CIRCLEQ_ENTRY(int) entries;
// } *integer;

// int cqueue_init(cqueue *q) {
// 	q->head = malloc(sizeof(circleq));
// 	CIRCLEQ_INIT(q.head);
// }

// int cqueue_push(cqueue *q, int x) {
// 	integer num;
// 	num = malloc(sizeof(struct entry));
// 	CIRCLEQ_INSERT_TAIL(q.head, num, entries);
// }

// int cqueue_pop(cqueue *q) {

// }

// int cqueue_destroy(cqueue *q) {

// }

