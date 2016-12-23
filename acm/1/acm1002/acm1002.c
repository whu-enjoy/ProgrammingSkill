/*************************************************************************
    > File Name       : acm1002.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月21日 星期三 17时35分18秒
 ************************************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
    char str[20] = {0};
	int flag = 0;
	int count = 0;

	while(1)
	{
		if (EOF == scanf("%s", str))
		{
			if (flag)
			{
				printf("%d\n", count);
			}
			break;
		}
		if (48 <= str[0] && str[0] <= 57)
		{
			if (flag)
			{
				printf("%d\n", count);
			}
			flag++;
			count = 0;
			printf("%s ", str);
		}
		else if('A' <= str[0] && str[0] <= 'Z' || 'a' <= str[0] && str[0] <= 'z')
		{
			count++;
		}
	}
  
    return 0;
}
