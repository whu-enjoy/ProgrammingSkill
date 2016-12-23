/*************************************************************************
    > File Name       : acm1039.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月22日 星期四 18时19分13秒
 ************************************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
    int ary[200000] = {0};
	int skip[200000] = {0};
	int n = 0;
	int pos = 0;
	int tmp = 0;
	int max = 0;

	int i = 0;
	int flag = 0;

	while(1)
	{
		max = 0;
		scanf("%d", &n);
		if (0 == n)
		{
			break;
		}
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &tmp);
			pos = tmp - 1 + skip[tmp-1];
			for (;pos < 200000;)
			{
				skip[pos]++;
				if (0 == ary[pos])
				{
					ary[pos] = i;
					break;
				}
				else
				{
					pos += skip[pos]-1;
				}
			}
			if (pos > max)
			{
				max = pos;
			}
		}

		if (1 == flag)
		{
			printf("\n");
		}
		flag = 1;
		printf("%d\n%d", max+1, ary[0]);
		ary[0] = 0;
		skip[0] = 0;
		for (i = 1; i <= max; i++)
		{
			printf(" %d", ary[i]);
			ary[i] = 0;
			skip[i] = 0;
		}
	}
  
    return 0;
}
