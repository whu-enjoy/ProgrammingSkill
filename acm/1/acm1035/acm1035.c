/*************************************************************************
    > File Name       : acm1035.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月22日 星期四 17时22分58秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int main(int argc,char *argv[])
{
    int n = 0;
	int ans = 0;

	while(1)
	{
		scanf("%d", &n);
		if (0 == n)
		{
			break;
		}
		ans = ceil((double)n/2);
		printf("%d\n", ans);
	}
  
    return 0;
}
