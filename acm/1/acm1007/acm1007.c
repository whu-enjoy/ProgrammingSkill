/*************************************************************************
    > File Name       : acm1007.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月19日 星期一 13时49分36秒
 ************************************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
    int matrix[8][10000] = {0};

	int i = 0;
	int j = 0;

	int n = 0;

	int time = 0;
	int T = 0;

	while(1 == scanf("%d", &n))
	{
		T = 0;

		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &matrix[i][j]);
			}
		}

		for (i = 0; i < n; i++)
		{
			time = matrix[0][i];
			for (j = 1; j < 8; j++)
			{
				if (matrix[j][i] < time)
				{
					time = matrix[j][i];
				}
			}
			T += time;
		}
		printf("%d\n", T);
	}
  
    return 0;
}
