/*************************************************************************
    > File Name       : acm1028.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月19日 星期一 15时23分00秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int main(int argc,char *argv[])
{
    int T = 0;
	int n = 0;
	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;

	int cases = 1;

	scanf("%d", &T);
	while(cases <= T)
	{
		scanf("%d %d %d %d %d", &n, &x1, &y1, &x2, &y2);
		if (abs(x1-y1)%2 != abs(x2-y2)%2)
		{
			printf("Case %d:\n-1\n", cases);
		}
		else if (x1 > x2)
		{
			if (y1 > y2)
			{
				if (x1 - x2 > y1 - y2)
				{
					printf("Case %d:\n%d\n",cases, x1-x2);
				}
				else
				{
					printf("Case %d:\n%d\n", cases, y1-y2);
				}
			}
			else
			{
				if (x1 - x2 > y2 - y1) 
				{
					printf("Case %d:\n%d\n",cases, x1-x2);
				}
				else
				{
					printf("Case %d:\n%d\n", cases, y2-y1);
				}
			}
		}
		else
		{
			if (y1 > y2)
			{
				if (x2 - x1 > y1 - y2)
				{
					printf("Case %d:\n%d\n",cases, x2-x1);
				}
				else
				{
					printf("Case %d:\n%d\n", cases, y1-y2);
				} 
			}
			else
			{
				if (x2 - x1 > y2 - y1) 
				{
					printf("Case %d:\n%d\n",cases, x2-x1);
				}
				else
				{
					printf("Case %d:\n%d\n", cases, y2-y1);
				}
			}
		}

		if (cases != T)
		{
			printf("\n");
		}
		cases++;
	}
  
    return 0;
}
