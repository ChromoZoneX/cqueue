#include <stdio.h>
#include "cqueue.h"

int main(int argc, char *argv[]){
	cqueue dhairya = {0};
	cqueue *mq;
	mq = &dhairya;
	int size, i, ret;
	size = 10;

	cq_init(mq, size);
	printf("\nTEST 1: PRINT EMPTY QUEUE\n");
	cq_print(mq);
	printf("head: %d\t\ttail: %d\t\titems: %d\n",mq->head, mq->tail, mq->items);

	printf("\nTEST 2: ENQUEUE UNTIL ITEMS == SIZE AND DEQUEUE UNTIL THE QUEUE IS EMPTY\n");
	for(i = 0; i < size; i++){
		cq_enqueue(mq, i);
	}

	cq_print(mq);

	for(i = 0; i < size; i++){
		cq_dequeue(mq, &ret);
	}	
	cq_print(mq);
	printf("head: %d\t\ttail: %d\t\titems: %d\n",mq->head, mq->tail, mq->items);


	printf("\nTEST 3: ENQUEUE 1 ITEM AND DEQUEUE 1 ITEM\n");
	cq_enqueue(mq, 1);
	cq_print(mq);
	cq_dequeue(mq,&ret);
	cq_print(mq);
	printf("head: %d\t\ttail: %d\t\titems: %d\n",mq->head, mq->tail, mq->items);

	printf("\nTEST 4: ENQUEUE AND DEQUEUE SIZE + 1 TIMES\n");
	for(i = 0; i < size + 1; i++){
		cq_enqueue(mq, i);
	}

	cq_print(mq);

	for(i = 0; i < size + 1; i++){
		cq_dequeue(mq, &ret);
	}
	cq_print(mq);
	cq_destroy(mq);
	printf("head: %d\t\ttail: %d\t\titems: %d\n",mq->head, mq->tail, mq->items);


	return 0;
}
