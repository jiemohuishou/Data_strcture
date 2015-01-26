#include "MGraph.h"

void main()
{
	MGraph *G ;
	int n, e;
	G = malloc(sizeof(MGraph));
	CreateMGraph(G, &n, &e);
	DFS(G, 1, n);
	free(G);
	G = NULL;
}
