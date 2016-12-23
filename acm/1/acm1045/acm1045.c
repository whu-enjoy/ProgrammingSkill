/*************************************************************************
    > File Name       : acm1045.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月20日 星期二 18时01分29秒
 ************************************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
    int T = 0;
	int i = 0;
	char ch = 0;
	int flag = 0;

	scanf("%d", &T);
	while('\n' != getchar());

	for (i = 0; i < T; i++)
	{
		flag = 0;
		ch = getchar();
		if ('A' <= ch && ch < 'Z')
		{
			printf("%c", ch);
		}
		else
		{
			printf("%c", ch-32);
		}
		while(1)
		{
			ch = getchar();
			if ('A' <= ch && ch < 'Z' && 1 == flag)
			{
				printf("%c", ch+32);
			}
			else if (32 == ch)
			{
				flag = 0;
				printf("%c", ch);
			}
			else if (10 == ch)
			{
				break;
			}
			else
			{
				printf("%c", ch);
				flag = 1;
			}
		}
		printf("\n");
	}
  
    return 0;
}
