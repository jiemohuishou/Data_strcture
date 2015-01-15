#include <stdio.h>

/*
 * 鸡翁一，值钱五；鸡母一，值钱三；鸡雏三，值钱一。百钱买百鸡，问鸡翁、鸡母、鸡雏各几何？
 *
 *
 * 设公鸡数为a，母鸡数为b， 小鸡数为c，可得方程式：
 *
 * a+b+c=100
 * 5a+3b+c/3=100
 * c%3=0
 */

int chicken_question(int g[], int m[], int s[])
{
	int a, b, c, k = 0;
	for (a = 0; a <= 20; a++)
		for (b = 0; b <= 33; b++) {
			c = 100 - a - b;
			if ((5*a+3*b+c/3 == 100) && (c%3 == 0)) {
				g[k] = a;
				m[k] = b;
				s[k] = c;
				k = k+1;
			}
		}
	return k;
}

int main()
{
	int g[10] = {0,};
	int m[10] = {0,};
	int s[10] = {0,};
	int ret, i;
	ret = chicken_question(g, m, s);
	for (i = 0; i < ret; i++) {
		fprintf(stdout, "%d %d %d\n", g[i], m[i], s[i]);
	}
}
