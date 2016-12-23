/*************************************************************************
    > File Name       : acm1413.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月20日 星期二 21时57分25秒
 ************************************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
    int a = 0;
	int b = 0;
	int h = 0;
	int t = 0;

	int i = 0;

	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d %d %d", &a, &b, &h);
		printf("%.2lf\n", (double)b*h/a);
	}
  
    return 0;
}
