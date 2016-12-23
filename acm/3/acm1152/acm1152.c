/*************************************************************************
    > File Name       : acm1152.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月20日 星期二 21时36分08秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int split(int ary[], int low, int high)
{
	int pivot = ary[low];
	
	while(low < high)
	{
		while(low < high && ary[high] >= pivot)
		{
			high--;
		}
		if (low < high)
		{
			ary[low++] = ary[high];
		}
		while(low < high && ary[low] <= pivot)
		{
			low++;
		}
		if (low < high)
		{
			ary[high--] = ary[low];
		}
	}

	ary[low] = pivot;

	return low;
}

int quicklySort(int ary[], int low, int high)
{
	int pivot = 0;

	if(low < high)
	{
		pivot = split(ary, low, high);
		quicklySort(ary, low, pivot-1);
		quicklySort(ary, pivot+1, high);
	}

	return 0;
}

int main(int argc,char *argv[])
{
    int n = 0;
	int k = 0;
	int *ary = NULL;
	int i = 0;

	while(EOF != scanf("%d %d", &n, &k))
	{
		ary = (int*)malloc(n*sizeof(int));
		for (i = 0; i < n; i++)
		{
			scanf("%d", &ary[i]);
		}
		quicklySort(ary, 0, n-1);
		printf("%d\n", ary[k-1]);
		free(ary);
	}

  
    return 0;
}
