/*************************************************************************
    > File Name       : acm1293.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月20日 星期二 20时14分05秒
 ************************************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
    int m = 0;
	int n = 0;
	int i = 0;
	int j = 0;
	int tmp = 0;
	int ary[] = {0,1,3,6,10,15,21,28,36,45};

	while(1)
	{
		scanf("%d %d", &m, &n);
		if (0 == m && 0 == n)
		{
			break;
		}

		for (i = n-1; i >= 0; i--)
		{
			tmp = m+ary[i];
			printf("%2d ", tmp);
			for (j = 1; j < (n-i); j++)
			{
				tmp += i+j+1;
				printf("%2d ", tmp);
			}
			printf("\n");
		}
		printf("\n");
	}
  
    return 0;
}
