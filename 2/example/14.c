#include "../SeqList/SeqList.h"

void SubList(SeqList *A, SeqList *B)
{
	int i, j, k;
	k = 1;

	for (i = 1; i <= B->length; i++) {
		for (j = k; j <= A->length; j++)
			if (B->data[i] >= A->data[j]) {
				k = j;
				break;
			} else 
				continue;
		if (B->data[i] == A->data[k]) {
			printf("k=%d\n", k);
			DeleteList(A, k);
		}
	}
}

int main()
{
	SeqList *A, *B;
	A = malloc(sizeof(SeqList));
	B = malloc(sizeof(SeqList));
	int bufA[] = {2,3,4,5};
	int bufB[] = {1,2,3,4};
	InitList(A, bufA, 4);
	InitList(B, bufB, 4);

	printf("A: ");
	PrintList(A);
	printf("B: ");
	PrintList(B);
	
	SubList(A, B);
	printf("A: ");
	PrintList(A);

}
