#include <stdio.h>
#include "../Sort.h"


void InsertSort(SeqList R, int n)
{
	// 对顺序表R做直接插入排序
	int i, j;
	for (i = 2; i <= n; i++)
		if (R[i].key < R[i-1].key) { //若R[i].key >=有序区中所有的key，则R[i]不动
			R[0] = R[i];	//当前记录复制为哨兵						
			for (j = i-1; R[0].key < R[j].key; j--)	//找插入位置
				R[j + 1] = R[j];	//记录后移
			R[j+1] = R[0];	//R[i]插入到正确位置
		}
}

#define NUM 10
void InitSeqList()
{
	int buf[NUM] = {1,4,2,3,6,5,7,8,9,0};
	int i;
	
	for (i = 0; i < NUM; i++) {
		R[i+1].key = buf[i]; //SeqList从1开始	
	}
}

void Traversal()
{
	int i = NUM;
	for (i = 1; i <= NUM; i++)
		fprintf(stdout, "%d ", R[i].key);
	fprintf(stdout, "\n");
}

int main()
{
	InitSeqList();
	fprintf(stdout, "Before Ordering: ");
	Traversal();
	InsertSort(R, 10);
	fprintf(stdout, "After Ordering: ");
	Traversal();

	return 0;
}
