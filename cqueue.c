/*	This is an implementation of a circular buffer. It uses a circular queue as 
	the underlying data structure. It only accepts integers for now. You may 
	create only one queue at a time.

	Author: Huzefa Fatakdawala
 */
#include "cqueue.h"

int cq_init(cqueue *q, int size) {
	q->size = size;
	q->queue = malloc(sizeof(int) * size);
	q->head = q->tail = 0;
}

int cq_enqueue(cqueue *q, int obj) {
	int *internal_queue = q->queue;

	if(q->size == 0) {
		internal_queue[0] = obj;
		q->head = q->tail = 0;
	}

}

int cq_dequeue(cqueue *q, int ret) {
	if(cqueue.size == 0){
		return -1;
	}
		
	ret = head;
	head = cq_next(q,head);
	--cqueue.items;
	return 0;
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
