#include "TSMatrix.h"

void CreateTriTable(TSMatrix *b, int a[][5], int m, int n)
{
	int i,j ,k=0;
	for (i=0; i < m; i++) 
		for (j=0;j<n;j++)
			if(a[i][j] != 0) {
				b->data[k].i = i;
				b->data[k].j = j;
				b->data[k].v = a[i][j];
				k++;
			}

	b->m = m;
	b->n = n;
	b->t = k;
}
