/*************************************************************************
    > File Name       : acm1300.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月21日 星期三 17时26分48秒
 ************************************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
    int c = 0;

	int i = 0;
	int n = 0;

	scanf("%d", &c);
	for (i = 0; i < c; i++)
	{
		scanf("%d", &n);
		if (0 == n%7 || 1 == n%7)
		{
			printf("Dzs\n");
		}
		else
		{
			printf("Sproblvem\n");
		}
	}
  
    return 0;
}
