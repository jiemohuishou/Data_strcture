#ifndef _STACK_LIST_H_
#define _STACK_LIST_H_

typedef char DataType;
typedef struct stacknode {
	DataType data;
	struct stacknode *next;
}StackNode;

typedef StackNode *LinkStack;
LinkStack top;

#endif
