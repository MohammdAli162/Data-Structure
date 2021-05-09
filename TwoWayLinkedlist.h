typedef struct TwoWayLinked{
	int data;
	struct TwoWayLinked *NextNode;
	struct TwoWayLinked *PerNode;
}TwoWayLinked;

typedef enum Error_State{
	NO_MEMORY=-1,
	NO_ENTRY=-1,
	ERROR_OPERATION=0,
	OKAY=1,
	OUT_OF_RANGE,
	EMPTY_LIST
}Error_State;

void PrintNode(TwoWayLinked **Head);
int PushNode(int value,TwoWayLinked **Head);
int InsertNode(int nodeNum,int val,TwoWayLinked **Head);