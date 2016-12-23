/*************************************************************************
    > File Name       : acm1424.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月15日 星期四 17时41分16秒
 ************************************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
	int i = 0;
    int n = 0;
	int output = 0;

	for (;;)
	{
		scanf("%d", &n);
		if (n > 2)
		{
			n = n - 2;
			if (2 == n%3)
			{
				printf("2 2");
			}
			else
			{
				printf("%d", 2+n%3);
			}

			for (i = 0;i < n/3; i++ )
			{
				printf(" 3");
			}
			printf("\n");
		}
		else if (0 == n)
		{
			break;
		}
		else
		{
			printf("%d\n", n);
		}
	}
  
    return 0;
}
