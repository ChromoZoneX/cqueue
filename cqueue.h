#ifndef QUEUE_H
#define QUEUE_H

// Do not overwrite the values in this structure externally.
typedef struct _cqueue {
	int *queue;
	int head;
	int tail;
	int items;
	int size;
} cqueue;

/* 	This function must be called before you actually do anything with the queue. It is recommended
 	that you allocate the required memory for the structure but NOT for the queue itself.
	
	Zero on success. Non-zero on failure.

 	@param q 	This is a pointer to the cqueue structure that you need to pass in.
 	@param size	This is the size of the queue that you would like to initialize.
 	@return	Zero on success. Non-zero otherwise.
 */
int cq_init(cqueue *q, int size);

/*	This function allows you to add an element to the queue you pass in. If the queue is full, a warning
	is displayed and the queue is left unmodified.
	
	Zero on success. Non-zero on failure.

	@param	q 	This is a pointer to the cqueue structure that you need to pass in.
	@param	obj	This is the object that you would like to add to the queue.
	@return	Zero on success. Non-zero otherwise.
 */
int cq_enqueue(cqueue *q, int buf);

/*	This function allows you to remove an element in te queue. The removed element is put in the provided
	buffer.

	Zero on success. Non-zero on failure.

	@param	q 	This is a pointer to the cqueue structure that you need to pass in.
	@param	buf This is the buffer where the removed value is stored in.
	@return Zero on success. Non-zero otherwise.

 */
int cq_dequeue(cqueue *q, int ret);

/*	This function must be called on a cqueue that has been initialized using the cq_init() function. If the
	cqueue was never initialized, this will result in undefined behaviour.

	Zero on success. Non-zero on failure.

	@param	q 	This is a pointer to the cqueue structure that you need to pass in.
	@param	ret This is a reference to a buffer of type int to store the dequeued element.	
	@return	Zero on success. Non-zero otherwise.
 */
int cq_destroy(cqueue *q);

#endif