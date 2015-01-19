#include "LinkList.h"

LinkList CreateListF()
{//头插法
	LinkList head;
	ListNode *p;
	char ch;
	head = NULL;	//制空单链表
	ch = getchar();

	while(ch != '\n') {
		p = (ListNode *)malloc(sizeof(ListNode));
		p->data = ch;
		p->next = head;
		head = p;
		ch = getchar();
	}
	return head;
}

LinkList CreateListR()
{//尾插法建表
	LinkList head, rear;
	ListNode *p;
	char ch;
	head = NULL;
	rear = NULL;
	ch  = getchar();
	while (ch != ' ') {
		p = (ListNode *)malloc(sizeof(ListNode));
		p->data = ch;
		if(head == NULL)
			head = p;//新结点*p插入空表
		else
			rear->next = p;//新结点*p插入到非空表的表为结点*rear之后
		rear = p;//表尾指针指向新的表尾结点
		ch = getchar();
	}
	if (rear != NULL)
		rear->next = NULL;//终端结点指针域制空
	return head;
}

LinkList CreateListR1()
{//尾插法建立带头结点的单链表算法
	LinkList head =	(ListNode *)malloc(sizeof(ListNode));
	ListNode *p, *r;
	DataType ch;
	r = head;

	while ((ch = getchar()) != '\n' ) {
		p = (ListNode *)malloc(sizeof(ListNode));
		p->data = ch;
		r->next = p;//新结点连接到尾结点之后
		r = p;//尾结点指向新节点
		
	}
	r->next = NULL;//终端结点指针域置空
	return head;
}

ListNode *GetNodei(LinkList head, int i)
{//head 为带头结点的单链表的头指针，i为要查找的结点序号
	ListNode *p;
	int j;

	p = head->next;//使p指向第一个结点，j置1
	j = 1;

	while (p != NULL && j < i) {//顺指针向后查找，直到p指向第i个结点或p为空为止
		p = p->next;
		++j;
	}

	if (j == i)
		return p;
	else
		return NULL;
}


ListNode *LocateNodek(LinkList head, DataType k)
{//head为带头结点的单链表的头指针，k为要查找的结点值
	ListNode *p = head->next; //p指向开始结点
	while (p && p->data != k)
		p = p->next;
	return p;
}

void InsertList(LinkList head, int i, DataType x)
{//在以head为头指针的带头结点的单链表中第i个结点的位置上
	ListNode *p, *s;
	int j;
	p = head;
	j = 0;

	while (p != NULL && j < i-1) {//使p指向第i-1个结点
		p = p->next;
		++j;

	}
	if (p == NULL) { //插入位置错误
		printf("ERROR\n");
		return ;
	} else {
		s = (ListNode *)malloc(sizeof(ListNode));
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
}

DataType DeleteList(LinkList head, int i)
{//在以head为头指针的带头结点的单链表中删除第i个结点
	ListNode *p, *s;

	DataType x;
	int j = 0;
	p = head;

	while (p!=NULL && j<i-1) { //使p指向第i-1个结点
		p = p->next;
		++j;
	}

	if (p == NULL) {//删除位置错误
		printf("位置错误\n");
		exit(0);
	}else {
		s = p->next;//s指向第i个结点
		p->next = s->next;//使p->next指向第i+1个结点
		x = s->data;
		free(s);
		return x;
	}
}

void PrintList(LinkList head)
{
	ListNode *p = head;
	while (p != NULL) {
		printf("%c ", p->data);
		p = p->next;
	}
}
