/*************************************************************************
    > File Name      : acm1005.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月21日 星期三 19时54分42秒
************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    int n = 0;
    int s = 0;
    int* matrix = NULL;
    int i = 0;
    int j = 0;
    int* animal = NULL;


    while(EOF != scanf("%d", &n))
    {
        animal = (int*)malloc(2*n*sizeof(int));
        for (i = 0; i < n; i++)
        {
            scanf("%d %d", &animal[2*i], &animal[2*i+1]);
        }
        scanf("%d", &s);
        s = s + 1;
        n = n + 1;
        matrix = (int*)malloc(n*s*sizeof(int));
        for (i = 0; i < n; i++)
        {
            matrix[i*s] = 0;
        }
        for (i = 1; i < s; i++)
        {
            matrix[i] = 0;
        }

        for (i = 1; i < n; i++)
        {
            for (j = 1; j < s; j++)
            {
                matrix[ i*s+j] = matrix[(i-1)*s+j];
                if (animal[2*(i-1)] <= j)
                {
                    if ( matrix[i*s+j] < matrix[(i-1)*s+j-animal[2*(i-1)]]+animal[2*i-1])
                    {
                        matrix[i*s +j] = matrix[(i-1)*s+j-animal[2*(i-1)]]+animal[2*i-1];
                    }
                }
            }
        }

        printf("%d\n", matrix[n*s-1]);
        free(animal);
        free(matrix);
    }
  
    return 0;
}
