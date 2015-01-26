
#define n 100	//叶子结点数
#define m 2*n-1	//哈夫曼树中结点总数
typedef struct {
	float weight;	//权值
	int lchild, rchild, parent;
} HTNode;
typedef HTNode HuffmanTree[m+1];	//0号单元不用
