#include "ALGraph.h"

void DFS(ALGraph G, int i)
{
	EdgeNode *p;
	int j;
	visited[i] = 1;
	p = G[i].link;

	while (p != NULL) {
		j = p->adjvex;
		if (!visited[j])
			DFS(G, j);
		p = p->next;
	}	
}
