/*************************************************************************
    > File Name       : acm1020.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月22日 星期四 15时17分19秒
 ************************************************************************/

#include <stdio.h>

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
	if (low < high)
	{
		pivot = split(ary, low, high);
		quicklySort(ary, low, pivot-1);
		quicklySort(ary, pivot+1, high);
	}

	return 0;
}

int main(int argc,char *argv[])
{
    int ary[1000] = {0};
	int t = 0;
	int n = 0;

	int i = 0;
	int j = 0;

	int flag = 0;

	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		if (1 == flag)
		{
			printf("\n\n");
		}
		flag = 1;
		scanf("%d", &n);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &ary[j]);
		}

		for (j = n-1; j >0; j--)
		{
			ary[j] = ary[j]-ary[j-1];
		}

		quicklySort(ary, 0, n-1);
		printf("Case %d:\n%d", i, ary[0]);
		for (j = 1; j < n; j++)
		{
			printf(" %d", ary[j]);
		}
	}
  
    return 0;
}
