/*************************************************************************
    > File Name       : acm1314.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月19日 星期一 18时04分54秒
 ************************************************************************/

#include <stdio.h>

int calc(int n)
{
	if (1 == n)
	{
		return 1;
	}
	else if (1 == n%2)
	{
		return calc(3*n+1)+1;
	}
	else
	{
		return calc(n/2)+1;
	}
}

int main(int argc,char *argv[])
{
    int m = 0;
	int n = 0;

	int i = 0;

	int max = 0;
	int tmp = 0;

	scanf("%d %d", &m, &n);
	while(0 != m && 0 != n)
	{
		max = 0;
		for (i = m; i <= n; i++)
		{
			tmp = calc(i);
			if (tmp > max)
			{
				max = tmp;
			}
		}
		printf("%d\n", max);

		scanf("%d %d", &m, &n);
	}
  
    return 0;
}
