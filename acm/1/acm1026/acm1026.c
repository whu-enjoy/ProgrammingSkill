/*************************************************************************
    > File Name       : acm1026.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月22日 星期四 15时50分56秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    int matrix[1000][1000] = {0};
	int i = 0;
	int j = 0;
	int k = 0;
	int t = 0;
	int n = 0;
	int max = 0;
	int tmp = 0;
	int flag = 0;

	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		if (1 == flag)
		{
			printf("\n\n");
		}
		flag = 1;
		scanf("%d", &n);
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				scanf("%d", &matrix[j][k]);
			}
		}

		max = 0;
		for (j = 1; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				if (0 == k)
				{
					max = 0;
				}
				else
				{
					max = matrix[j-1][k-1];
				}

				if (matrix[j-1][k] > max)
				{
					max = matrix[j-1][k];
				}

				if(n == k)
				{
					matrix[j][k] += max;
				}
				else
				{
					if (matrix[j-1][k+1] > max)
					{
						matrix[j][k] += matrix[j-1][k+1];
					}
					else
					{
						matrix[j][k] += max;
					}
				}
			}
		}

		max = matrix[n-1][0];
		for (j = 1; j < n; j++)
		{
			if (matrix[n-1][j] > max)
			{
				max = matrix[n-1][j];
			}
		}

		printf("Case %d:\n%d", i, max);
	}
  
    return 0;
}
