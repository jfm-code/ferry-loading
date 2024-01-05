#include <stdio.h>
#include <stdlib.h>
#include "ferryload.h"

struct node;
typedef struct node Node;
struct node
{
	int data;
	Node* next;
};

struct queue
{
	Node* head;
	Node* tail;
};
typedef struct queue Queue;

QUEUE queue_init_default()
{
	Queue* pQueue = (Queue*)malloc(sizeof(Queue));
	if (pQueue == NULL)
	{
		LOG_CRITICAL("Malloc failed in pQueue\n");
		return NULL;
	}

	pQueue->head = NULL;
	
	LOG_DEBUG("Initialize successful %p\n", pQueue);
	return pQueue;
}
Status queue_enqueue(QUEUE* hQueue, int value)
{
	/*
	Queue* pQueue = (Queue*)hQueue;
	//create a new node to insert at tail
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("Malloc failed in newNode\n");
		return FAILURE;
	}

	newNode->next = NULL;
	newNode->data = value;

	if (pQueue->head == NULL) //why pQueue->head here isn't equaled to NULL?
		pQueue->head = newNode;
	else
	{
		//create a tail point at head first then go to the last element
		Node* tail = pQueue->head;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
	
	LOG_DEBUG("Enqueue value %d\n", value);
	return SUCCESS;
	*/
	Queue* pQueue = (Queue*)hQueue;
	//create a new node to insert at tail
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("Malloc failed in newNode\n");
		return FAILURE;
	}

	newNode->next = NULL;
	newNode->data = value;

	if (pQueue->head == NULL) //why pQueue->head here isn't equaled to NULL?
		pQueue->head = newNode;
	else
		pQueue->tail->next = newNode;
		
	pQueue->tail = newNode;
	printf("Enqueue %d\n", value);
	return SUCCESS;
}
Status queue_dequeue(QUEUE* hQueue)
{
	Queue* pQueue = (Queue*)hQueue;
	//remove a node at the head
	Node* temp = NULL;
	if (pQueue->head != NULL)
	{
		LOG_DEBUG("Dequeue value %d\n", pQueue->head->data);
		temp = pQueue->head;
		pQueue->head = pQueue->head->next;
		free(temp);
		return SUCCESS;
	}
	else
		return FAILURE;
}
Boolean queue_is_empty(QUEUE* hQueue)
{
	Queue*pQueue = (Queue*)hQueue;
	if (pQueue->head == NULL)
		return TRUE;
	else
		return FALSE;
}
void queue_destroy(QUEUE** hQueue)
{
	Queue* pQueue = (Queue*)*hQueue;
	LOG_DEBUG("Destroying %p\n", pQueue); 
	Node* temp = NULL;
	while (pQueue->head != NULL)
	{
		temp = pQueue->head;
		pQueue->head = pQueue->head->next;
		free(temp);
	}
	free(pQueue);
	*hQueue = NULL;
}
void clear_keyboard_buffer(void)
{
	char c;
	scanf("%c", &c);
	while (c != '\n')
	{
		scanf("%c", &c);
	}
}
