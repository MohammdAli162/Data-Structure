#ifndef QUEUE_H_
#define QUEUE_H_
typedef unsigned long int u32;
typedef struct Node{
	u32 data;
	struct Node *next;
}Node;
typedef struct QueueHead{
	 Node *Fnode;
	 Node *next;
}QueueHead;
typedef enum Error_State{
	NO_MEMORY=-1,
	EMPTY_QUEUE=0,
	OKAY=1,
}Error_State;





#endif