#include <stdio.h>


typedef int KeyType;
typedef struct node {
	KeyType key;
	struct node *next;
} HTNode;
typedef HTNode *HT[M];

HTNode *HashSearch2(HT T, KeyType K, int m)
{
	//在长度为m的散列表T中查找关键字值为K的元素位置
	HTNode *p = T[h(K,m)];	//取K所在链表的头指针
	while (p!=NULL && p->key != K)
		p = p->next;	//顺链查找

	return p;
}

int HashInsert2(HT T, HTNode *s, int m)
{
	//采用头插法在T表上插入一个新结点*s
	int d;
	HTNode *p = HashSearch2(T, s->key, m);	//查找表中有无待插结点
	if (p!=NULL)	
		return 0;	//说明表中已有该结点
	else {	//将*s插入在相应链表的表头上
		d = h(s->key, m);
		s->next = T[d];
		T[d] = s;
		return 1;	//说明插入成功
	}
}
