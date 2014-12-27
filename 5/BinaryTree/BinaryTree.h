#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

typedef char DataType;
typedef struct node {
	DataType data;
	struct node *lchild, *rchild;
}BinTNode;

typedef BinTNode *BinTree;
#endif
