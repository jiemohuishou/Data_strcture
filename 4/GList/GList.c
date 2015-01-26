#include "GList.h"

Glist CreateGList(Glist GL)
{
	char ch;
	char b;

	scanf("%c", &ch);
	scanf("%c", &b);	//接收'\n'

	if (ch != ' '){
		GL = (GLNode *)malloc(sizeof(GLNode));
		memset (GL, 0, sizeof(GLNode));
		if (ch == '(') {
			GL->tag = 1;//list;
			GL->slink = CreateGList(GL->slink);	//递归调用构造子表
		} else {
			GL->tag = 0;//atom;	//构造原子结点
			GL->data = ch;
		}
	} else
		GL = NULL;

	scanf("%c", &ch);
	scanf("%c", &b);	//接收'\n'
	if (GL != NULL)
		if (ch == ',') {
			GL->link = CreateGList(GL->link);	//递归构造后续广义表
		} else {
			GL->link = NULL;	//表示遇到')'或结束符';'时，无后续表
		}
	return GL;
}

void PrintGList(Glist GL)
{
	if (GL != NULL) {
		if (GL->tag == list) {
			printf("(");
			if (GL->slink == NULL)
				printf(" ");
			else
				PrintGList(GL->slink);
		} else 
			printf("%c", GL->data);

		if (GL->tag == list)
			printf(")");
		if (GL->link != NULL) {
			printf(",");
			PrintGList(GL->link);
		}
	}
}

void FindGlistX(Glist GL, DataType x , int *mark)
{
	Glist p;
	if (GL != NULL) {
		if (GL->tag == 0 && GL->data == x) {
			p = GL;
			*mark = 1;
		} else
			if (GL->tag == 1) 
				FindGlistX(GL->slink, x, mark);
		FindGlistX(GL->link, x, mark);
	}
}	

Glist head(Glist GL)
{
	Glist p;
	if (GL != NULL && GL->tag !=0) {
		p = GL->slink;
		p->link = NULL;
		return p;
	} else
		return NULL;
}

Glist tail(Glist GL)
{
	Glist p;
	if (GL!=NULL && GL->tag !=0) {
		p = GL->slink;
		p = p->link;
		GL->slink = p;
	}
	return p;
}
