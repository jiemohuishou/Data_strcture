#include <stdio.h>
#include "../Sort.h"

void SelectSort(SeqList R, int n)
{//对R做直接选择排序
	int i,j,k;
	for (i = 1; i < n; i++) {//做n-1趟排序
		k = i;	//设k为第i趟排序中关键字最小的记录位置
		for (j = i+1; j <= n; j++)//在[i...n]选择关键字最小的记录
			if (R[j].key < R[k].key)
				k = j;	//若有比R[k].key小的记录， 记住该位置
		if (k != i) {	//与第i个记录交换
			R[0] = R[i];
			R[i] = R[k];
			R[k] = R[0];
		}
	}	
}

int main()
{
	InitSeqList();
	SelectSort(R, 10);
	Traversal();
}
