/*************************************************************************
    > File Name       : acm1276.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月16日 星期五 21时29分53秒
 ************************************************************************/

#include <stdio.h>

int check[] = {1,2,4,8,16,32,64,128,256,512,1024,1025};
int count[] = {0,1,2,3,4,5,6,7,8,9,10};

int calc(int n, int flag)
{
	int i = 0;
	int j = 0;
	int result1 = 0;
	int result2 = 0;

	for (i = 0; i < 11; i++)
	{
		if (check[i] <= n && n < check[i+1])
		{
			if (n == check[i])
			{
				if (flag > 0)
				{
					return 0;
				}
				else
				{
					return count[i];
				}
			}
			else
			{
				break;
			}
		}
	}

	result2 = calc(check[i+1], flag) + calc(check[i+1] - n, flag+1) + 1;
	result1 = calc(check[i], flag) + calc(n - check[i], flag+1) + 1;
	flag++;

	if (result1 > result2)
	{
		return result2;
	}
	else
	{
		return result1;
	}
}

int main(int argc,char *argv[])
{
	int n = 0;
	int i = 0;

	for (;;)
	{
		scanf("%d", &n);
		if(!n)
		{
			break;
		}
		printf("%d\n", calc(n, 0));
	}

    return 0;
}
