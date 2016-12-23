/*************************************************************************
    > File Name       : acm1203.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月19日 星期一 14时26分36秒
 ************************************************************************/

#include <stdio.h>

int condidate(int ary[], int m, int n)
{
	int i = m;
	int c = ary[m];
	int count = 1;

	while(count > 0 && i < n)
	{
		i = i+1;
		if (c == ary[i])
		{
			count++;
		}
		else
		{
			count--;
		}
	}

	if (i == n)
	{
		return c;
	}
	else
	{
		return condidate(ary, i+1, n);
	}
}

int main(int argc,char *argv[])
{
	int ary[1000000] = {0};

    int c = 0;

	int n = 0;
	int i = 0;
	int count = 0;

	while(1 == scanf("%d", &n))
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d", &ary[i]);
		}

		c = condidate(ary, 0, n);
		count = 0;
		for (i = 0; i < n; i++)
		{
			if (c == ary[i])
			{
				count++;
			}
		}

		if (count > n/2)
		{
			printf("%d\n", c);
		}
	}
  
    return 0;
}
