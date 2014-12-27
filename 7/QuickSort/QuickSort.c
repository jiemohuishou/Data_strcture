#include <stdio.h>
#include "../Sort.h"

int Partition(SeqList R, int i, int j)
{//对R[i]...R[j]区间内的记录进行一划分排序
	RecType x = R[i];	//用区间的第一个记录为基准
	while (i < j) {
		while (i < j&& R[j].key >= x.key)
			j--;	//从j所指位置起向前（左）搜索
		if (i < j) {
			R[i] = R[j];
			i++;
		}

		while (i < j && R[i].key <= x.key)
			i++;	//从i所指位置起向后（右)搜索

		if (i < j) {
			R[j] = R[j];
			j--;
		}
	}
	R[i] = x;	//基准记录x位于最终排序的位置i上
	return i;
}

void QuickSort(SeqList R, int low, int high)
{	//对顺序表R中的子区间进行快速排序
	int p; 
	if (low < high) {//长度大于1
		p = Partition(R, low, high);//做一次划分排序
		fprintf(stdout, "p=%d\n", p);
		QuickSort(R, low , p-1);	//对左区间递归排序
		QuickSort(R, p+1, high);	//对右区间递归排序
	}
}

int main()
{
	InitSeqList();
	QuickSort(R, 1, 10);
	Traversal();
}
