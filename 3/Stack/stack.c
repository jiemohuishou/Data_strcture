#include "stack.h"

void InitStack(SeqStack *S)
{
	S->top = -1;
	int i;
	for (i=0; i<100; i++)
		S->data[i] = 0;
}

int StackEmpty(SeqStack *S)
{
	return S->top == -1;
}

int StackFull(SeqStack *S)
{
	return S->top == StackSize-1;
}	

void Push(SeqStack *S, DataType x)
{
	if (StackFull(S))
		printf("stack overflow");
	else {
		S->top = S->top + 1;
		S->data[S->top] = x;
	}
}

DataType Pop(SeqStack *S)
{
	if(StackEmpty(S)){
		printf("stack underflow");
		exit(0);
	} else
		return S->data[S->top--];
}

DataType GetTop(SeqStack *S)
{
	if(StackEmpty(S)) {
		printf("stack empty");
		exit(0);
	} else 
		return S->data[S->top];
}
