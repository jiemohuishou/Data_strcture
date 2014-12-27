#ifndef _SORT_H_
#define _SORT_H_
typedef int KeyType;
#define MAXSIZE 1024
typedef struct {
	KeyType key;
//InfoType otherinfo;
}RecType;
typedef RecType SeqList[MAXSIZE+1];
SeqList R;

#define NUM 10
void InitSeqList()
{
	int buf[NUM] = {1,4,2,3,6,5,7,8,9,0};
	int i;
	
	for (i = 0; i < NUM; i++) {
		R[i+1].key = buf[i]; //SeqList从1开始	
	}
}

void Traversal()
{
	int i = NUM;
	for (i = 1; i <= NUM; i++)
		fprintf(stdout, "%d ", R[i].key);
	fprintf(stdout, "\n");
}
#endif
