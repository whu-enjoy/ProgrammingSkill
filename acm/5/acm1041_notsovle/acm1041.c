/*************************************************************************
    > File Name       : acm1041.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月21日 星期三 14时34分27秒
 ************************************************************************/

#include <stdio.h>

int success;

int search(char matrix[], int n, int x, int y, int hp)
{

	if (x < 0 || y < 0 || x >= n || y >= n)
	{
		return 0;
	}
	if (matrix[x*30+y] == 'x')
	{
		return 0;
	}
	else if (matrix[x*30+y] == 'k')
	{
		return 0;
	}
	else if (matrix[x*30+y] == 'd')
	{
		hp--;
		if (hp < 0)
		{
			return 0;
		}
	}
	else if (matrix[x*30+y] == 'a')
	{
		success = 1;
		return 0;
	}

	matrix[x*30+y] = 'x';
	search(matrix, n, x+1, y, hp);//down
	if (1 == success)
	{
		return 0;
	}

	search(matrix, n, x, y+1, hp);//right
	if (1 == success)
	{
		return 0;
	}
	search(matrix, n, x-1, y, hp);//up
	if (1 == success)
	{
		return 0;
	}
	search(matrix, n, x, y-1, hp);//left

	return 0;
}

int main(int argc,char *argv[])
{
    char matrix[900] = {0};
	int t = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int n = 0;
	int x = 0;
	int y = 0;
	//FILE* fd = NULL;
	char ch;
	int hp = 1;
	int flag = 0;
	
	//fd = fopen("input","r");
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);
		scanf("%c", &ch);
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				scanf("%c", &matrix[j*30+k]);
				//printf("%c", matrix[j*30+k]);
				if ('p' == matrix[j*30+k])
				{
					x = j;
					y = k;
			 	}
			}
			scanf("%c", &ch);
			//printf("%c", ch);
		}

		hp = 1;
		success = 0;
		search(matrix, n, x, y, hp);
		
		if (1 == flag)
		{
		    printf("\n");
		}
		flag = 1;
		if (1 == success)
		{
			printf("Yes");
		}
		else
		{
			printf("No");
		}
	}
  
    return 0;
}
