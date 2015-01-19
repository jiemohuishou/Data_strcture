#include "TSMatrix.h"

void FastTran(TSMatrix *a, TSMatrix *b)
{
	int col, p, t, q;
	int *num, *rownext;
	num = (int *)calloc(a->n+1, 4);
	rownext = (int *)calloc(a->m+1, 4);

	b->m = a->n;
	b->n = a->m;
	b->t = a->t;

	if (b->t) {
		for (col=0; col<a->n; ++col)
			num[col] = 0;
		for (t=0; t<a->t; ++t) {
			++num[a->data[t].j];
		}
		int i;
		for (i=0; i<a->n; i++)
			printf("%d ", num[i]);
		printf("\n");
		rownext[0] = 0;

		for (col = 1; col<a->n; ++col) {
			rownext[col] = rownext[col-1]+num[col-1];
			fprintf(stdout, "rownext[%d]=%d\n", col, rownext[col]);
		}
		for (p=0; p<a->t; ++p) {
			col = a->data[p].j;
			q = rownext[col];
			printf("q=%d\n", q);
			b->data[q].i = a->data[p].j;
			b->data[q].j = a->data[p].i;
			b->data[q].v = a->data[p].v;
			++rownext[col];
		}
	}
}
