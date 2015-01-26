#include "GList.h"

int main()
{
	//Glist l;
	GLNode *l;

	l = CreateGList(l);
	PrintGList(l);
	printf("\n");

	Glist h = tail(l);
	printf("head=%c\n", h->data);
}
