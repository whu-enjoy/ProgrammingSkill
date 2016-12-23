/*************************************************************************
    > File Name       : acm1157.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月15日 星期四 19时24分17秒
 ************************************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
    int i = 0;
	int j = 0;
	int N = 0;
	int ary[10000] = {0};
	int count = 0;
	int flag = 0;
	int cases = 0;

	scanf("%d", &N);
	for (cases = 1; -1 != N; cases++)
	{
		count = 0;
		for (i=0; i < N; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (flag = 0; 0 == flag;)
		{
			flag = 1;
			for (i = 0; i < N-1; i++)
			{
				if (1 == ary[i] && -1 == ary[i+1])
				{
					ary[i] = -1;
					ary[i+1] = 1;
					count++;
					flag = 0;
					i++;
				}
			}
		}
		
		printf("Case %d: %d\n",cases, count);
		scanf("%d", &N);
	}
  
    return 0;
}
