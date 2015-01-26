#include "MGraph.h"

void CreateMGraph(MGraph *G, int *n, int *e)
{
	char a;
	int i, j, k, w;
	scanf("%d,%d", n, e);	//读入顶点数和边数
	fprintf(stdout, "n=%d, e=%d\n", *n, *e);
	for (i = 0; i < *n; i++) {
		scanf("%c", &a);//'\n'
		scanf("%c", &G->vexs[i]);	//输入顶点信息
	}
	for (i = 0; i < *n; i++)
		for (j = 0; j < *n; j++)
			G->arcs[i][j] = 0;

	fprintf(stdout, "input i,j,w\n");
	for (k = 0; k < *e; k++) {	//读入e条边，建立邻接矩阵
		scanf("%d,%d,%d", &i, &j, &w);	//读入一条边的两端顶点序号i、j及边上的权w
		G->arcs[i][j] = w;
		G->arcs[j][i] = w;	//置矩阵对称元素权值

	}
}
