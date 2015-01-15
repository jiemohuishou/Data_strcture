#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include <stdlib.h>

#define ListSize 100
typedef int DataType;
typedef struct {
	DataType data[ListSize];
	int length;//线性表的当前表长（实际存储元素的个数）
}SeqList;

#endif
