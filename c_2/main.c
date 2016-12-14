/*************************************************************************
    > File Name       : main.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2016��12��09�� ������ 15ʱ16��03��
 ************************************************************************/

#include "main.h"

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
int do_calc_ternaryOperator(IN int value1, IN int value2, IN int value3)
{
	return value1?value2:value3;
}

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
int CallBack(int (*fun)(), ...)
{
	va_list argp;
	int op = 0;
	int value1 = 0;
	int value2 = 0;
	int value3 = 0;
	int result = 0;

	va_start(argp, fun); //����fun��ȡargp�ṹ��ƫ��

	//���ѡ��Ŀ����
	//��ڶ�������Ϊ�������־
	//����������Ϊ�μӼ��������
	//����do_calc_unaryOperator()�����Ĳ�����ʽ����fun
	if (fun == do_calc_unaryOperator)
	{
		op = va_arg(argp,int);
		value1 = va_arg(argp, int);
		result = fun(op, value1);
	}
	//���ѡ����Ŀ����
	//��ڣ�����������Ϊ�μӼ��������
	//����do_calc_ternaryOperator()�����Ĳ�����ʽ����fun
	else if (fun == do_calc_ternaryOperator)
	{
		value1 = va_arg(argp, int);
		value2 = va_arg(argp, int);
		value3 = va_arg(argp, int);
		result = fun(value1, value2, value3);
	}
	//������˫Ŀ����
	//��ڶ���������˫Ŀ�������־
	//�����ĸ�����Ϊ�μӼ��������
	//����do_calc_binaryOperator()�����Ĳ�����ʽ����fun
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
		OUT char str3[])
{
	sprintf(str3,"(%s %s %s)",str1, binaryOp_char[op], str2);
    return CallBack(do_calc_binaryOperator, op, value1, value2);
}

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
		IN int flag)
{
	char str1[80] = {0}; //���ڱ����ַ���
	char str2[80] = {0}; //���ڱ����ַ���
	char str3[80] = {0}; //���ڱ����ַ���
	char str4[80] = {0}; //���ڱ����ַ���
	int result1 = 0; //���ڱ��������
	int result2 = 0; //���ڱ��������
	int result3 = 0; //���ڱ��������
	int result4 = 0; //���ڱ��������
	int result = 0;  //���ڱ������ս��
	int i[8] = {0};  //ѭ������
	int count[8] = {0}; //ÿ��ѭ������,count[0]û��ʹ��
	
	//����ÿ��ѭ������(Ϊ��Ŀ���������+1)
	for (i[0] = 0; i[0] < 8; i[0]++)
	{
	    count[i[0]] = flagUnaryOperator+1;
	}
	
	//����ѭ��,���߸�λ�ÿ��Է��õ�Ŀ�����,
	//ÿ��λ�ÿ���ѡ��Ż��߷��ĸ���Ŀ�����
	//�ȶ����ȼ�����������ݱ���
	//Ȼ��Եڶ��μ�����������ݱ���
	//�ٶԶԵ����μ�����������ݱ���
	//�ٶԽ�����б���
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
                                
								//������
				                printf("%s = %d\n", str3, result);
								//�������������ֵ���,��������ļ�
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
		OUT char str4[])
{
    sprintf(str4, "%s ? %s : %s", str1, str2, str3);
    return CallBack(do_calc_ternaryOperator, value1, value2, value3);
}

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
		IN int binaryOp[])
{
    char str1[80] = {0}; //���ڱ����ַ���
    char str2[80] = {0}; //���ڱ����ַ���
    char str3[80] = {0}; //���ڱ����ַ���
    char str4[80] = {0}; //���ڱ����ַ���
    int result1 = 0; //���ڱ�����
    int result2 = 0; //���ڱ�����
    int result3 = 0; //���ڱ�����
    int result = 0;  //���ڱ������ս��
 	int i[8] = {0};  //ѭ������
	int count[7] = {0}; //ѭ������
	int op = 0; //��������־
	
	//����ѭ������Ϊ��Ŀ���������+1
	for (i[0] = 1; i[0] < 7; i[0]++)
	{
	    count[i[0]] = flagUnaryOperator+1;
	}
	
	//����˫Ŀ�������־����
	for (i[0] = 0; i[0] < BOC; i[0]++)
	{
	    op = binaryOp[i[0]];
		//���ĳ������Ԫ��Ϊ0,˵���û�û�и�����������
		//��������ѭ��
	    if (0 == op)
	    {
	        continue;
	    }

		//����Ŀ��������뵥Ŀ������������������б���
		//ÿ��ѭ�������ȶ�˫Ŀ��������������ݱ���
		//�ٶ���Ŀ��������������ݱ���
		//�ڶԽ�����б���
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
								//����Ŀ�����������������б���
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

									//������
                                    printf("%s = %d\n", str3, result);
									//���������ڸ�����ֵ,�򽫽�����浽�ļ�
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
	
	int i[4] = {0}; //ѭ������	
	int op_1 = 0;   //�����һ��˫Ŀ������ı�־
	int op_2= 0;    //����ڶ���˫Ŀ������ı�־
	int op_3 = 0;   //���������˫Ŀ������ı�־

	//����ֻ�е�Ŀ�������˫Ŀ����������
	//��Ϊһ������ڼ��뵥Ŀ����������������
	//���ԾͰ�˫Ŀ���������ϱ��������������
	//����ѭ����̫����
	//��������ѭ�����ڱ�������˫Ŀ�����������
	for (i[0] = 0; i[0] < BOC; i[0]++)
	{
		for (i[1] = 0; i[1] < BOC; i[1]++)
		{
			for (i[2] = 0; i[2] < BOC; i[2]++)
			{
			    op_1 = binaryOp[i[0]];
			    op_2 = binaryOp[i[1]];
			    op_3 = binaryOp[i[2]];

				//�������˫Ŀ���������һ����־Ϊ0
				//˵���û�û�и�����Ӧ��˫Ŀ�����
			    if (0==op_1 || 0==op_2 || 0==op_3)
			    {
				    continue;
			    }

                //����һ�����,�����ּ���˳��
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

	//��������Ŀ�����,˫Ŀ�����,��Ŀ����������
	//���flagTernaryOperatorΪ0,˵���û�û�и�����Ŀ�����
	//����ֱ�ӽ���������
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
 * ����ԭ�� :
 *     static
 *     int getArray(
 *             OUT int value[], 
 *             IN int basePOS, 
 *             IN int n)
 *
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
int getArray(OUT int value[], IN int basePos, IN int n)
{
	int tmp = 0;     //�����м�ֵ
	int i = 0;       //ѭ������
	int swapPos = 0; //��basePos��λ�����������ڵ�λ��

	if (basePos > 3) //ֻҪ��ǰ����λ������ȷ��,���о������
	{
		return 0;
	}

	//��ȡ��basePos��λ���ϵ��������ڵ�λ��
	swapPos = n/factorial(4-basePos-1)+basePos;

	//����ԭ����
	tmp = value[swapPos];

	//��basePos��swapPos֮��������������һ��λ��
	//����basePos���ǲ�����swapPos
	for (i = swapPos; i > basePos; i--)
	{
		value[i] = value[i-1];
	}

	//��swapPos�ϵ�ֵ����basePosλ�����basePos�ϵ�ֵ���滻
	value[basePos] = tmp;

	//�ݹ�����basePos���������
	getArray(value, basePos+1, n%factorial(4-basePos-1));

	return 0;
}

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
		OUT int binaryOp[])
{
	char op[3] = {0};           //�����û�����Ĳ�����
	int i = 0;                  //ѭ������
	int binaryFlag[BOC] = {0};  //����ָʾĳ��˫Ŀ������Ƿ��Ѿ�������
	int unaryFlag[UOC] = {0};   //����ָʾĳ����Ŀ������Ƿ��Ѿ�������
	char cleanStdin = '\0';     //����������뻺����
	
	//��ȡvalue[]
	printf("please input 4 value : ");
	for (i = 0; i < 4; i++)
	{
		scanf("%d", &value[i]);
	}

	//������뻺����
	while('\n' != (cleanStdin = getchar()));

	//��ȡT
	printf("please input T :");
	scanf("%d",&T);

	//ѭ����ȡ�û�����,ֱ���û�������ȷ��ʽ�����˳�ѭ��
	{
retry:
		//��flagUnaryOperator��flagBinaryOperator��0
		flagUnaryOperator = 0;
		flagTernaryOperator = 0;

		//���binaryFlag�����binaryOp����
		for (i = 0; i < BOC; i++)
		{
			binaryFlag[i] = 0;
			binaryOp[i] = 0;
		}

		//���unaryFlag�����unaryOp����
		for (i = 0; i < UOC; i++)
		{
		    unaryFlag[i] = 0;
		    unaryOp[i] = 0;
		}

		//������뻺����
		while('\n' != (cleanStdin = getchar()));
		printf("please input binary operator(no more than 10) \nor ternary operator(just '?')\nor unary operator(just '~')\nend with # and no repeated!!:\n");
		
		//ѭ����ȡ����,�������û����������
		//binaryOp�����unaryOp����
		//����binaryFlag��unaryFlag��־
		//����flagUnaryOperator��flagTernaryOperator��־
		//�����û�����#�˳�ѭ��
		for (;;)
		{
			//��ȡһ������,����������нض�
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
 * ����ԭ�� :
 *     int main(int argc, char* argv[])
 *
 * �������� : 
 *     ������,����getInput()�����û�����
 *     �����ĸ����ݵ�����
 *     ����ÿһ�����е���permutation()�����������������
 *
 * �����б� :
 *     IN :
 *         
 *     OUT:
 *	       
 *
 * ����ֵ   :
 *     0 
 * *******************************************************/
int main(int argc,char *argv[])
{
	int i = 0;                  //ѭ������
	int j = 0;                  //ѭ������
	int value[4] = {0};         //�����û�������ĸ�����
	int valueTemp[4] = {0};     //�û���������ݸ���,���㶼ʹ���������
	int binaryOp[BOC] = {0};    //����˫Ŀ�������־
	int unaryOp[UOC+1] = {0};   //���浥Ŀ�������־

	//open log file
	fd = fopen("score.txt","w+");
	
	//��ȡ�û�����
	getInput(value, unaryOp, binaryOp);

	//ѭ������ÿ�����
	for (i = 0; i < factorial(4); i++)
	{
	    //�Ƚ��ĸ����ݴ�value�����п�����valueTemp����
		for (j = 0; j < 4; j++)
		{
			valueTemp[j] = value[j];
		}
        
        //��ȡ�ĸ����ݵ�����
		getArray(valueTemp, 0, i);
		
		//��ȡ�����������
		permutation(valueTemp, unaryOp, binaryOp);
	}

	fprintf(stderr,"the hit result will save in score.txt\n");
    fclose(fd);
    return 0;
}
