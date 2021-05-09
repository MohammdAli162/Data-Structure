#ifndef LINKEDLIST_ONEWAY_H_
#define LINKEDLIST_ONEWAY_H_
typedef unsigned long int u32;
typedef struct Node{
	u32 data;
	struct Node *next;
}Node;
typedef enum Error_State{
	NO_MEMORY=-1,
	NO_ENTRY=-1,
	ERROR_OPERATION=0,
	OKAY=1,
	OUT_OF_RANGE,
	EMPTY_LIST
}Error_State;


int Add_NodeLast(u32 value,Node **Head);
int GetNodesCount(int *number,Node **Head);
int Insert_Node(int node,int value,Node **Head);
int Push_Node(u32 value,Node **Head);
int Print_Linked(Node **Head);
int Print_Node(int *result,int node,Node **Head);
int Update_Node(int value,int node,Node **Head);
int Delete_Node(int node,Node **Head);
int Delete_NodeF(Node **Head);

#endif