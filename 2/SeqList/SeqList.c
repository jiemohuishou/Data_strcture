#include <stdio.h>
#include "SeqList.h"

void InsertList(SeqList *L, int i, DataType x)
{	//在顺序表L中第i个位置之前插入一个新元素x
	int j;
	if (i <1 || i > L->length+1) {
		printf("position error");
		return ;
	}
	if (L->length >= ListSize) {
		printf("overflow");
		return ;
	}

	for (j = L->length-1; j>=i-1; j--)
		L->data[j+1] = L->data[j];	//从最后一个元素开始逐一后移
	L->data[i-1] = x;	//插入新元素x
	L->length++;	//实际表长加1
}

DataType DeleteList(SeqList *L, int i)
{//在顺序表L中删除第i个元素，并返回被删除元素
	int j;
	DataType x;
	if (i <1 || i > L->length) {
		printf("position error");
		exit(0);
	}
	x = L->data[i];
	for(j=i;j<=L->length;j++)
		L->data[j-1] = L->data[j];//元素前移
	L->length--;//实际表长减1
	return x;//返回被删除的元素
}

void InitList(SeqList *L, int buf[], int len)
{
	int i;
	L->length = len;
	for (i=1; i <= len; i++) {
		L->data[i] = buf[i-1];
	}
}

void PrintList(SeqList *L)
{
	int i;
	for (i = 1; i <= L->length; i++)
		printf("%d ", L->data[i]);
	printf("\n");
}

SeqList* Converts(SeqList *L)
{	//将线性表逆置
	DataType x;
	int i, k;
	k = L->length/2;
	for (i = 0; i < k; i++) {
		x = L->data[i];
		L->data[i] = L->data[L->length-i-1];
		L->data[L->length-i-1] = x;
	}
	return L;
}































