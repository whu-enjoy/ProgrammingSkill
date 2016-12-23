/*************************************************************************
    > File Name       : acm1017.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月15日 星期四 21时16分14秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int main(int argc,char *argv[])
{
    double a = 0;
	double b = 0;
	double c = 0;

	int x1,x2,x3,y1,y2,y3;
	double tmp1,tmp2,tmp3;
	
	int i = 0;

	int N = 0;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
		a = sqrt(pow(x2-x3, 2)+pow(y2-y3, 2));
		b = sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
		c = sqrt(pow(x1-x3, 2)+pow(y1-y3, 2));

		tmp1 = a*(pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c);
		tmp2 = b*(pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c);
		tmp3 = c*(pow(b,2)+pow(a,2)-pow(c,2))/(2*a*b);
		printf("%.3f\n",tmp1+tmp2+tmp3);
	}
  
    return 0;
}
