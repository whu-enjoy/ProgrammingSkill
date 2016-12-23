/*************************************************************************
    > File Name       : acm1137.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月15日 星期四 21时49分14秒
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
			ary[high++] = ary[low];
		}
	}

	ary[low] = pivot;
	return low;
}

int quicklySort(int ary[], int low, int high)
{
	int pivotPos = 0;
	if (low < high)
	{
		pivotPos = split(ary, low, high);
		quicklySort(ary, low, pivotPos-1);
		quicklySort(ary, pivotPos+1, high);
	}
}

int main(int argc,char *argv[])
{
    int N = 0;
	int M = 0;

	int i = 0;
	
	int count = 0;

	int *price = NULL;

	while(1)
	{
	if (EOF == scanf("%d %d", &N, &M))
	{
		break;
	}

	price = (int*)malloc(N*sizeof(int));

	for (i = 0; i < N; i++)
	{
		scanf("%d", &price[i]);
	}
	quicklySort(price, 0, N-1);

	for (i = 0; M >= 0; i++)
	{
		M -= price[0];

	}
	printf("%d\n", i-1);
	free(price);
	price = NULL;
	}

    return 0;
}
