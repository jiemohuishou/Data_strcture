#include "stack_list.h"

/*
void InitStack(SeqStack *S)
{
	S->top = -1;
}
*/

int StackEmpty(LinkStack top)
{
	return top == NULL;
}

/*
int StackFull(SeqStack *S)
{
	return S->top == StackSize-1;
}	
*/

LinkStack Push(LinkStack top, DataType x)
{
	StackNode *p;
	p = (StackNode *)malloc(sizeof(StackNode));
	p->data = x;
	p->next = top;
	top = p;
	return top;
}

LinkStack Pop(LinkStack top, DataType *x)
{
	StackNode *p = top;
	if (StackEmpty(top)) {
		printf("stack empty");
		exit(0);
	} else {
		*x = p->data;
		top = p->next;
		free(p);
		return top;
	}
}

DataType GetTop(LinkStack top)
{
	if (StackEmpty(top)) {
		printf("stack empty");
		exit(0);
	} else
		return top->data;
}
