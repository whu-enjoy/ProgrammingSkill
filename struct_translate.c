/*******************************************************************************
  程序员      : enjoy
  最后修改时间: 2016年3月29日 13:19:37
  函数说明    : 本函数用于测试结构体在函数传值的时候的引用方式以及结构体指针在
                函数传值时的引用方式,本代码更详细的解释,请看本人博客
http://blog.csdn.net/enjoy5512/article/details/51006114
*******************************************************************************/

#include<stdio.h>
#include<string.h>

//测试的结构体,包含整型,数组,指针
typedef struct
{
	int x;
	int y;
	char name[5];
	struct DNode *next;
}DNode;

/*
  函数说明:
      测试的是结构体指针在函数传值时的用法,因为会将传入参数Node修改之后的结果传
	  递回去,所以采用了二级指针,**Node是实际的结构体所在的内存,*Node是一个四字
	  节的指针,指向实际内存,Node是一个二级指针,指向*Node这个指针所在的内存地址
  输入参数:
      二级结构体指针
  输出函数:
      一级结构体指针
*/
DNode* testPoint(DNode **Node)
{
	DNode *mNode = NULL;

	//正常的一个结构体指针的创建与初始化
	mNode = (DNode*)malloc(sizeof(DNode));
	mNode->x = 1;
	mNode->y = 1;
	mNode->next = NULL;
	strcpy(mNode->name,"test");

	*Node = mNode;

	return mNode;
}

/*
  函数说明:
      测试的是结构体传值,因为需要将Node的改变传递出去,所以采用一级指针输入
  输入参数:
      一级结构体指针
  输出函数:
      结构体
*/
DNode test(DNode *Node)
{
	DNode mNode;

	mNode.x = 2;
	mNode.y = 2;
	mNode.next = NULL;
	strcpy(mNode.name,"test");
	*Node = mNode;

	return mNode;
}

/*
  函数说明:
      测试的是结构体指针在传值的用法,因为不用将结果传递出去,所以可以将结构体指
	  针直接传递进来,注意如果是用二级指针传递的,在结构体引用时(*Node)->要用括号
	  因为->的优先级大于*
  输入参数:
      一级结构体指针
  输出参数:
      空值
*/
void Destory(DNode* Node)
{
	DNode *nextNode = Node;
	int i = 0;

	for(;;)
	{
		if(Node->next != NULL)
		{
			nextNode = Node->next;
			free(Node);
		}
		else
		{
			free(Node);
			break;
		}		
	}
}

/*
  函数说明:
      主函数
  输入参数:
      
  输出参数:
      
*/
int main(void)
{
	DNode *aNode = NULL;
	DNode *bNode = NULL;
	DNode cNode;
	DNode dNode;

	printf("hello world!!\n");

	aNode = testPoint(&bNode);
	cNode = test(&dNode);


	Destory(aNode);

	return 0;
}
