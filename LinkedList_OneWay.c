#include "LinkedList_OneWay.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


int Key_Search(int *node,int key,Node **Head){
	Node *temp = *Head;
	int i = 1;
	while(temp != NULL){
		if(temp->data == key){
			*node = i;
			return OKAY;
		}
	temp = temp->next;
	i++;
	}
	*node = -1;
	return NO_ENTRY;
}
int Delete_NodeF(Node **Head){
	if(*Head == NULL){
		return EMPTY_LIST;
	}
	Node *Temp = *Head;
	*Head = Temp->next;
	free(Temp);
	return OKAY;
}
int Delete_Node(int node,Node **Head){
	int num;
	GetNodesCount(&num,Head);
	if(node > num){
		return OUT_OF_RANGE;
	}
	Node *temp,*last = *Head;

	while(--node > 1){
		last = last->next;
	}
	temp = last->next;
	last->next = temp->next;
	free(temp);
	return OKAY;
}
int Update_Node(int value,int node,Node **Head){
	int num;
	GetNodesCount(&num,Head);
	if(node > num){
		return OUT_OF_RANGE;
	}
	Node *last = *Head;
	while((node--) > 1){
		last = last->next;
	}
	last->data = value;
	return OKAY;
}
int Print_Node(int *result,int node,Node **Head){
	int num;
	GetNodesCount(&num,Head);
	if(node > num){
		return OUT_OF_RANGE;
	}
	Node *last = *Head;
	while((node--) > 1){
		last = last->next;
	}
	*result = last->data;
	return OKAY;
}
int Print_Linked(Node **Head){
	int i = 0;
	Node *temp = (*Head);
	while(temp != NULL){
		printf("Node %d Value = %d\n",(++i),temp->data);
		temp = temp->next;
	}
	return OKAY;
}
int Push_Node(u32 value,Node **Head){
	Node *newNode =(Node *)malloc(sizeof(Node));
	if(newNode == NULL){
		return NO_MEMORY;
	}
	newNode->data = value;
	newNode->next = *Head;
	*Head = newNode;
	return OKAY;
}
int Insert_Node(int node,int value,Node **Head){
	int num;
	GetNodesCount(&num,Head);
	if(node - num > 1){
		return OUT_OF_RANGE;
	}
	Node *last = *Head;
	Node *newNode =(Node *)malloc(sizeof(Node));
	if(newNode == NULL){
		return NO_MEMORY;
	}
	newNode->data = value;
	while((--node) > 1){
		last = last->next;
	}
	newNode->next = last->next;
	last->next = newNode;
	return OKAY;
}
int GetNodesCount(int *number,Node **Head){
	int i = 0;
	Node *last = *Head;
	while(last != NULL){
		last = last->next;
		i++;
	}
	*number = i;
	return OKAY;
}
int Add_NodeLast(u32 value,Node **Head){
	Node *newNode =(Node *)malloc(sizeof(Node));
	if(newNode == NULL){
		return NO_MEMORY;
	}
	newNode->data = value;
	newNode->next = NULL;
	Node *last;
	if(*Head == NULL){
		*Head = newNode;
	}
	else{
		last = *Head;
		while(last->next != NULL){
			last = last->next;
		}
		last->next = newNode;
	}
	return OKAY;
}