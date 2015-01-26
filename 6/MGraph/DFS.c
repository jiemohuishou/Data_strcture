#include "MGraph.h"

int visited[20];
void DFS(MGraph *G, int i , int n)
{
	//从顶点vi出发，深度优先搜索遍历图G（邻接矩阵结构）
	int j;
	printf("v%d->", i);	//假设访问顶点vi以输出该顶点的序号代之
	visited[i] = 1;	//标记vi已访问过
	for (j = 0; j < n; j++)
		if (G->arcs[i][j] == 1 && !visited[j])
			DFS(G, j, n);	//若（vi，vj）包含于E(G)，且vj未被访问过，则从开始递归调用
}
