#ifndef _GLIST_H_
#define _GLIST_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum NodeTag
{
	atom, 
	list
} NodeTag;		//atom=0，表示原子；list=1，表示子表
typedef char DataType;
typedef struct GLNode {
	NodeTag tag;
	union {
		DataType data;//用以存放原子结点值
		struct GLNode *slink;//指向子表的指针
	};
	struct GLNode *link;//指向下一个表结点
//}*Glist;	//广义表类型
}GLNode;
typedef GLNode * Glist;
#endif
