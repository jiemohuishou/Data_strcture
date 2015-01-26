#ifndef _MGRAPH_H_
#define _MGRAPH_H_

#include <stdlib.h>
#include <stdio.h>

#define MaxVertexNum 50
typedef char VertexType;
typedef int Adjmatrix;
typedef struct  {
	VertexType vexs[MaxVertexNum];
	Adjmatrix arcs[MaxVertexNum][MaxVertexNum];
}MGraph;
#endif
