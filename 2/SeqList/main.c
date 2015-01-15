#include <stdio.h>
#include "SeqList.h"
#include <stdlib.h>

int main()
{
	int buf[] = {0,1,2,3,4};
	SeqList *L = malloc(sizeof(SeqList));

	InitList(L, buf, sizeof(buf)/sizeof(buf[0]));
	PrintList(L);

	InsertList(L, 6, 100);
	PrintList(L);

	DeleteList(L, 6);
	PrintList(L);
	Converts(L);
	PrintList(L);
	return 0;
}
