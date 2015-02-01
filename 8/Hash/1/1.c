#include <stdio.h>


#define M 997 
typedef int KeyType;
typedef struct {
	KeyType key;
//	DataType data;
} NodeType;

typedef NodeType HashTable[M];

int h(KeyType K, int m)
{
	return K%m;
}

int HashSearch1(HashTable HT, KeyType K, int m)
{
	//在长度为m的散列表HT中查找关键字值为K的元素位置
	int d, temp;
	d = h(K, m);	//计算散列地址
	temp = d;
	while (HT[d].key != -32768) {	//当散列地址中的key域不为空，则循环
		if (HT[d].key == K)
			return d;	//查找成功返回其下标d
		else
			d = (d+1)%m;	//计算下一地址
		if (d == temp)
			return -1;	//查找一周扔无空位置,返回-1表示失败
	}

	return d;	//遇到空单元，查找失败
}

int HashInsert1(HashTable HT, NodeType s, int m)
{
	//在HT表上插入一个新结点s
	int d;
	d = HashSearch1(HT, s.key, m);	//查找插入位置
	if (d == -1)
		return -1;	//表满，不能插入
	else {
		if (HT[d].key == s.key)
			return 0;	//表中已有該结点
		else {	//找到一个开放的地址
			HT[d] = s;	//插入新结点
			return 1;	//插入成功
		}
	}
}
