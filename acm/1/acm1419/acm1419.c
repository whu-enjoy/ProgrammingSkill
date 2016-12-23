/*************************************************************************
    > File Name       : acm1419.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月15日 星期四 18时36分37秒
 ************************************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
    int i = 0;
	int j = 0;
	int k = 0;
	int pos = 0;
	int T = 0;
	int N = 0;
	int ary[100] = {0};
	int xay = 0;
	int amr = 0;

	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		amr = 0;
		xay = 0;
		scanf("%d", &N);
		for (j = 0, pos = 0; j < N; j++)
		{
			scanf("%d", &ary[pos]);
			for (k = pos-1; k >= 0; k--)
			{
				if (ary[pos] == ary[k])
				{
					if (j%2)
					{
						amr += pos-k+1;
					}
					else
					{
						xay += pos-k+1;
					}
					pos = k-1;
		 			break;
		 		}
			}
			pos++;
		}
		if (xay > amr)
		{
			printf("xay\n");
		}
		else
		{
			printf("amr\n");
		}
	}
  
    return 0;
}
