/*************************************************************************
    > File Name       : acm1406.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月20日 星期二 19时33分44秒
 ************************************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
    long a = 0;
	long b = 0;
	long tmp = 0;
	double c = 0;
	int flag = 0;

	while(EOF != scanf("%ld %ld", &a, &b))
	{
		if (0 != flag)
		{
			printf("\n");
		}
		flag = 1;
		if (0 == a || 0 == b || a > b)
		{
			printf("0");
		}
		else
		{
			c = (double)b/(2*(double)a);
			tmp = b/(2*a);
			if (c-0.5>tmp)
			{
				printf("%ld", tmp+1);
			}
			else
			{
				printf("%ld", tmp);
			}
		}
	}
  
    return 0;
}
