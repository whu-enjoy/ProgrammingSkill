/*************************************************************************
    > File Name       : acm1043.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月23日 星期五 12时45分44秒
 ************************************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
    char matrix[6000][1001];
	int n = 0;
	int m = 0;
	int q = 0;
	int max = 0;
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	int k = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &j);
		scanf("%s", matrix[j-1]);
	}

	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &q);
		max = 0;
		for (j = 0; j < q; j++)
		{
			scanf("%d %d", &x, &y);
			x = x-1;
			y = y-1;
			for (k = 0; k < 1000; k++)
			{
				if (matrix[x][k] != matrix[y][k])
				{
					break;
				}
			}
			max += k;
			//if (k > max)
			//{
			//	max = k;
			//}
		}
		printf("%d\n", max);
	}
  
    return 0;
}
