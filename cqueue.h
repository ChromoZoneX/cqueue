/*	This is an implementation of a circular buffer. It uses a circular queue as 
	the underlying data structure. It only accepts integers for now.
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef CQUEUE_H
#define CQUEUE_H

// Do not overwrite the values in this structure externally.
typedef struct _cqueue {
	int *queue;
	int head;
	int tail;
	int items;
	int size;
} cqueue;

typedef struct _cq_node {
	void *obj;
	void *next;
	void *prev;
} cq_node;

/* 	This function must be called before you actually do anything with the queue. It is recommended
 	that you allocate the required memory for the structure but NOT for the queue itself.
	
	Zero on success. Non-zero on failure.

 	@param q 	This is a pointer to the cqueue structure that you need to pass in.
 	@param size	This is the size of the queue that you would like to initialize.
 	@return	Zero on success. Non-zero otherwise.
 */
int cq_init(cqueue *q, int size);

int cq_init_list(cqueue *q, int size);

int cq_init_array(cqueue *q, int size);

/*	This function allows you to add an element to the queue you pass in. If the queue is full, a warning
	is displayed and the queue is left unmodified.
	
	Zero on success. Non-zero on failure.

	@param	q 	This is a pointer to the cqueue structure that you need to pass in.
	@param	obj	This is the object that you would like to add to the queue.
	@return	Zero on success. Non-zero otherwise.
 */
int cq_enqueue(cqueue *q, int obj);

/*	This function allows you to remove an element in te queue. The removed element is put in the provided
	buffer.

	Zero on success. Non-zero on failure.

	@param	q 	This is a pointer to the cqueue structure that you need to pass in.
	@param	buf This is the buffer where the removed value is stored in.
	@return Zero on success. Non-zero otherwise.

 */
int cq_dequeue(cqueue *q, int *buf);

/*	This function must be called on a cqueue that has been initialized using the cq_init() function. If the
	cqueue was never initialized, this will result in undefined behaviour.

	Zero on success. Non-zero on failure.

	@param	q 	This is a pointer to the cqueue structure that you need to pass in.
	@param	ret This is a pointer to a buffer of type int to store the dequeued element.	
	@return	Zero on success. Non-zero otherwise.
 */
int cq_destroy(cqueue *q);

/*	Prints the contents of the queue passed to it from head to tail.
	
	@param	q 	This is a pointer to the cqueue that you need to pass in.
 */
int cq_print(cqueue *q);

#endif
