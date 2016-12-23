/*************************************************************************
    > File Name       : acm1003.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月21日 星期三 18时38分31秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

typedef struct person
{
	int order;
	int old;
	char name[12];
}P;

int main(int argc,char *argv[])
{
    P per[] = {
		{1, 930, "Adam"},
		{2, 912, "Seth"},
		{3, 905, "Enosh"},
		{4, 910, "Kenan"},
		{5, 895, "Mahalalel"},
		{6, 962, "Jared"},
		{7, 365, "Enoch"},
		{8, 969, "Methuselah"},
		{9, 777, "Lamech"},
		{10, 0, "Noah"},
		{11, 0, "Shem"},
		{11, 0, "Ham"},
		{11, 0, "Japheth"}};
	P name[2];
	int i = 0;

	while(EOF != scanf("%s %s", name[0].name, name[1].name))
	{
		name[0].order = 0;
		name[1].order = 0;
		name[0].old = 0;
		name[1].old = 0;
		for (i = 0; i < 13; i++)
		{
			if (0 == strcmp(per[i].name, name[0].name))
			{
				name[0].order = per[i].order;
				name[0].old = per[i].old;
			}
			if (0 == strcmp(per[i].name, name[1].name))
			{
				name[1].order = per[i].order;
				name[1].old = per[i].old;
			}
		}

			if (0 == name[0].order || 0 == name[1].order)
			{
				printf("No enough information\n");
			}
			else if (name[0].order < name[1].order)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}

			if (0 == name[0].old || 0 == name[1].old)
			{
				printf("No enough information\n");
			}
			else if (name[0].old > name[1].old)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
	}
  
    return 0;
}
