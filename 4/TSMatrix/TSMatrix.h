#ifndef _TSMATRIX_H_
#define _TSMATRIX_H_
<<<<<<< HEAD
#include <stdlib.h>
#include <stdio.h>

#define MaxSize 1000	//假设非零元素个数的最大为1000个
typedef int DataType;
typedef struct {
	int i, j;	//非零原色的行号、列号（下标）
	DataType v;	//非零元素值
}TriTupleNode;
typedef struct {
	TriTupleNode data[MaxSize];	//存储三元组的数组
	int m, n, t;	//矩阵的行数、列数和非零元素的个数
}TSMatrix;	//稀疏矩阵类型
=======
#define MaxSize 1000

>>>>>>> 60dd1c04e2c5be6737cf5dbdd5efe8d57fb7ebd3
#endif
