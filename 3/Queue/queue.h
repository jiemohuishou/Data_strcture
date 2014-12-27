#ifndef _QUEUE_H_
#define _QUEUE_H_

#define QueueSize 100
typedef char DataType;
typedef struct {
	DataType data[QueueSize];
	int front, rear;
} CirQueue;
#endif
