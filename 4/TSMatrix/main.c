#include "TSMatrix.h"

void print(TSMatrix *b)
{
	int i;
	for (i=0; i<b->t; i++) {
		fprintf(stdout, "%d %d %d\n", 
				b->data[i].i, b->data[i].j,
				b->data[i].v);
	}

}
int main()
{
	int m = 4;
	int n = 5;
	int buf[4][5] = {{0, 3, 0, 5,0},
		{0, 0, -2, 0, 0},
		{1, 0, 0, 0, 6},
		{0, 0, 8, 0, 0}};
	TSMatrix *a = malloc(sizeof(TSMatrix));
	TSMatrix *b = malloc(sizeof(TSMatrix));
	CreateTriTable(a, buf, m, n);
	print(a);
	printf("--------------\n");
//	TransMatrix(a, b);
	FastTran(a,b);
	print(b);

}
