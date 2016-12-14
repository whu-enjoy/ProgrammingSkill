/*************************************************************************
    > File Name       : main.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016年12月09日 星期五 15时16分03秒
 ************************************************************************/

#include "main.h"

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
int do_calc_unaryOperator(IN int op, IN int value)
{
    switch(op)
    {
    case 1: // ~
        return ~value;
    default:
        printf("the Unary Operator type is error!!\nplease check and try again!\n");
        exit(1);
    }
}

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
int do_calc_binaryOperator(IN int op, IN int value1, IN int value2)
{
	switch(op)
	{
		case 1: // *
			return value1*value2;
		case 2: // /
			return value1/value2;
		case 3: // %
			return value1%value2;
		case 4: // +
			return value1+value2;
		case 5: // -
			return value1-value2;
		case 6: // <<
			return value1<<value2;
		case 7: // >>
			return value1>>value2;
		case 8: // &
			return value1&value2;
		case 9: // ^
			return value1^value2;
		case 10: // |
			return value1|value2;
		default:
			printf("the binary operator is error!\nplease check and try again\n");
			exit(1);
	}
}

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
int do_calc_ternaryOperator(IN int value1, IN int value2, IN int value3)
{
	return value1?value2:value3;
}

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
int CallBack(int (*fun)(), ...)
{
	va_list argp;
	int op = 0;
	int value1 = 0;
	int value2 = 0;
	int value3 = 0;
	int result = 0;

	va_start(argp, fun); //根据fun获取argp结构体偏移

	//如果选择单目运算
	//则第二个参数为运算符标志
	//第三个参数为参加计算的数据
	//采用do_calc_unaryOperator()函数的参数形式调用fun
	if (fun == do_calc_unaryOperator)
	{
		op = va_arg(argp,int);
		value1 = va_arg(argp, int);
		result = fun(op, value1);
	}
	//如果选择三目运算
	//则第２３４个参数为参加计算的数据
	//采用do_calc_ternaryOperator()函数的参数形式调用fun
	else if (fun == do_calc_ternaryOperator)
	{
		value1 = va_arg(argp, int);
		value2 = va_arg(argp, int);
		value3 = va_arg(argp, int);
		result = fun(value1, value2, value3);
	}
	//否则是双目运算
	//则第二个参数是双目运算符标志
	//第三四个参数为参加计算的数据
	//采用do_calc_binaryOperator()函数的参数形式调用fun
	else
	{
		op = va_arg(argp, int);
		value1 = va_arg(argp,int);
		value2 = va_arg(argp,int);
		result = fun(op, value1, value2);
	}
	va_end(argp);

	return result;
}

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
		OUT char str2[])
{
    switch(op)
    {
    case 0:
        sprintf(str2, "(%s)", str1);
        return value;
    default:
        sprintf(str2, "(%s%s)",unaryOp_char[op], str1);
        return CallBack(do_calc_unaryOperator, op, value);        
    }
}

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
		OUT char str3[])
{
	sprintf(str3,"(%s %s %s)",str1, binaryOp_char[op], str2);
    return CallBack(do_calc_binaryOperator, op, value1, value2);
}

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
		IN int flag)
{
	char str1[80] = {0}; //用于保存字符串
	char str2[80] = {0}; //用于保存字符串
	char str3[80] = {0}; //用于保存字符串
	char str4[80] = {0}; //用于保存字符串
	int result1 = 0; //用于保存计算结果
	int result2 = 0; //用于保存计算结果
	int result3 = 0; //用于保存计算结果
	int result4 = 0; //用于保存计算结果
	int result = 0;  //用于保存最终结果
	int i[8] = {0};  //循环变量
	int count[8] = {0}; //每轮循环次数,count[0]没有使用
	
	//设置每轮循环次数(为单目运算符数量+1)
	for (i[0] = 0; i[0] < 8; i[0]++)
	{
	    count[i[0]] = flagUnaryOperator+1;
	}
	
	//七轮循环,有七个位置可以放置单目运算符,
	//每个位置可以选择放或者放哪个单目运算符
	//先对首先计算的两个数据遍历
	//然后对第二次计算的两个数据遍历
	//再对对第三次计算的两个数据遍历
	//再对结果进行遍历
  	for(i[1] = 0; i[1] < count[1]; i[1]++)
    {
     	for(i[2] = 0; i[2] < count[2]; i[2]++)
        {
         	for(i[3] = 0; i[3] < count[3]; i[3]++)
            {
             	for(i[4] = 0; i[4] < count[4]; i[4]++)
                {
                 	for(i[5] = 0; i[5] < count[5]; i[5]++)
                    {
                     	for(i[6] = 0; i[6] < count[6]; i[6]++)
                        {
                         	for(i[7] = 0; i[7] < count[7]; i[7]++)
                            {
                                switch(flag)
                                {
                                case 0://(((a b) c) d)
                                    //(a b)
                                    sprintf(str2,"%d", value[0]);
					                result1 = calc_unaryOperator(unaryOp[i[7]], value[0], str2, str1);
					       			sprintf(str3,"%d", value[1]);
					                result2 = calc_unaryOperator(unaryOp[i[6]], value[1], str3, str2);						                
					                if (((7 == op_1 || 6 == op_1) && result2 < 0) || ((2 == op_1 || 3 == op_1) && 0 == result2))
					                {
					                    continue; //op = << , >> && value2 < 0   op == / , % && value2 == 0
					                }
					                result3 = calc_binaryOperator(op_1, result1, result2, str1, str2, str3);
					                
					                //((a b) c)
					                result1 = calc_unaryOperator(unaryOp[i[5]], result3, str3, str1);
					                sprintf(str3, "%d", value[2]);						                
					                result2 = calc_unaryOperator(unaryOp[i[4]], value[2], str3, str2);						            
					                if (((7 == op_2 || 6 == op_2) && result2 < 0) || ((2 == op_2 || 3 == op_2) && 0 == result2))
					                {
					                    continue; //op = << , >> && value2 < 0   op == / , % && value2 == 0
					                }    
					                result3 = calc_binaryOperator(op_2, result1 , result2, str1, str2, str3);
					                
					                //(((a b) c) d)
					                result1 = calc_unaryOperator(unaryOp[i[3]], result3, str3, str1);						                
					                sprintf(str3, "%d", value[3]);
					                result2 = calc_unaryOperator(unaryOp[i[2]], value[3], str3, str2);						                
					                if (((7 == op_3 || 6 == op_3) && result2 < 0) || ((2 == op_3 || 3 == op_3) && 0 == result2))
					                {
					                    continue; //op = << , >> && value2 < 0   op == / , % && value2 == 0
					                }
					                result3 = calc_binaryOperator(op_3, result1, result2, str1, str2, str3);					                
					                result = calc_unaryOperator(unaryOp[i[1]], result3, str3, str1);
					                
					                sprintf(str3, "(((a b) c) d) (%d): %s", i[7]+i[6]*count[7]+i[5]*count[7]*count[6]+i[4]*count[7]*count[6]*count[5]+i[3]*count[7]*count[6]*count[5]*count[4]+i[2]*count[7]*count[6]*count[5]*count[4]*count[3]+i[1]*count[7]*count[6]*count[5]*count[4]*count[3]*count[2], str1);
					                break;
                                    
                                case 1://((a b) (c d))
                                    //(a b)
                                    sprintf(str2,"%d", value[0]);
					                result1 = calc_unaryOperator(unaryOp[i[7]], value[0], str2, str1);
					       			sprintf(str3,"%d", value[1]);
					                result2 = calc_unaryOperator(unaryOp[i[6]], value[1], str3, str2);						            
					                if (((7 == op_1 || 6 == op_1) && result2 < 0) || ((2 == op_1 || 3 == op_1) && 0 == result2))
					                {
					                    continue; //op = << , >> && value2 < 0   op == / , % && value2 == 0
					                }    
					                result3 = calc_binaryOperator(op_1, result1, result2, str1, str2, str3);
					                
					                //(c d)
                                    sprintf(str2,"%d", value[2]);
					                result1 = calc_unaryOperator(unaryOp[i[5]], value[2], str2, str1);
					       			sprintf(str4,"%d", value[3]);
					                result2 = calc_unaryOperator(unaryOp[i[4]], value[3], str4, str2);
					                if (((7 == op_3 || 6 == op_3) && result2 < 0) || ((2 == op_3 || 3 == op_3) && 0 == result2))
					                {
					                    continue; //op = << , >> && value2 < 0   op == / , % && value2 == 0
					                }
					                result4 = calc_binaryOperator(op_3, result1, result2, str1, str2, str4);
					                
					                //((a b) (c d))					                
					                result1 = calc_unaryOperator(unaryOp[i[3]], result3, str3, str1);	
					                result2 = calc_unaryOperator(unaryOp[i[2]], result4, str4, str2);
					                if (((7 == op_2 || 6 == op_2) && result2 < 0) || ((2 == op_2 || 3 == op_2) && 0 == result2))
					                {
					                    continue; //op = << , >> && value2 < 0   op == / , % && value2 == 0
					                }					                	
					                result3 = calc_binaryOperator(op_2, result1, result2, str1, str2, str3);					                
					                result = calc_unaryOperator(unaryOp[i[1]], result3, str3, str1);
					                
					                sprintf(str3, "((a b) (c d)) (%d): %s", i[7]+i[6]*count[7]+i[5]*count[7]*count[6]+i[4]*count[7]*count[6]*count[5]+i[3]*count[7]*count[6]*count[5]*count[4]+i[2]*count[7]*count[6]*count[5]*count[4]*count[3]+i[1]*count[7]*count[6]*count[5]*count[4]*count[3]*count[2], str1);						  			                
                                    break;
                                    
                                case 2://((a (b c)) d)
                                    //(b c)
                                    sprintf(str2,"%d", value[1]);
					                result1 = calc_unaryOperator(unaryOp[i[7]], value[1], str2, str1);
					       			sprintf(str3,"%d", value[2]);
					                result2 = calc_unaryOperator(unaryOp[i[6]], value[2], str3, str2);						                
					                if (((7 == op_2 || 6 == op_2) && result2 < 0) || ((2 == op_2 || 3 == op_2) && 0 == result2))
					                {
					                    continue; //op = << , >> && value2 < 0   op == / , % && value2 == 0
					                }
					                result3 = calc_binaryOperator(op_2, result1, result2, str1, str2, str3);

					                //(a (b c))
					                sprintf(str2, "%d", value[0]);						                
					                result1 = calc_unaryOperator(unaryOp[i[5]], value[0], str2, str1);
					                result2 = calc_unaryOperator(unaryOp[i[4]], result3, str3, str2);
					                if (((7 == op_1 || 6 == op_1) && result2 < 0) || ((2 == op_1 || 3 == op_1) && 0 == result2))
					                {
					                    continue; //op = << , >> && value2 < 0   op == / , % && value2 == 0
					                }
					                result3 = calc_binaryOperator(op_1, result1 , result2, str1, str2, str3);
					                
					                //((a (b c)) d)
					                result1 = calc_unaryOperator(unaryOp[i[3]], result3, str3, str1);						                
					                sprintf(str3, "%d", value[3]);
					                result2 = calc_unaryOperator(unaryOp[i[2]], value[3], str3, str2);						                
					                if (((7 == op_3 || 6 == op_3) && result2 < 0) || ((2 == op_3 || 3 == op_3) && 0 == result2))
					                {
					                    continue; //op = << , >> && value2 < 0   op == / , % && value2 == 0
					                }
					                result3 = calc_binaryOperator(op_3, result1, result2, str1, str2, str3);		
					                result = calc_unaryOperator(unaryOp[i[1]], result3, str3, str1);
					                
					                sprintf(str3, "((a (b c)) d) (%d): %s", i[7]+i[6]*count[7]+i[5]*count[7]*count[6]+i[4]*count[7]*count[6]*count[5]+i[3]*count[7]*count[6]*count[5]*count[4]+i[2]*count[7]*count[6]*count[5]*count[4]*count[3]+i[1]*count[7]*count[6]*count[5]*count[4]*count[3]*count[2], str1);			                
					                break;
					                
                                case 3://(a ((b c) d))
                                    //(b c)
                                    sprintf(str2,"%d", value[1]);
					                result1 = calc_unaryOperator(unaryOp[i[7]], value[1], str2, str1);
					       			sprintf(str3,"%d", value[2]);
					                result2 = calc_unaryOperator(unaryOp[i[6]], value[2], str3, str2);						                
					                if (((7 == op_2 || 6 == op_2) && result2 < 0) || ((2 == op_2 || 3 == op_2) && 0 == result2))
					                {
					                    continue; //op = << , >> && value2 < 0   op == / , % && value2 == 0
					                }
					                result3 = calc_binaryOperator(op_2, result1, result2, str1, str2, str3); 
					                                                   
                                    //((b c) d)
					                result1 = calc_unaryOperator(unaryOp[i[5]], result3, str3, str1);
					                sprintf(str3, "%d", value[3]);						                
					                result2 = calc_unaryOperator(unaryOp[i[4]], value[3], str3, str2);						                
					                if (((7 == op_3 || 6 == op_3) && result2 < 0) || ((2 == op_3 || 3 == op_3) && 0 == result2))
					                {
					                    continue; //op = << , >> && value2 < 0   op == / , % && value2 == 0
					                }
					                result3 = calc_binaryOperator(op_3, result1 , result2, str1, str2, str3);
					                                                    
                                    //(a ((b c) d))
                                    sprintf(str2, "%d", value[0]);
					                result1 = calc_unaryOperator(unaryOp[i[3]], value[0], str2, str1);
					                result2 = calc_unaryOperator(unaryOp[i[2]], result3, str3, str2);
					                if (((7 == op_1 || 6 == op_1) && result2 < 0) || ((2 == op_1 || 3 == op_1) && 0 == result2))
					                {
					                    continue; //op = << , >> && value2 < 0   op == / , % && value2 == 0
					                }						                
					                result3 = calc_binaryOperator(op_1, result1, result2, str1, str2, str3);		
					                result = calc_unaryOperator(unaryOp[i[1]], result3, str3, str1);
					                
					                sprintf(str3, "(a ((b c) d)) (%d): %s", i[7]+i[6]*count[7]+i[5]*count[7]*count[6]+i[4]*count[7]*count[6]*count[5]+i[3]*count[7]*count[6]*count[5]*count[4]+i[2]*count[7]*count[6]*count[5]*count[4]*count[3]+i[1]*count[7]*count[6]*count[5]*count[4]*count[3]*count[2], str1);
					                break;
					                
                                case 4://(a (b (c d)))
					                //(c d)
                                    sprintf(str2,"%d", value[2]);
					                result1 = calc_unaryOperator(unaryOp[i[7]], value[2], str2, str1);
					       			sprintf(str3,"%d", value[3]);
					                result2 = calc_unaryOperator(unaryOp[i[6]], value[3], str3, str2);
					                if (((7 == op_3 || 6 == op_3) && result2 < 0) || ((2 == op_3 || 3 == op_3) && 0 == result2))
					                {
					                    continue; //op = << , >> && value2 < 0   op == / , % && value2 == 0
					                }
					                result3 = calc_binaryOperator(op_3, result1, result2, str1, str2, str3);

					                //(b (c d))
					                sprintf(str2, "%d", value[1]);						                
					                result1 = calc_unaryOperator(unaryOp[i[5]], value[1], str2, str1);
					                result2 = calc_unaryOperator(unaryOp[i[4]], result3, str3, str2);
					                if (((7 == op_2 || 6 == op_2) && result2 < 0) || ((2 == op_2 || 3 == op_2) && 0 == result2))
					                {
					                    continue; //op = << , >> && value2 < 0   op == / , % && value2 == 0
					                }
					                result3 = calc_binaryOperator(op_2, result1 , result2, str1, str2, str3);	
					                
					                //(a (b (c d)))
					                sprintf(str2, "%d", value[0]);						                
					                result1 = calc_unaryOperator(unaryOp[i[3]], value[0], str2, str1);
					                result2 = calc_unaryOperator(unaryOp[i[2]], result3, str3, str2);
					                if (((7 == op_1 || 6 == op_1) && result2 < 0) || ((2 == op_1 || 3 == op_1) && 0 == result2))
					                {
					                    continue; //op = << , >> && value2 < 0   op == / , % && value2 == 0
					                }
					                result3 = calc_binaryOperator(op_1, result1 , result2, str1, str2, str3);
					                result = calc_unaryOperator(unaryOp[i[1]], result3, str3, str1);
					                
					                sprintf(str3, "(a (b (c d))) (%d): %s", i[7]+i[6]*count[7]+i[5]*count[7]*count[6]+i[4]*count[7]*count[6]*count[5]+i[3]*count[7]*count[6]*count[5]*count[4]+i[2]*count[7]*count[6]*count[5]*count[4]*count[3]+i[1]*count[7]*count[6]*count[5]*count[4]*count[3]*count[2], str1);
					                break;
					                
                                default:
                                    printf("error type of order!\n");
		                            exit(-3);
                                }                                
                                
								//输出结果
				                printf("%s = %d\n", str3, result);
								//如果结果与给定的值相等,则输出到文件
				                if (result == T)
				                {
				                    fprintf(fd, "%s = %d\n", str3, result);
				                }
                            }   
                        }   
                    }   
                }   
            }   
        }   
    }  
		               
	return 0;
}

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
		OUT char str4[])
{
    sprintf(str4, "%s ? %s : %s", str1, str2, str3);
    return CallBack(do_calc_ternaryOperator, value1, value2, value3);
}

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
		IN int binaryOp[])
{
    char str1[80] = {0}; //用于保存字符串
    char str2[80] = {0}; //用于保存字符串
    char str3[80] = {0}; //用于保存字符串
    char str4[80] = {0}; //用于保存字符串
    int result1 = 0; //用于保存结果
    int result2 = 0; //用于保存结果
    int result3 = 0; //用于保存结果
    int result = 0;  //用于保存最终结果
 	int i[8] = {0};  //循环变量
	int count[7] = {0}; //循环次数
	int op = 0; //操作符标志
	
	//设置循环次数为单目运算符数量+1
	for (i[0] = 1; i[0] < 7; i[0]++)
	{
	    count[i[0]] = flagUnaryOperator+1;
	}
	
	//遍历双目运算符标志数组
	for (i[0] = 0; i[0] < BOC; i[0]++)
	{
	    op = binaryOp[i[0]];
		//如果某个数组元素为0,说明用户没有给定这个运算符
		//跳过本轮循环
	    if (0 == op)
	    {
	        continue;
	    }

		//对三目运算符加入单目运算符后的六种情况进行遍历
		//每次循环都是先对双目运算符的两个数据遍历
		//再对三目运算符的三个数据遍历
		//在对结果进行遍历
      	for(i[1] = 0; i[1] < count[1]; i[1]++)
        {
         	for(i[2] = 0; i[2] < count[2]; i[2]++)
            {
             	for(i[3] = 0; i[3] < count[3]; i[3]++)
                {
                 	for(i[4] = 0; i[4] < count[4]; i[4]++)
                    {
                     	for(i[5] = 0; i[5] < count[5]; i[5]++)
                        {
                            for (i[6] = 0; i[6] < count[6]; i[6]++)
                            {
								//对三目运算符的五种情况进行遍历
                                for (i[7] = 0; i[7] < 5; i[7]++)
                                {
                                    switch(i[7])
                                    {
                                    case 0://(ab?c:d)                                       
                                        //(a b)
                                        sprintf(str2,"%d", value[0]);
		                                result1 = calc_unaryOperator(unaryOp[i[6]], value[0], str2, str1);
		                       			sprintf(str3,"%d", value[1]);
		                                result2 = calc_unaryOperator(unaryOp[i[5]], value[1], str3, str2);
		                                if (((7 == op || 6 == op) && result2 < 0) || ((2 == op || 3 == op) && 0 == result2))
					                    {
					                        continue; //op = << , >> && value2 < 0   op == / , % && value2 == 0
					                    }						                
		                                result3 = calc_binaryOperator(op, result1, result2, str1, str2, str3);
		                                
		                                //((a b) ? c : d)
		                                result1 = calc_unaryOperator(unaryOp[i[4]], result3, str3, str1);
		                                sprintf(str3,"%d", value[2]);
		                                result2 = calc_unaryOperator(unaryOp[i[3]], value[2], str3, str2);
		                                sprintf(str4,"%d", value[3]);
		                                result3 = calc_unaryOperator(unaryOp[i[2]], value[3], str4, str3);
		                                result = calc_ternaryOperator(result1, result2, result3, str1, str2, str3, str4);
		                                result = calc_unaryOperator(unaryOp[i[1]], result, str4, str1);
		                                
		                                sprintf(str3, "((a b) ? c : d) (%d): %s", i[6]+i[5]*count[6]+i[4]*count[6]*count[5]+i[3]*count[6]*count[5]*count[4]+i[2]*count[6]*count[5]*count[4]*count[3]+i[1]*count[6]*count[5]*count[4]*count[3]*count[2], str1);	
		                                break;
		                                
                                    case 1://(a?bc:d)
                                        //(b c)
                                        sprintf(str2,"%d", value[1]);
		                                result1 = calc_unaryOperator(unaryOp[i[6]], value[1], str2, str1);
		                       			sprintf(str3,"%d", value[2]);
		                       			result2 = calc_unaryOperator(unaryOp[i[5]], value[2], str3, str2);
		                       			if (((7 == op || 6 == op) && result2 < 0) || ((2 == op || 3 == op) && 0 == result2))
					                    {
					                        continue; //op = << , >> && value2 < 0   op == / , % && value2 == 0
					                    }
						                result3 = calc_binaryOperator(op, result1, result2, str1, str2, str3);
		                                
		                                //(a ? (b c) : d)
		                                sprintf(str2,"%d", value[0]);
		                                result1 = calc_unaryOperator(unaryOp[i[4]], value[0], str2, str1);
		                                result2 = calc_unaryOperator(unaryOp[i[3]], result3, str3, str2);		                        
		                                sprintf(str4,"%d", value[3]);
		                                result3 = calc_unaryOperator(unaryOp[i[2]], value[3], str4, str3);
		                                result = calc_ternaryOperator(result1, result2, result3, str1, str2, str3, str4);
		                                result = calc_unaryOperator(unaryOp[i[1]], result, str4, str1);
		                                
		                                sprintf(str3, "(a ? (b c) : d) (%d): %s", i[6]+i[5]*count[6]+i[4]*count[6]*count[5]+i[3]*count[6]*count[5]*count[4]+i[2]*count[6]*count[5]*count[4]*count[3]+i[1]*count[6]*count[5]*count[4]*count[3]*count[2], str1);
		                                break;
		                                
		                            case 2://(a?b:cd)                                
                                        //(c d)
                                        sprintf(str2,"%d", value[2]);
		                                result1 = calc_unaryOperator(unaryOp[i[6]], value[2], str2, str1);
		                       			sprintf(str3,"%d", value[3]);
		                                result2 = calc_unaryOperator(unaryOp[i[5]], value[3], str3, str2);
		                                if (((7 == op || 6 == op) && result2 < 0) || ((2 == op || 3 == op) && 0 == result2))
					                    {
					                        continue; //op = << , >> && value2 < 0   op == / , % && value2 == 0
					                    }
		                                result3 = calc_binaryOperator(op, result1, result2, str1, str2, str3);
		                                
		                                //(a ? b : (c d))
		                                sprintf(str2,"%d", value[0]);
		                                result1 = calc_unaryOperator(unaryOp[i[4]], value[0], str2, str1);
		                                sprintf(str4,"%d", value[1]);
		                                result2 = calc_unaryOperator(unaryOp[i[3]], value[1], str4, str2);		                        
		                                result3 = calc_unaryOperator(unaryOp[i[2]], result3, str3, str4);
		                                result = calc_ternaryOperator(result1, result2, result3, str1, str2, str4, str3);
		                                result = calc_unaryOperator(unaryOp[i[1]], result, str3, str1);
		                                
		                                sprintf(str3, "(a ? b : (c d)) (%d): %s", i[6]+i[5]*count[6]+i[4]*count[6]*count[5]+i[3]*count[6]*count[5]*count[4]+i[2]*count[6]*count[5]*count[4]*count[3]+i[1]*count[6]*count[5]*count[4]*count[3]*count[2], str1); 
		                                break;
		                                
                                    case 3://(a?b:c d)                                
                                        //a ? b : c
                                        sprintf(str2,"%d", value[0]);
		                                result1 = calc_unaryOperator(unaryOp[i[4]], value[0], str2, str1);
		                                sprintf(str3,"%d", value[1]);
		                                result2 = calc_unaryOperator(unaryOp[i[3]], value[1], str3, str2);
		                                sprintf(str4,"%d", value[2]);
		                                result3 = calc_unaryOperator(unaryOp[i[2]], value[2], str4, str3);
		                                
		                                result = calc_ternaryOperator(result1, result2, result3, str1, str2, str3, str4);
		                                
		                                // ((a?b:c) d)
		                                result1 = calc_unaryOperator(unaryOp[i[6]], result, str4, str1);
		                                sprintf(str3,"%d", value[3]);
		                                result2 = calc_unaryOperator(unaryOp[i[5]], value[3], str3, str2);
		                                if (((7 == op || 6 == op) && result2 < 0) || ((2 == op || 3 == op) && 0 == result2))
					                    {
					                        continue; //op = << , >> && value2 < 0   op == / , % && value2 == 0
					                    }
		                                result = calc_binaryOperator(op, result1, result2, str1, str2, str3);
		                                result = calc_unaryOperator(unaryOp[i[1]], result, str3, str1);
		                                
		                                sprintf(str3, "((a ? b : c) d)) (%d): %s", i[6]+i[5]*count[6]+i[4]*count[6]*count[5]+i[3]*count[6]*count[5]*count[4]+i[2]*count[6]*count[5]*count[4]*count[3]+i[1]*count[6]*count[5]*count[4]*count[3]*count[2], str1);		  
		                                break;
		                                
                                    case 4://(a b?c:d)                                
                                        //b ? c : d
                                        sprintf(str2,"%d", value[1]);
		                                result1 = calc_unaryOperator(unaryOp[i[4]], value[1], str2, str1);
		                                sprintf(str3,"%d", value[2]);
		                                result2 = calc_unaryOperator(unaryOp[i[3]], value[2], str3, str2);
		                                sprintf(str4,"%d", value[3]);
		                                result3 = calc_unaryOperator(unaryOp[i[2]], value[3], str4, str3);
		                                
		                                result = calc_ternaryOperator(result1, result2, result3, str1, str2, str3, str4);
		                                
		                                // (a (b ? c : d))
		                                sprintf(str2,"%d", value[0]);
		                                result1 = calc_unaryOperator(unaryOp[i[6]], value[0], str2, str1);
		                                result2 = calc_unaryOperator(unaryOp[i[5]], result, str4, str2);
		                                if (((7 == op || 6 == op) && result2 < 0) || ((2 == op || 3 == op) && 0 == result2))
					                    {
					                        continue; //op = << , >> && value2 < 0   op == / , % && value2 == 0
					                    }		                        
		                                result = calc_binaryOperator(op, result1, result2, str1, str2, str3);
		                                result = calc_unaryOperator(unaryOp[i[1]], result, str3, str1);
		                                
		                                sprintf(str3, "(a (b ? c : d)) (%d): %s", i[6]+i[5]*count[6]+i[4]*count[6]*count[5]+i[3]*count[6]*count[5]*count[4]+i[2]*count[6]*count[5]*count[4]*count[3]+i[1]*count[6]*count[5]*count[4]*count[3]*count[2], str1);
		                                break;
		                                
                                    default:
                                        printf("error order!please check and try again!\n");
                                        exit(-4);
                                    }

									//输出结果
                                    printf("%s = %d\n", str3, result);
									//如果结果等于给定的值,则将结果保存到文件
				                    if (result == T)
				                    {
				                        fprintf(fd, "%s = %d\n", str3, result);
			 	                    }
                                }	
                             }
                         }
                     }                         
                 }
            }
        }
    }	
}

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
 *      
 * *******************************************************/
static
int permutation(
		IN int value[], 
		IN int unaryOp[], 
		IN int binaryOp[])
{
	//char unaryOp_char[][] = {"~"};
	//char binaryOp_char[10][] = {"", '*','/','%', '+','-', "<<",">>", '&', '^', '|'};
	//int binaryOp[] = {1,2,3,4,5,6,7,8,9,10};
	//int unaryOp[] = {1};
	
	int i[4] = {0}; //循环变量	
	int op_1 = 0;   //保存第一个双目运算符的标志
	int op_2= 0;    //保存第二个双目运算符的标志
	int op_3 = 0;   //保存第三个双目运算符的标志

	//计算只有单目运算符和双目运算符的情况
	//因为一个组合在加入单目运算符后有七种情况
	//所以就把双目运算符的组合遍历放在这个函数
	//否则循环层太多了
	//这里三层循环用于遍历三个双目运算符的排列
	for (i[0] = 0; i[0] < BOC; i[0]++)
	{
		for (i[1] = 0; i[1] < BOC; i[1]++)
		{
			for (i[2] = 0; i[2] < BOC; i[2]++)
			{
			    op_1 = binaryOp[i[0]];
			    op_2 = binaryOp[i[1]];
			    op_3 = binaryOp[i[2]];

				//如果三个双目运算符中有一个标志为0
				//说明用户没有给定相应的双目运算符
			    if (0==op_1 || 0==op_2 || 0==op_3)
			    {
				    continue;
			    }

                //对于一种组合,有五种计算顺序
				//0 : (((a b) c ) d)
				//1 : ((a b) (c d))
				//2 : ((a (b c)) d)
				//3 : (a ((b c) d))
				//4 : (a (b (c d)))
			    for (i[3] = 0; i[3] < 5; i[3]++)
			    {
			        binaryOperator(value, unaryOp, op_1, op_2, op_3, i[3]);
			    }			    													    
			}
		}
	}

	//计算有三目运算符,双目运算符,单目运算符的情况
	//如果flagTernaryOperator为0,说明用户没有给定三目运算符
	//可以直接结束本函数
	if (0 == flagTernaryOperator)
	{
		return 0;
	}
	else
	{
	    ternaryOperator(value, unaryOp, binaryOp);
	}

	return 0;
}

/**********************************************************
 * 函数原型 :
 *     static
 *     int getArray(
 *             OUT int value[], 
 *             IN int basePOS, 
 *             IN int n)
 *
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
int getArray(OUT int value[], IN int basePos, IN int n)
{
	int tmp = 0;     //保存中间值
	int i = 0;       //循环变量
	int swapPos = 0; //第basePos个位置上数据所在的位置

	if (basePos > 3) //只要将前三个位置数据确定,排列就完成了
	{
		return 0;
	}

	//获取第basePos个位置上的数据所在的位置
	swapPos = n/factorial(4-basePos-1)+basePos;

	//保存原数据
	tmp = value[swapPos];

	//将basePos和swapPos之间的数据整体后移一个位置
	//包括basePos但是不包括swapPos
	for (i = swapPos; i > basePos; i--)
	{
		value[i] = value[i-1];
	}

	//将swapPos上的值赋给basePos位置完成basePos上的值的替换
	value[basePos] = tmp;

	//递归排列basePos后面的数据
	getArray(value, basePos+1, n%factorial(4-basePos-1));

	return 0;
}

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
int factorial(IN int n)
{
	if (n < 2)
	{
		return 1;
	}
	else
	{
		return n*factorial(n-1);
	}
}

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
		OUT int binaryOp[])
{
	char op[3] = {0};           //保存用户输入的操作符
	int i = 0;                  //循环变量
	int binaryFlag[BOC] = {0};  //用于指示某个双目运算符是否已经输入了
	int unaryFlag[UOC] = {0};   //用于指示某个单目运算符是否已经输入了
	char cleanStdin = '\0';     //用于清除输入缓冲区
	
	//获取value[]
	printf("please input 4 value : ");
	for (i = 0; i < 4; i++)
	{
		scanf("%d", &value[i]);
	}

	//清空输入缓冲区
	while('\n' != (cleanStdin = getchar()));

	//获取T
	printf("please input T :");
	scanf("%d",&T);

	//循环获取用户输入,直到用户按照正确格式输入退出循环
	{
retry:
		//将flagUnaryOperator和flagBinaryOperator置0
		flagUnaryOperator = 0;
		flagTernaryOperator = 0;

		//清空binaryFlag数组和binaryOp数组
		for (i = 0; i < BOC; i++)
		{
			binaryFlag[i] = 0;
			binaryOp[i] = 0;
		}

		//清空unaryFlag数组和unaryOp数组
		for (i = 0; i < UOC; i++)
		{
		    unaryFlag[i] = 0;
		    unaryOp[i] = 0;
		}

		//清空输入缓冲区
		while('\n' != (cleanStdin = getchar()));
		printf("please input binary operator(no more than 10) \nor ternary operator(just '?')\nor unary operator(just '~')\nend with # and no repeated!!:\n");
		
		//循环获取输入,并根据用户的输入填充
		//binaryOp数组和unaryOp数组
		//设置binaryFlag和unaryFlag标志
		//设置flagUnaryOperator和flagTernaryOperator标志
		//遇到用户输入#退出循环
		for (;;)
		{
			//获取一个输入,并对输入进行截断
			scanf("%s", op);
			op[2] = 0;

			//{'*','/','%', '+','-', "<<",">>", '&', '^', '|'}
			//{1,2,3,4,5,6,7,8,9,10}
			if (0 == strcmp("*", op))
			{
				if (0 == binaryFlag[ 0])
				{
					binaryOp[0] = 1; 
					binaryFlag[0] = 1;
				}
				else
				{
					printf("repeated  operator!!please retry!!\n");
					goto retry;
				}
			}
			else if (0 == strcmp("/", op))
			{
				if (0 == binaryFlag[1] )
				{
					binaryOp[1] = 2; 
					binaryFlag[1] = 1;
				}
				else
				{
					printf("repeated  operator!!please retry!!\n");
					goto retry;
				}
			}
			else if (0 == strcmp("%", op))
			{
				if (0 == binaryFlag[2] )
				{
					binaryOp[2] = 3;
					binaryFlag[2] = 1;
				} 
				else
				{
					printf("repeated operator!!please retry!!\n");
					goto retry;
				}
			}
			else if (0 == strcmp("+", op))
			{
				if  (0 == binaryFlag[3])
				{
				 	binaryOp[3] = 4;
					binaryFlag[3] = 1;
				}
				else
				{
					printf("repeated operator!!please retry!!\n");
					goto retry;
				}
			}
			else if (0 == strcmp("-", op))
			{
				if (0 == binaryFlag [4])
				{
					binaryOp[4] = 5; 
					binaryFlag[4] = 1;
				}
				else
				{
	
					printf("repeated operator!!please retry!!\n");
					goto retry;
				}
			}
			else if (0 == strcmp("<<", op))
			{
				if (0 == binaryFlag [5])
				{
					binaryOp[5] = 6;
					binaryFlag[5] = 1;
				}
				else
				{
					printf("repeated operator!!please retry!!\n");
					goto retry;
				}
			}
			else if (0 == strcmp(">>", op))
			{
				if (0 == binaryFlag[6])
				{
					binaryOp[6] = 7;
					binaryFlag[6] = 1;
				}
				else
				{
					printf("repeated operator!!please retry!!\n");
					goto retry;
				}
			}
			else if (0 == strcmp("&", op))
			{
				if (0 == binaryFlag [7])
				{
					binaryOp[7] = 8;
					binaryFlag[7] = 1;
				}
				else
				{
					printf("repeate d operator!!please retry!!\n");
					goto retry;
				}
			}
			else if (0 == strcmp("^", op))
			{
				if (0 == binaryFlag[ 8])
				{
					binaryOp[8] = 9; 
					binaryFlag[8] = 1;
				}
				else
				{
					printf("repeate d operator!!please retry!!\n");
					goto retry;
				}
			}
			else if (0 == strcmp("|", op))
			{
				if (0 == binaryFlag[ 9])
				{
					binaryOp[9] = 10; 
					binaryFlag[9] = 1;
				}
				else
				{
					printf("repeated operator!!please retry!!\n");
					goto retry;
				}
			}
			else if (0 == strcmp("?", op))
			{
				if (0 == flagTernaryOperator) 
				{
					flagTernaryOperator = 1;
				}
				else
				{
					printf("repeated operator!!please retry!!\n");
					goto retry;
				}
			}
			else if (0 == strcmp("~", op))
			{
				if (0 == unaryFlag[0] ) 
				{
					flagUnaryOperator++;
					unaryFlag[0] = 1;
					unaryOp[i] = 1;
				}
				else
				{
					printf("repeated operator!!please retry!!\n");
					goto retry;
				}
			}
			else if (0 == strcmp("#", op))
			{
				break;
			}
			else
			{
					printf("error input!!please input again!!\n");
					goto retry;
			}
		}
	}

	return 0;
}

/**********************************************************
 * 函数原型 :
 *     int main(int argc, char* argv[])
 *
 * 函数功能 : 
 *     主函数,调用getInput()接收用户输入
 *     产生四个数据的排列
 *     并对每一种排列调用permutation()函数进行运算符遍历
 *
 * 参数列表 :
 *     IN :
 *         
 *     OUT:
 *	       
 *
 * 返回值   :
 *     0 
 * *******************************************************/
int main(int argc,char *argv[])
{
	int i = 0;                  //循环变量
	int j = 0;                  //循环变量
	int value[4] = {0};         //保存用户输入的四个数据
	int valueTemp[4] = {0};     //用户输出的数据副本,计算都使用这个数组
	int binaryOp[BOC] = {0};    //保存双目运算符标志
	int unaryOp[UOC+1] = {0};   //保存单目运算符标志

	//open log file
	fd = fopen("score.txt","w+");
	
	//获取用户输入
	getInput(value, unaryOp, binaryOp);

	//循环遍历每种情况
	for (i = 0; i < factorial(4); i++)
	{
	    //先将四个数据从value数组中拷贝到valueTemp数组
		for (j = 0; j < 4; j++)
		{
			valueTemp[j] = value[j];
		}
        
        //获取四个数据的排列
		getArray(valueTemp, 0, i);
		
		//获取运算符的排列
		permutation(valueTemp, unaryOp, binaryOp);
	}

	fprintf(stderr,"the hit result will save in score.txt\n");
    fclose(fd);
    return 0;
}
