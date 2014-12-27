#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>


#define StackSize 100
typedef char DataType;
typedef struct {
	DataType data[StackSize];	
	int top;
}SeqStack;

SeqStack S;

#endif
