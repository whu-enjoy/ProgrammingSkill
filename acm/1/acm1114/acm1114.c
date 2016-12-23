/*************************************************************************
    > File Name       : acm1114.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月20日 星期二 15时29分07秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int main(int argc,char *argv[])
{
    double scoreA[12] = {0};
	int score[6] = {0};

	int N = 0;
	int M = 0;
	double tmp = 0;

	int i = 0;

	while(1)
	{
		scanf("%lf %lf %lf %lf %lf %lf", &scoreA[0], &scoreA[1], &scoreA[2], &scoreA[3], &scoreA[4], &scoreA[5]);
		if (-100 == scoreA[0])
		{
			break;
		}
		scanf("%lf %lf %lf %lf %lf %lf", &scoreA[6], &scoreA[7], &scoreA[8], &scoreA[9], &scoreA[10], &scoreA[11]);

		for (i = 0; i < 6; i++)
		{
			tmp = sqrt(pow(scoreA[2*i], 2) + pow(scoreA[2*i+1], 2));
			if (0 <= tmp & tmp <= 3)
			{
				score[i] = 100;
			}
			else if (3 < tmp && tmp <= 6)
			{
				score[i] = 80;
			}
			else if (6 < tmp && tmp <= 9)
			{
				score[i] = 60;
			}
			else if (9 < tmp && tmp <= 12)
			{
				score[i] = 40;
			}
			else if (12 < tmp && tmp <= 15)
			{
				score[i] = 20;
			}
			else
			{
				score[i] = 0;
			}
		}

		N = score[0] + score[1] + score[2];
		M = score[3] + score[4] + score[5];
		
		printf("SCORE: %d to %d, ", N, M);
		if (N == M)
		{
			printf("TIE.\n");
		}
		else
		{
			printf("PLAYER %d WINS.\n", N>M?1:2);
		}
	}
  
    return 0;
}
