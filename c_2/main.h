/*************************************************************************
    > File Name       : main.h
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016��12��14�� ������ 13ʱ32��31��
 ************************************************************************/
 
 #ifndef _MAIN_H
 #define _MAIN_H

/********************************************************************
 * ͷ�ļ�
 * *****************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

/********************************************************************
 * �궨��
 * *****************************************************************/
#define IN const
#define OUT
#define BOC 10
#define UOC 1


/********************************************************************
 * ȫ�ֱ���
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
 * �����б�
 * *****************************************************************/

/**********************************************************
 * ����ԭ�� :
 *     static
 *     int do_calc_unaryOperator(
 *             IN int op,
 *             IN int value)
 *
 * �������� : 
 *     �����������opѡ��Ŀ�����
 *     ����value�ĵ�Ŀ������ 
 *
 * �����б� :
 *     IN :
 *       int op : ��Ŀ�������־
 *           int unaryOp[] = {1};
 *           char unaryOp_char = {"~"};
 *       int value : Ҫ���������
 *     OUT:
 *	     �� 
 *
 * ����ֵ   :
 *      ����value�ĵ�Ŀ������
 * *******************************************************/
static
int do_calc_unaryOperator(
        IN int op, 
        IN int value);

/**********************************************************
 * ����ԭ�� :
 *     static
 *     int do_calc_binaryOperator(
 *         IN int op,
 *         IN int value1,
 *         IN int value2)
 *
 * �������� : 
 *     ����opѡ��һ��˫Ŀ�����,
 *     ����value1��value2�ļ�����
 *
 * �����б� :
 *     IN :
 *       int op : ˫Ŀ�������־
 *           char binaryOp_char[][] = 
 *           {"*", "/", "%", "+", "-", "<<", ">>", "&", "^", "|"};
 *           int binaryOp[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 *       int value1 : ��һ������
 *       int value2 : �ڶ�������
 *     OUT:
 *	       
 *
 * ����ֵ   :
 *     ����value1��value2�ļ����� 
 * *******************************************************/
static
int do_calc_binaryOperator(
        IN int op, 
        IN int value1, 
        IN int value2);

/**********************************************************
 * ����ԭ�� :
 *     static
 *     int do_calc_ternaryOperator(
 *             IN int value1,
 *             IN int value2,
 *             IN int value3)
 *
 * �������� : 
 *      ���㲢����value1?value2:value3�Ľ��
 *
 * �����б� :
 *     IN :
 *       int value1 : ��һ������
 *       int value2 : �ڶ�������
 *       int value3 : ����������
 *     OUT:
 *	       
 *
 * ����ֵ   :
 *      value1?value2:value3�Ľ��
 * *******************************************************/
static
int do_calc_ternaryOperator(
        IN int value1, 
        IN int value2, 
        IN int value3);

/**********************************************************
 * ����ԭ�� :
 *     static
 *     int CallBack(
 *             int (*fun)(),
 *             ...)
 *
 * �������� : 
 *      �ص�����
 *      ͨ��������fun,ѡ��
 *      do_calc_unaryOperator()/
 *      do_calc_binaryOperator()/
 *      do_calc_ternaryOperator()
 *      ����һ������,��������Ӧ������ʽ���ú���
 *
 * �����б� :
 *     IN :
 *             int (*fun)() : ��Ҫ�ص��ĺ���������(��ַ)
 *     OUT:
 *	       
 *
 * ����ֵ   :
 *      ����������
 * *******************************************************/
static
int CallBack(int (*fun)(), ...);

/**********************************************************
 * ����ԭ�� :
 *     static
 *     int calc_unaryOperator(
 *             IN int op,
 *             IN int value,
 *             IN char str1[],
 *             OUT char str2[])
 *
 * �������� : 
 *      ���opΪ0,�򷵻�value
 *      ���op��Ϊ0,����ûص���������op value�Ľ��
 *      str2����������,���ں�������
 *
 * �����б� :
 *     IN :
 *       int op : ��Ŀ�������־
 *        0 ��ʾ���õ�Ŀ�����
 *        �����Ĳ���
 *        char unaryOperator_char[] = {"~"};
 *        int unaryOperator[] = {1};
 *       int value : Ҫ���������
 *       char str1[] : Ҫ��������ݵ��ַ�����ʽ
 *     OUT:
 *	     char str2[] : ����������,���ں������ 
 *
 * ����ֵ   :
 *      ���ؼ�����
 * *******************************************************/
static
int calc_unaryOperator(
		IN int op,
		IN int value,
		IN char str1[],
		OUT char str2[]);

/**********************************************************
 * ����ԭ�� :
 *	static
 *	int calc_binaryOperator(
 *			IN int op,
 *			IN int value1,
 *			IN int value2,
 *			IN char str1[],
 *			IN char str2[],
 *			OUT char str3[])
 *
 * �������� : 
 *     ����do_calc_binaryOperator����value1��value2��������
 *     ͬʱ��������̱�����str3����
 *
 * �����б� :
 *     IN :
 *       int op : ˫Ŀ�������־
 *           char binaryOp_char[][] = 
 *           {"*", "/", "%", "+", "-", "<<", ">>", "&", "^", "|"};
 *           int binaryOp[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 *       int value1 : ��һ������
 *       int value2 : �ڶ�������
 *       char str1[]: ��һ�������ַ�����ʽ
 *       char str2[]: �ڶ��������ַ�����ʽ
 *     OUT:
 *	     char str3[]: ����������  
 *
 * ����ֵ   :
 *     ���ؼ����� 
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
 * ����ԭ�� :
 *     static
 *     int binaryOperatpr(
 *             IN int value[],
 *             IN int unaryOp[],
 *             IN int op_1,
 *             IN int op_2,
 *             IN int op_3,
 *             IN int flag)
 *
 * �������� : 
 *     ����һ��˫Ŀ��������(eg:a + b + c + d)�ڼ��뵥Ŀ��������
 *     (flagUnaryOperator+1)^7�ֽ�������
 *
 * �����б� :
 *     IN :
 *       int value[] : Ҫ������ĸ�����
 *       int unaryOp[] : ��Ŀ�������־����
 *       int op_1 : ��һ��˫Ŀ�����
 *       int op_2 : �ڶ���˫Ŀ�����
 *       int op_3 : ������˫Ŀ�����
 *       int flag : ÿ����ϼ���˳���־
 *         0 : (((a b) c) d)
 *         1 : ((a b) (c d))
 *         2 : ((a (b c)) d)
 *         3 : (a ((b c) d))
 *         4 : (a (b (c d)))
 *     OUT:
 *	       
 *
 * ����ֵ   :
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
 * ����ԭ�� :
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
 * �������� : 
 *      ����CallBack�ص���������value1?value2:value3�Ľ��
 *      ������������
 *
 * �����б� :
 *     IN :
 *       int value1 : ��һ������
 *       int value2 : �ڶ�������
 *       int value3 : ����������
 *       char str1[]: ��һ�����ݵ��ַ�����ʽ
 *       char str2[]: �ڶ������ݵ��ַ�����ʽ
 *       char str3[]: ���������ݵ��ַ�����ʽ
 *     OUT:
 *       char str4[]: ����������
 *	       
 *
 * ����ֵ   :
 *     ����value1?value2:value3�Ľ�� 
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
 * ����ԭ�� :
 *     static
 *     int ternaryOperator(
 *             IN int value[],
 *             IN int unaryOp[],
 *             IN int binaryOp[])
 *
 * �������� : 
 *      ������Ŀ�����,˫Ŀ�����,��Ŀ�������������б���
 *      �������������Ӧ�����,�������������ֵ���,��
 *      �ѱ���������浽score.txt��
 *
 * �����б� :
 *     IN :
 *       int value[]   : Ҫ���������
 *       int unaryOp[] : ��Ŀ�������־����
 *       int binaryOp[]: ˫Ŀ�������־����
 *     OUT:
 *
 * ����ֵ   :
 *     0 
 * *******************************************************/
static
int ternaryOperator(
		IN int value[], 
		IN int unaryOp[],
		IN int binaryOp[]);

/**********************************************************
 * ����ԭ�� :
 *     IN int value[],
 *     IN int unaryOp[],
 *     IN int binaryOp[])
 *
 * �������� : 
 *     ���ĸ����ݵ�һ������,�������������� 
 *
 * �����б� :
 *     IN :
 *       int value[]   : Ҫ������ĸ�����
 *       int unaryOp[] : ��Ŀ�������־����
 *       int binaryOp[]: ˫Ŀ�������־����
 *     OUT:
 *	       
 *
 * ����ֵ   :
 *     0 
 * *******************************************************/
static
int permutation(
		IN int value[], 
		IN int unaryOp[], 
		IN int binaryOp[]);

/**********************************************************
 * ����ԭ�� :
 *     static
 *     int getArray(
 *             OUT int value[], 
 *             IN int basePOS, 
 *             IN int n)
 * �������� : 
 *     ����0-4��˳�����εݹ�ȷ������λ���ϵ�����,����
 *     value[]��������� 
 *
 * �����б� :
 *     IN :
 *       int basePos : Ҫȷ��ֵ��λ��  
 *	     int n : ����ʣ�����ݵĵ�N������ 
 *	   OUT:
 *       int value[] : Ҫ���е�����
 *
 * ����ֵ   :
 *       0
 * *******************************************************/
static
int getArray(
        OUT int value[], 
        IN int basePos, 
        IN int n);

/**********************************************************
 * ����ԭ�� :
 *     static
 *     int factorial(
 *             IN int n)
 *
 * �������� : 
 *     �ݹ����N�Ľ׳�
 *
 * �����б� :
 *     IN :
 *        int n : Ҫ�������
 *     OUT:
 *	      ��
 *
 * ����ֵ   :
 *     ����n*factorial(n-1)
 * *******************************************************/
static
int factorial(
        IN int n);

/**********************************************************
 * ����ԭ�� :
 *     static
 *     int getInput(
 *             OUT int value[],
 *             OUT int unaryOp[],
 *             OUT int binaryOp[])
 *
 * �������� : 
 *     ��ȡ�û�������
 *     ���value����
 *     ���unaryOp�����binaryOp����
 *     ����flagUnaryOperator��flagBinaryOperator��־
 *
 * �����б� :
 *     IN :
 *         
 *     OUT:
 *	     int value[]   : �����û����������  
 *	     int unaryOp[] : �����û�����ĵ�Ŀ������Ķ�Ӧ��־
 *	     int binaryOp[]: �����û������˫Ŀ������Ķ�Ӧ��־
 *
 * ����ֵ   :
 *     0 
 * *******************************************************/
static 
int getInput(
		OUT int value[],
		OUT int unaryOp[],
		OUT int binaryOp[]);
#endif /* _MAIN_H */

