#include "ALGraph.h"

void CreateGraph(ALGraph GL, int n, int e)
{
	//n为顶点数， e为图的边数
	int i, j, k;
	EdgeNode *p;

	for (i = 0; i < n; i++) {	//建立顶点表
		GL[i].vertex = getchar();	//读入顶点信息
		GL[i].link = NULL;	//边表头指针置空
	}

	for (k = 0; k <e ; k++) {//	采用头插法建立每个顶点的邻接表
		scanf("%d,%d", &i, &j);	//读入边（vi，vj）的顶点序号
		p = (EdgeNode *)malloc(sizeof(EdgeNode));
		p->adjvex = j;	//将邻接点序号j赋给新结点的邻接点域
		p->next = GL[i].link;
		GL[i].link = p;	//将新结点插入到顶点vi的边表头部

		p = (EdgeNode *)malloc(sizeof(EdgeNode));
		p->adjvex = i;	//将邻接点序号i赋给新结点的邻接点域
		p->next = GL[j].link;
		GL[j].link = p;	//将新结点插入到顶点vj的边表头部
	}
}
