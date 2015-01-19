#include "TSMatrix.h"

void TransMatrix(TSMatrix *a, TSMatrix *b)
{
	int p, q, col;
	b->m = a->n;
	b->n = a->m;
	b->t = a->t;

	if (b->t <=0)
		printf("no element\n");
	else {
		q = 0;
		for (col=0; col<a->n;++col)
			for(p=0;p<a->t;++p)
				if(a->data[p].j == col) {
					b->data[q].i = a->data[p].j;
					b->data[q].j = a->data[p].i;
					b->data[q].v = a->data[p].v;
					++q;
				}
	}
}
