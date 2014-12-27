#include <stdio.h>
#include "../Sort.h"

void DbubbleSort(SeqList R, int n )
{//自底向上、自顶向下交替进行双向扫描冒泡排序
	int i = 1, j;
	RecType t;	//t作为排序交替记录的中间变量
	int NoSwap;	//表示一趟扫面是否有交换， 为假无交换
	NoSwap = 1;	//首先假设有交换，表无序
	while(NoSwap) {	//当有交换时做循环
		NoSwap = 0;//置成无交换
		for (j = n-i+1; j>=i+1;j--)	//自底向上扫描
			if(R[j].key < R[j-1].key) {	//若反序（下面的小于前一个），即交换
				t = R[j];
				R[j] = R[j-1];
				R[j-1]  =t;
				NoSwap = 1;	//说明有交换
			}

		for (j = i+1; j <= n-i; j++)	//自顶向下扫描
			if (R[j].key > R[j+1].key) {	//若反序（前面的大于后一个），即交换
				t = R[j];
				R[j] = R[j+1];
				R[j+1]  =t;
				NoSwap = 1;	//说明有交换
			}
		i = i+1;
	}
}

int main()
{
	InitSeqList();
	DbubbleSort(R, 10);
	Traversal();
}
