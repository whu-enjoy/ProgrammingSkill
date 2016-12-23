/*************************************************************************
    > File Name       : acm1074.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月16日 星期五 19时59分38秒
 ************************************************************************/

#include <stdio.h>

int split(int ary[], int low, int high)
{
	int pivot = ary[low];

	while(low<high)
	{
		while (low < high && ary[high] >= pivot)
		{
			high--;
		}
		if (low < high)
		{
			ary[low++] = ary[high];
		}
		while (low < high && ary[low] < pivot)
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
     int T = 0;
	 int n = 0;

	 int i = 0;
	 int j = 0;
	 int k = 0;
	 int l = 0;
	 int flag = 0;

	 int ary[10000] = {0};

	 scanf("%d", &T);
	 for (i = 0; i < T; i++)
	 {
		 flag = 0;
		 scanf("%d", &n);

		 for (j = 0; j < n; j++)
		 {
			 scanf("%d", &ary[j]);
		 }
		 quicklySort(ary, 0, n-1);
		 for (j = n-1; j > 1; j--)
		 {
			 for (k = j-1; k > 0; k--)
			 {
				 for (l = 0; l < j-1; l++)
				 {
					 if (ary[j] == ary[k] + ary[l])
					 {
						 printf("%d\n", ary[j]);
						 flag = 1;
						 j = 1;
						 k = 1;
						 break;
					 }
				 }
			 }
		 }
		 if (!flag)
		 {
			 printf("-1\n");
		 }
	 }
  
    return 0;
}
