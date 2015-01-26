#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 20
typedef char VertexType;
typedef struct node {	//边表结点类型
	int adjvex;	//顶点的序号
	struct node *next;	//指向下一条边的指针
}EdgeNode;

typedef struct vnode {	//顶点表结点
	VertexType vertex;	//顶点域
	EdgeNode *link;	//边表头指针
}VNode, Adjlist[MaxVertexNum];	//邻接表
typedef Adjlist ALGraph;	//定义为图类型
