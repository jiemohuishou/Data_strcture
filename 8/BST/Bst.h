#include <stdlib.h>
#include <stdio.h>
typedef int KeyType;
typedef struct node {
	KeyType key;
	struct node *lchild, *rchild;
} BSTNode;

typedef BSTNode *BSTree;
