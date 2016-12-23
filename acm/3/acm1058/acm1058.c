/*************************************************************************
    > File Name       : acm1058.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月22日 星期四 19时33分40秒
 ************************************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
    int n = 0;
	long int count = 0;
	int i = 0;

	while(1)
	{
		scanf("%d", &n);
		if (0 == n)
		{
			break;
		}
		count = 0;
		for (i = 0; i <= n/3; i++)
		{
			count += (n-3*i)/2+1; 
		}
		printf("%ld\n", count);
	}
  
    return 0;
}
