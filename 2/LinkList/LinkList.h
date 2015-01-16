#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdlib.h>
#include <stdio.h>

typedef int DataType;
typedef struct node{
	DataType data;
	struct node *next;
}ListNode;

typedef ListNode *LinkList;
ListNode * p;
LinkList head; //头指针

#endif
