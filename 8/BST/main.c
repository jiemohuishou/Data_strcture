#include "Bst.h"

BSTree InsertBST(BSTree T, BSTNode *S)
{
	BSTNode *f, *p = T;
	while (p) {	//找插入位置
		f = p;	//令f指向p的双亲
		if (S->key < p->key)
			p = p->lchild;
		else
			p = p->rchild;
	}

	if (T == NULL)	//T为空树，新结点作为根结点
		T = S;
	else if (S->key < f->key)
		f->lchild = S;	//作为双亲的左孩子插入
	else
		f->rchild = S;	//作为双亲的右孩子插入

	return T;
}	

BSTree CreateBST(void)
{
	BSTree T = NULL;
	KeyType key;
	BSTNode *S;
	scanf("%d", &key);
	while (key) {	//假设key = 0是输入结束
		S = (BSTNode *)malloc(sizeof(BSTNode));
		S->key = key;	//生成新结点
		S->lchild = S->rchild =NULL;
		T = InsertBST(T, S);	//将新结点*S插入二叉排序树T
		scanf("%d", &key);
	}
	return T;
}

BSTNode *SearchBST(BSTree T, KeyType x)
{
	if (T  == NULL || T->key == x)
		return T;
	if (x < T->key)
		return SearchBST(T->lchild, x);
	else
		return SearchBST(T->rchild, x);
}

int main()
{
	BSTree T = NULL;
	T = CreateBST();
	
}
