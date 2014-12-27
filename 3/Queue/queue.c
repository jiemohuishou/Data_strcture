#include <stdio.h>

#include "queue.h"

// 置空队列
void InitQueue(CirQueue *Q)
{
	Q->front = Q->rear = 0;
}

// 判队空
int QueueEmpty(CirQueue *Q)
{
	return Q->rear == Q->front;
}

// 判队满
int QueueFull(CirQueue *Q)
{
	return (Q->rear + 1) % QueueSize == Q->front;
}

// 入队列
void EnQueue(CirQueue *Q, DataType x)
{
	if (QueueFull(Q))
		printf("Queue overflow");
	else {
		Q->data[Q->rear] = x;
		Q->rear = (Q->rear+1) % QueueSize;
	}
}

//取队头元素
DataType GetFront(CirQueue *Q)
{
	if(QueueEmpty(Q)) {
		printf("Queue empty");
		exit(0);
	}
	else
		return Q->data[Q->front];
}

//出队列
DataType DeQueue(CirQueue *Q)
{
	DataType x;
	if (QueueEmpty(Q)) {
		printf("Queue empty");
		exit(0);
	}
	else {
		x = Q->data[Q->front];
		Q->front = (Q->front + 1)% QueueSize;
		return x;
	}
}
