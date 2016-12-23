/*************************************************************************
    > File Name       : acm1029.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月20日 星期二 14时53分46秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
    char ch = 0;
	int i = 0;
	char check[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	int tmp = 0;

	while(1)
	{
		ch = getchar();
		if ('$' == ch)
		{
			printf("\n");
			break;
		}
		else if (10 == ch)
		{
			printf("\n");
			i = 0;
		}
		else
		{
			i++;
			if (ch-65-i%26 < 0)
			{
				printf("%c", check[26+ch-65-i%26]);
			}
			else
			{
				printf("%c", check[ch-65-i%26]);
			}
		}
	}
  
    return 0;
}
