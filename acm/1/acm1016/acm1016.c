/*************************************************************************
    > File Name       : acm1016.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月22日 星期四 13时29分40秒
 ************************************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
	int ary[1000][2] = {0};
	int checked[1000] = {0};
    int xl = 0;
	int yl = 0;
	int xh = 0;
	int yh = 0;
	int xm = 0;
	int ym = 0;
	int xt = 0;
	int yt = 0;
	int x = 0;
	int y = 0;

	int i = 0;
	int j = 0;

	int n = 0;
	int flag = 0;

	while (EOF != scanf("%d", &n))
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &ary[i][0], &ary[i][1]);
		}

		for (i = 0; i < n; i++)
		{
			checked[i] = 0;
		}

		yl = ary[0][1];
		yh = ary[0][1];
		for (i = 1; i < n; i++)
		{
			if (ary[i][1] < yl)
			{
				yl = ary[i][1];
			}
			else if (ary[i][1] > yh)
			{
				yh = ary[i][1];
			}
		}
		y = yl + yh;

		if (0 == y%2)
		{
			ym = y/2;
			for (i = 0; i <n; i++)
			{
				if (ary[i][1] == ym)
				{
				 	checked[i] = 1;
				} 
			}
		}
		
		for (i = 0; i < n; i++)
		{
			if (1 == checked[i])
			{
				continue;
			}
			for (j = i+1; j < n; j++)
			{
				if (1 == checked[j])
				{
					continue;
				}
				if ((ary[j][0] == ary[i][0]) && (ary[j][1]+ary[i][1] == y))
				{
		 			checked[i] = 1;
					checked[j] = 1;
					break;
				}
			}
		}

		flag = 1;
		for (i = 0; i < n; i++)
		{
			if (0 == checked[i])
			{
				printf("NO\n");
				flag = 0;
				break;
			}
		}
		if (1 == flag)
		{
			printf("YES\n");
		}
	}
  
    return 0;
}
