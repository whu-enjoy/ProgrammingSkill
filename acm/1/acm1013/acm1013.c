/*************************************************************************
    > File Name       : acm1013.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月21日 星期三 22时02分43秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
    char str[101] = {0};
	int i = 0;
	int j = 0;
	int k = 0;
	int pos = 0;
	char tmp[100][101] = {0};
	int length = 0;
	int flag[101] = {0};
	char check = 'z';

	while(EOF != scanf("%s", str))
	{
		length = strlen(str);
		for (i = 0; i < length; i++)
		{
			for (j = 0; j < length; j++)
			{
				tmp[i][j] = str[(i+j)%length];
			}
			tmp[i][j] = 0;
		}

		for (i = 0; i < length; i++)
		{
			flag[i] = i;
		}

		for (i = 0; i < length; i++)
		{
			check = tmp[flag[0]][i];
			pos = 0;
			for (j = 1; j < length; j++)
			{
				if (0 == flag[j])
				{
					break;
				}
				k = flag[j];
				if (tmp[k][i] < check)
				{ 
				 	pos = 0;
					flag[pos] = k;
					check = tmp[k][i];
				}
				else if (tmp[k][i] == check)
				{
					flag[++pos] = k;
				}
			}
			flag[++pos] = 0;
		}

		printf("%s\n", tmp[flag[0]]);
	}
  
    return 0;
}
