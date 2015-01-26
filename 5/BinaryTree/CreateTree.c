#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"
#include "../../3/Stack/stack.h"

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
//				fprintf(stdout, "st[%d]=%c\n", top, St[top]->data);
				fprintf(stdout, "%c %d\n", ch, top);
				k = 1;
				break;
			case ')' :
				top--;
				fprintf(stdout, "%c %d\n", ch, top);
				break;
			case ',' :
				k = 2;
				fprintf(stdout, "%c %d\n", ch, top);
				break;
			default :
				p = (BinTNode *)malloc(sizeof(BinTNode));
				p->data = ch;
				fprintf(stdout, "%c %d\n", ch, top);
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

/*
void Inorder1(BinTree bt)
{
	SeqStack S;
	BinTNode *p;
	InitStack(&S);
	Push(&S, bt);

	while(!StackEmpty(&S)) {
		while (GetTop(&S))
			Push(&S, GetTop(&S)->lchild);	//直到左子树为空
		p = Pop(&S);
		if (!StackEmpty(&S)) {
			printf("%c", GetTop(&S)->data);	//访问根节点
			p = Pop(&S);
			Push(&S, p->rchild);	//右子树进栈
		}
	}
}
*/

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

int BinTreeDepth(BinTree bt)
{
	int depl, depr;
	if (bt == NULL)
		return 0;
	else {
		depl = BinTreeDepth(bt->lchild);
		depr = BinTreeDepth(bt->rchild);
		if (depl>depr)
			return depl+1;
		else
			return depr+1;
	}
}

int main()
{
	BinTNode *tree = NULL;

#if 1
	char *p = "(A(B(D,E),C(,F)))";
	//char *p = "(A(B(,D(E,F)),C))";
	tree = CreateTree(p);
#else
	tree = CreateBinTree(tree);
#endif

	printf("depth=%d\n", BinTreeDepth(tree));
	//Preorder(tree);
	//Postorder(tree);
	//Inorder2(tree);
}
