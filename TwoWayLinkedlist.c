#include "TwoWayLinkedlist.h"

static void CreateNode(TwoWayLinked **node){
	*node  = (TwoWayLinked *) malloc(sizeof(TwoWayLinked));
}
void GetNodesCount(TwoWayLinked **Head,int *val){
	int i = 0;
	TwoWayLinked *temp = *Head;
	while(temp != NULL){
		temp = temp->NextNode;
		i++;
	}
	*val = i;
}
int InsertNode(int nodeNum,int val,TwoWayLinked **Head){
	int count;
	GetNodesCount(Head,&count);
	if(count < nodeNum){
		return OUT_OF_RANGE;
	}
	TwoWayLinked *newNode;
	CreateNode(&newNode);
	if(newNode == NULL){
		return NO_MEMORY;
	}
	newNode->data = val;
	newNode->PerNode = NULL;
	newNode->NextNode = NULL;
	TwoWayLinked *temp = *Head;
	while(nodeNum-- > 1){
		temp = temp->NextNode;
	}
	newNode->NextNode = temp->NextNode;
	newNode->PerNode = temp;
	temp->NextNode->PerNode = newNode;
	temp->NextNode = newNode;
	return OKAY;
}
void PrintNode(TwoWayLinked **Head){
		int i = 0;
		TwoWayLinked *temp = (*Head);
		while(temp != NULL){
			printf("Node %d Value = %d\n",(++i),temp->data);
			temp = temp->NextNode;
		}
}
int PushNode(int value,TwoWayLinked **Head){
	TwoWayLinked *newNode;
	CreateNode(&newNode);
	if(newNode == NULL){
		return NO_MEMORY;
	}
	newNode->data = value;
	newNode->PerNode = NULL;
	newNode->NextNode = NULL;
	if(*Head == NULL){
		*Head = newNode;
	}
	else{
		newNode->NextNode = *Head;
		(*Head)->PerNode = newNode;
		*Head = newNode;
	}
}