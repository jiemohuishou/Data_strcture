#include "stack.h"

int Expr()
{
	SeqStack S;
	DataType ch, x;
	InitStack(&S);
	ch = getchar();
	
	while(ch != '#') {
		if (ch == '(')
			Push(&S, ch);
		else
			if (ch == ')')
				if (StackEmpty(&S))
					return 0;
				else
					x = Pop(&S);
		ch = getchar();
	}

	if (StackEmpty(&S))
		return 1;
	else
		return 0;
}

int main()
{
	int ret = Expr();	
	if (ret == 0)
		printf("not \n");
	else
		printf("yes \n");
	return 0;
}
