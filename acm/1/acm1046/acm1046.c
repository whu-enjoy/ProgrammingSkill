/*************************************************************************
    > File Name       : acm1046.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月16日 星期五 19时33分14秒
 ************************************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
    int T = 0;
	int N = 0;

	int i = 0;
	int j = 0;
	int k = 0;
	int tmp = 0;
	int count = 0;
	int pos = 0;

	int ary[3000] = {0};

	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		scanf("%d", &N);
		for (j = 0; j < N; j++)
		{
			scanf("%d", &ary[j]);
		}

		count = 0;
		for (j = 1; j < N; j++)
		{
			pos = j;
			for (k = pos-1; k >= 0; k--)
			{
				if (ary[k] > ary[pos])
				{
					tmp = ary[k];
					ary[k] = ary[pos];
					ary[pos] = tmp;
					count++;
					pos = k;
				}
				else
				{
					break;
				}
			}
		}

		printf("%d\n", count);
	}
  
    return 0;
}
