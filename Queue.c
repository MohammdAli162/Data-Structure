#include "Queue.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
int AddQueue(u32 value,Node **Head){
	Node *newNode =(Node *)malloc(sizeof(Node));
	if(newNode == NULL){
		return NO_MEMORY;
	}
	newNode->data = value;
	newNode->next = *Head;
	*Head = newNode;
	return OKAY;
}
 
int PopQueue( u32 &value,Node **Head){
	Node *cur = *Head;
	if(cur == NULL){
		return EMPTY_QUEUE;
	}
	while(cur->next->next != NULL){
		cur = cur->next;
	}
	*value = cur->next->data;
	free(cur->next);
	cur->next = NULL;
	return OKAY;
}
