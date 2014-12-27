#include <stdio.h>
#include "../Sort.h"

void ShellInsert(SeqList R, int dk, int n)
{	//希尔排序中的一趟插入排序，dk为当前增量
	int i, j;
	for (i = dk+1; i <= n; i++)	//将R[dk+1....n]分别插入有序区
		if (R[i].key < R[i-dk].key) {
			R[0] = R[i];	//暂存在R[0]中
			j = i - dk;
			while (j > 0 && R[0].key < R[j].key) {
				R[j+dk] = R[j];	//记录后移，查找插入位置
				j = j-dk;		//查找前一记录
			}
			R[j+dk] = R[0];	//插入R[i]到正确位置
		}
}

void ShellSort(SeqList R, int d[], int t, int n)
{ //按增量序列d[0...t-1]对顺序表R作希尔排序
	int k;
	for (k = 0; k < t; k++)
		ShellInsert(R, d[k], n);
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
	int d[] = {5, 3, 1};
	ShellSort(R, d, 10, 10);
	Traversal();
}
