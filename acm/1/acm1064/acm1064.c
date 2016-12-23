/*************************************************************************
    > File Name       : acm1064.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月19日 星期一 21时02分04秒
 ************************************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
	int ary[1000] = {0};

    int N = 0;
	int i = 0;
	int j = 0;

	int tmp = 0;
	int cases = 0;
  
	while(EOF != scanf("%d", &N))
	{
		cases++;
		for (i = 0; i < N; i++)
		{
			scanf("%d", &tmp);
			ary[tmp] = cases;
		}

		for (i = 0; i < 1000; i++)
		{
			if (ary[i] == cases)
			{
				printf("%d", i);
				i++;
				break;
			}
		}
		for (; i < 1000; i++)
		{
			if (ary[i] == cases)
			{
				printf(" %d", i);
			}
		}
		printf("\n");
	}

    return 0;
}
