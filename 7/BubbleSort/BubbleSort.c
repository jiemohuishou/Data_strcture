#include <stdio.h>
#include "../Sort.h"

void BubbleSort(SeqList R, int n)
{	//采用自底向上扫面数组R[1..n]做冒泡排序
	int i, j, flag;
	for (i = 1; i < n; i++) {//最多做n-1趟排序

		flag = 0;	//flag表示每一趟是否有交换，先置0
		for (j = n; j>=1; j--)			//进行第i趟排序	
			if (R[j].key < R[j-1].key) {
				R[0] = R[j-1];	//R[0]作为交换时的暂存单元
				R[j-1] = R[j];
				R[j] = R[0];
				flag =1 ;	//有交换， flag置1
			}	
		if (flag == 0)
			return ;
	}
}

int main()
{
	InitSeqList();
	BubbleSort(R, 10);
	Traversal();
}
