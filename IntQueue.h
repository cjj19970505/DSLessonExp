#ifndef INTQUEUE_H
#define INTQUEUE_H
struct IQNode
{
	int data;
	struct IQNode *next;
};
typedef struct IQNode IQNode;
struct IntQueue
{
	IQNode *head;
	IQNode *tail;
};
typedef struct IntQueue IntQueue;
IntQueue *IQ_Create();
void IQ_InQueue(IntQueue *queue, int data);
void IQ_Print(IntQueue *queue);
int IQ_IsEmpty(IntQueue *queue);
int IQ_OutQueue(IntQueue *queue, int *out);
void IQ_Delete(IntQueue *queue);
#endif
