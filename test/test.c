#include <stdio.h>

long int fact(int n)
{
	int temp;
	if (n == 0) {
		return 1;
	} else {
		temp = n * fact(n-1);
		printf("temp=%d\n", temp);
	}
	return temp;
}

int main()
{
	int n = 5;
	printf("%d\n", fact(n));
}
