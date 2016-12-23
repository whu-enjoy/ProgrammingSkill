/*************************************************************************
    > File Name       : acm1034.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月22日 星期四 16时58分00秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int main(int argc,char *argv[])
{
    long long int pieces;
	int n;
	long long int tmp = 0;

	while(EOF != scanf("%d", &n))
	{
		tmp = pow(n,3);
		tmp += 5*n;
		tmp += 6;
		tmp /= 6;
		printf("%ld\n", tmp);
	}
  
    return 0;
}
