#include "IntQueue.h"
#include <stdio.h>
#include <stdlib.h>

IQNode *IQ_CreateNode(int data);
void IQ_DeleteNode(IQNode *node);
IntQueue *IQ_Create()
{
	IntQueue *iq = (IntQueue*)malloc(sizeof(IntQueue));
	iq->head = IQ_CreateNode(0);
	iq->tail = iq->head;
	return iq;
}
IQNode *IQ_CreateNode(int data)
{
	IQNode *node = (IQNode*)malloc(sizeof(IQNode));
	node->next = NULL;
	node->data = data;
	return node;
}
void IQ_InQueue(IntQueue *queue, int data)
{
	IQNode *oldTail = queue->tail;
	IQNode *newTail = IQ_CreateNode(data);
	oldTail->next = newTail;
	queue->tail = newTail;
}

//·µ»Ø×´Ì¬ 
int IQ_OutQueue(IntQueue *queue, int *out)
{
	if(IQ_IsEmpty(queue))
	{
		return 0;
	}
	IQNode *oldFirst = queue->head->next;
	if(queue->tail == oldFirst)
	{
		queue->tail = queue->head;
		queue->head->next = NULL;
		queue->tail->next = NULL;
		
	}
	else
	{
		queue->head->next = oldFirst->next;
	}
	*out = oldFirst->data;
	IQ_DeleteNode(oldFirst);
	return 1;
	
		
}
void IQ_DeleteNode(IQNode *node)
{
	free(node);
}
int IQ_IsEmpty(IntQueue *queue)
{
	if(queue->head == queue->tail)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void IQ_Print(IntQueue *queue)
{
	IQNode *curr = queue->head;
	printf("BEGIN::");
	while((curr=curr->next)!=NULL)
	{
		printf("%d-", curr->data);
	}
	printf("END\n");
}
void IQ_Delete(IntQueue *queue)
{
	IQNode *curr = queue->head;
	do
	{
		IQNode *delNode = curr;
		curr = curr->next;
		IQ_DeleteNode(delNode);
	}
	while(curr != NULL);
}


