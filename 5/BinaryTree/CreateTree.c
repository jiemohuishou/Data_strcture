#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"

// 前序遍历
void Preorder(BinTree bt)
{
	if (bt != NULL) {
		printf("%c", bt->data);
		Preorder(bt->lchild);
		Preorder(bt->rchild);
	}
}

// 中序遍历
void Inorder(BinTree bt)
{
	if (bt != NULL) {
		Inorder(bt->lchild);
		printf("%c", bt->data);
		Inorder(bt->rchild);
	}
}


// 后序遍历
void Postorder(BinTree bt)
{
	if (bt != NULL) {
		Postorder(bt->lchild);
		Postorder(bt->rchild);
		printf("%c", bt->data);
	}
}
BinTNode *CreateTree(char *str)
{
    BinTNode *St[100];
    BinTNode *p = NULL;
	int top, k, j = 0;
	top = -1;
	char ch = str[j];
	BinTNode *b = NULL;
	while (ch != '\0') {
		switch(ch) {
			case '(' :
				top++;
				St[top] = p;
				k = 1;
				break;
			case ')' :
				top--;
				break;
			case ',' :
				k = 2;
				break;
			default :
				p = (BinTNode *)malloc(sizeof(BinTNode));
				p->data = ch;
				p->lchild = p->rchild = NULL;
				if (b == NULL)
					b = p;
				else {
					switch(k) {
						case 1:
							St[top]->lchild = p;
							break;
						case 2:
							St[top]->rchild = p;
							break;
					}
				}
		}
		j++;
		ch = str[j];
	}
	return b;
}

BinTree CreateBinTree(BinTree bt)
{
	BinTNode *Q[100];
	BinTNode *s;
	int front, rear; char ch;
	ch = getchar();
	bt = NULL;
	front = 1;
	rear = 0;

	while (ch != '#') {
		if (ch == '\n')
			goto WWW;
		s = NULL;
		if (ch != '@') {
			s = (BinTNode *)malloc(sizeof(BinTNode));
			s->data = ch;
			s->lchild=s->rchild = NULL;
		}
		rear++;
		Q[rear] = s;
		if(rear == 1)
			bt = s;
		else {
			if(s!=NULL & Q[front] != NULL)
				if (rear%2 == 0)
					Q[front]->lchild = s;
				else
					Q[front]->rchild = s;
			if (rear % 2 != 0)
				front++;
		}
WWW:
		ch = getchar();
	}
	return bt;
}

void Inorder2(BinTree bt)
{
	BinTNode *ST[100];
	int top = 0;
	ST[top] = bt;

	do {
		while (ST[top] != NULL) {
			top = top +1;
			ST[top] = ST[top-1]->lchild;
		}
		top = top - 1;
		if (top >=0) {
			printf("%c", ST[top]->data);
			ST[top] = ST[top]->rchild;
		}

	} while (top != -1);
}

void TransLevel(BinTree bt)
{

}

int main()
{
	BinTNode *tree = NULL;

#if 0
	char *p = "(A(B(D,E),C(,F)))";
	//char *p = "(A(B(,D(E,F)),C))";
	tree = CreateTree(p);
#else
	tree = CreateBinTree(tree);
#endif

	//Preorder(tree);
	Inorder(tree);
	//Postorder(tree);
	//Inorder2(tree);
}
