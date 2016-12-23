/*************************************************************************
    > File Name       : acm1315.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月20日 星期二 16时27分44秒
 ************************************************************************/

#include <stdio.h>

int calc(int a, int b, int c)
{
    int ans = 1;

	a = a%c;

	while(b>0)
	{
		if (1 == b%2)
		{
			ans = (ans * a)%c;
		}
		b = b/2;
		a = (a*a)%c;
	}

	return ans;
}

int main(int argc,char *argv[])
{
    int a = 0;
	int b = 0;
	int c = 0;

	while(1)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (0 == a && 0 == b && 0 == c)
		{
			break;
		}
		else
		{
			printf("%d\n", calc(a, b, c));
		}
	}
  
    return 0;
}
