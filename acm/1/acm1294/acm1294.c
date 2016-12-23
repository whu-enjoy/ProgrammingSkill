/*************************************************************************
    > File Name       : acm1294.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月16日 星期五 17时24分45秒
 ************************************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
    int t = 0;
	int n = 0;

	int i = 0;
	int j = 0;

	int big = 0;
	int small = 0;
	int big_small = 0;

	int tmp_big = 0;
	int tmp_small = 0;

	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);
		big = 0;
		small = 1;
		big_small = 0;
		for (j = 0; j < 2*n; j++)
		{
			tmp_big = big;
			tmp_small = small;
			big += big_small;
			small = 2 * (tmp_big+big_small);
			big_small = tmp_small;
		}
		printf("%d\n", small+big+big_small);
	}
  
    return 0;
}
