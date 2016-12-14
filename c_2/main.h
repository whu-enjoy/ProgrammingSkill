/*************************************************************************
    > File Name       : main.h
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月14日 星期三 13时32分31秒
 ************************************************************************/
 
 #ifndef _MAIN_H
 #define _MAIN_H

/********************************************************************
 * 头文件
 * *****************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

/********************************************************************
 * 宏定义
 * *****************************************************************/
#define IN const
#define OUT
#define BOC 10
#define UOC 1


/********************************************************************
 * 全局变量
 *******************************************************************/
// int binaryOp[] = {1,2,3,4,5,6,7,8,9,10};
char binaryOp_char[BOC+1][3] = {"","*", "/", "%", "+", "-", "<<", ">>", "&", "^", "|"};
// int unaryOp[] = {1};
char unaryOp_char[UOC+1][2] = {"","~"};
static
FILE* fd;
static
int T;
static
int flagTernaryOperator;
static
int flagUnaryOperator;

/********************************************************************
 * 函数列表
 * *****************************************************************/

/**********************************************************
 * 函数原型 :
 *     static
 *     int do_calc_unaryOperator(
 *             IN int op,
 *             IN int value)
 *
 * 函数功能 : 
 *     根据输入参数op选择单目运算符
 *     返回value的单目运算结果 
 *
 * 参数列表 :
 *     IN :
 *       int op : 单目运算符标志
 *           int unaryOp[] = {1};
 *           char unaryOp_char = {"~"};
 *       int value : 要计算的数据
 *     OUT:
 *	     无 
 *
 * 返回值   :
 *      返回value的单目运算结果
 * *******************************************************/
static
int do_calc_unaryOperator(
        IN int op, 
        IN int value);

/**********************************************************
 * 函数原型 :
 *     static
 *     int do_calc_binaryOperator(
 *         IN int op,
 *         IN int value1,
 *         IN int value2)
 *
 * 函数功能 : 
 *     根据op选择一个双目运算符,
 *     计算value1和value2的计算结果
 *
 * 参数列表 :
 *     IN :
 *       int op : 双目运算符标志
 *           char binaryOp_char[][] = 
 *           {"*", "/", "%", "+", "-", "<<", ">>", "&", "^", "|"};
 *           int binaryOp[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 *       int value1 : 第一个数据
 *       int value2 : 第二个数据
 *     OUT:
 *	       
 *
 * 返回值   :
 *     返回value1和value2的计算结果 
 * *******************************************************/
static
int do_calc_binaryOperator(
        IN int op, 
        IN int value1, 
        IN int value2);

/**********************************************************
 * 函数原型 :
 *     static
 *     int do_calc_ternaryOperator(
 *             IN int value1,
 *             IN int value2,
 *             IN int value3)
 *
 * 函数功能 : 
 *      计算并返回value1?value2:value3的结果
 *
 * 参数列表 :
 *     IN :
 *       int value1 : 第一个数据
 *       int value2 : 第二个数据
 *       int value3 : 第三个数据
 *     OUT:
 *	       
 *
 * 返回值   :
 *      value1?value2:value3的结果
 * *******************************************************/
static
int do_calc_ternaryOperator(
        IN int value1, 
        IN int value2, 
        IN int value3);

/**********************************************************
 * 函数原型 :
 *     static
 *     int CallBack(
 *             int (*fun)(),
 *             ...)
 *
 * 函数功能 : 
 *      回调函数
 *      通过给定的fun,选择
 *      do_calc_unaryOperator()/
 *      do_calc_binaryOperator()/
 *      do_calc_ternaryOperator()
 *      其中一个函数,并按照相应参数格式调用函数
 *
 * 参数列表 :
 *     IN :
 *             int (*fun)() : 需要回调的函数函数名(地址)
 *     OUT:
 *	       
 *
 * 返回值   :
 *      返回运算结果
 * *******************************************************/
static
int CallBack(int (*fun)(), ...);

/**********************************************************
 * 函数原型 :
 *     static
 *     int calc_unaryOperator(
 *             IN int op,
 *             IN int value,
 *             IN char str1[],
 *             OUT char str2[])
 *
 * 函数功能 : 
 *      如果op为0,则返回value
 *      如果op不为0,则调用回调函数计算op value的结果
 *      str2保存计算过程,用于后面的输出
 *
 * 参数列表 :
 *     IN :
 *       int op : 单目运算符标志
 *        0 表示不用单目运算符
 *        其他的参照
 *        char unaryOperator_char[] = {"~"};
 *        int unaryOperator[] = {1};
 *       int value : 要计算的数据
 *       char str1[] : 要计算的数据的字符串形式
 *     OUT:
 *	     char str2[] : 保存计算过程,便于后面输出 
 *
 * 返回值   :
 *      返回计算结果
 * *******************************************************/
static
int calc_unaryOperator(
		IN int op,
		IN int value,
		IN char str1[],
		OUT char str2[]);

/**********************************************************
 * 函数原型 :
 *	static
 *	int calc_binaryOperator(
 *			IN int op,
 *			IN int value1,
 *			IN int value2,
 *			IN char str1[],
 *			IN char str2[],
 *			OUT char str3[])
 *
 * 函数功能 : 
 *     调用do_calc_binaryOperator计算value1和value2的运算结果
 *     同时将计算过程保存在str3里面
 *
 * 参数列表 :
 *     IN :
 *       int op : 双目运算符标志
 *           char binaryOp_char[][] = 
 *           {"*", "/", "%", "+", "-", "<<", ">>", "&", "^", "|"};
 *           int binaryOp[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 *       int value1 : 第一个数据
 *       int value2 : 第二个数据
 *       char str1[]: 第一个数据字符串形式
 *       char str2[]: 第二个数据字符串形式
 *     OUT:
 *	     char str3[]: 保存计算过程  
 *
 * 返回值   :
 *     返回计算结果 
 * *******************************************************/
static
int calc_binaryOperator(
		IN int op,
		IN int value1,
		IN int value2,
		IN char str1[],
		IN char str2[],
		OUT char str3[]);

/**********************************************************
 * 函数原型 :
 *     static
 *     int binaryOperatpr(
 *             IN int value[],
 *             IN int unaryOp[],
 *             IN int op_1,
 *             IN int op_2,
 *             IN int op_3,
 *             IN int flag)
 *
 * 函数功能 : 
 *     计算一种双目运算符组合(eg:a + b + c + d)在加入单目运算符后的
 *     (flagUnaryOperator+1)^7种结果并输出
 *
 * 参数列表 :
 *     IN :
 *       int value[] : 要计算的四个数据
 *       int unaryOp[] : 单目运算符标志数组
 *       int op_1 : 第一个双目运算符
 *       int op_2 : 第二个双目运算符
 *       int op_3 : 第三个双目运算符
 *       int flag : 每种组合计算顺序标志
 *         0 : (((a b) c) d)
 *         1 : ((a b) (c d))
 *         2 : ((a (b c)) d)
 *         3 : (a ((b c) d))
 *         4 : (a (b (c d)))
 *     OUT:
 *	       
 *
 * 返回值   :
 *     0 
 * *******************************************************/
static
int binaryOperator(
		IN int value[],
		IN int unaryOp[],
		IN int op_1,
		IN int op_2,
		IN int op_3,
		IN int flag);

/**********************************************************
 * 函数原型 :
 *     static
 *     int calc_ternaryOperator(
 *             IN int value1,
 *             IN int value2,
 *             IN int value3,
 *             IN char str1[],
 *             IN char str2[],
 *             IN char str3[].
 *             OUT char str4[])
 *
 * 函数功能 : 
 *      调用CallBack回调函数计算value1?value2:value3的结果
 *      并保存计算过程
 *
 * 参数列表 :
 *     IN :
 *       int value1 : 第一个数据
 *       int value2 : 第二个数据
 *       int value3 : 第三个数据
 *       char str1[]: 第一个数据的字符串形式
 *       char str2[]: 第二个数据的字符串形式
 *       char str3[]: 第三个数据的字符串形式
 *     OUT:
 *       char str4[]: 保存计算过程
 *	       
 *
 * 返回值   :
 *     返回value1?value2:value3的结果 
 * *******************************************************/
static
int calc_ternaryOperator(
		IN int value1,
		IN int value2,
		IN int value3,
		IN char str1[],
		IN char str2[],
		IN char str3[],
		OUT char str4[]);

/**********************************************************
 * 函数原型 :
 *     static
 *     int ternaryOperator(
 *             IN int value[],
 *             IN int unaryOp[],
 *             IN int binaryOp[])
 *
 * 函数功能 : 
 *      对有三目运算符,双目运算符,单目运算符的情况进行遍历
 *      计算结果并输出对应的情况,如果结果与给定的值相等,则
 *      把遍历结果保存到score.txt中
 *
 * 参数列表 :
 *     IN :
 *       int value[]   : 要计算的数据
 *       int unaryOp[] : 单目运算符标志数组
 *       int binaryOp[]: 双目运算符标志数组
 *     OUT:
 *
 * 返回值   :
 *     0 
 * *******************************************************/
static
int ternaryOperator(
		IN int value[], 
		IN int unaryOp[],
		IN int binaryOp[]);

/**********************************************************
 * 函数原型 :
 *     IN int value[],
 *     IN int unaryOp[],
 *     IN int binaryOp[])
 *
 * 函数功能 : 
 *     对四个数据的一种排列,遍历运算符的组合 
 *
 * 参数列表 :
 *     IN :
 *       int value[]   : 要计算的四个数据
 *       int unaryOp[] : 单目运算符标志数组
 *       int binaryOp[]: 双目运算符标志数组
 *     OUT:
 *	       
 *
 * 返回值   :
 *     0 
 * *******************************************************/
static
int permutation(
		IN int value[], 
		IN int unaryOp[], 
		IN int binaryOp[]);

/**********************************************************
 * 函数原型 :
 *     static
 *     int getArray(
 *             OUT int value[], 
 *             IN int basePOS, 
 *             IN int n)
 * 函数功能 : 
 *     按照0-4的顺序依次递归确定各个位置上的数据,返回
 *     value[]数组的排列 
 *
 * 参数列表 :
 *     IN :
 *       int basePos : 要确定值的位置  
 *	     int n : 对于剩下数据的第N次排列 
 *	   OUT:
 *       int value[] : 要排列的数组
 *
 * 返回值   :
 *       0
 * *******************************************************/
static
int getArray(
        OUT int value[], 
        IN int basePos, 
        IN int n);

/**********************************************************
 * 函数原型 :
 *     static
 *     int factorial(
 *             IN int n)
 *
 * 函数功能 : 
 *     递归计算N的阶乘
 *
 * 参数列表 :
 *     IN :
 *        int n : 要计算的数
 *     OUT:
 *	      无
 *
 * 返回值   :
 *     返回n*factorial(n-1)
 * *******************************************************/
static
int factorial(
        IN int n);

/**********************************************************
 * 函数原型 :
 *     static
 *     int getInput(
 *             OUT int value[],
 *             OUT int unaryOp[],
 *             OUT int binaryOp[])
 *
 * 函数功能 : 
 *     获取用户的输入
 *     填充value数组
 *     填充unaryOp数组和binaryOp数组
 *     设置flagUnaryOperator和flagBinaryOperator标志
 *
 * 参数列表 :
 *     IN :
 *         
 *     OUT:
 *	     int value[]   : 保存用户输入的数据  
 *	     int unaryOp[] : 保存用户输入的单目运算符的对应标志
 *	     int binaryOp[]: 保存用户输入的双目运算符的对应标志
 *
 * 返回值   :
 *     0 
 * *******************************************************/
static 
int getInput(
		OUT int value[],
		OUT int unaryOp[],
		OUT int binaryOp[]);
#endif /* _MAIN_H */

