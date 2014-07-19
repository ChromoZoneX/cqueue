#include "cqueue.h"


int main(int argc, char *argv[]){
	cqueue * mq ;
	int size;
	size = 10;
	cq_init(mq, size);

	for(i = 0; i < size; i++){
		cq_enqueue(mq, i);
	}
	cq_print(mq);
	for(i = 0; i < 5; i++){
		int ret;
		cq_dequeue(mq, &ret)
		printf ("dequeued item: %d\n",ret);
	}
	cq_print(mq);
	
	return 0;
}