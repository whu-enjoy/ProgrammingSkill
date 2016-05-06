/*=============================================================================
#
# Author        : enjoy5512
#
# E-mail        : enjoy5512@163.com
#
# Last modified : 2016-04-19 12:31
#
# Filename      : get_letter_2.cpp
#
# Description   : 这个代码测试了cin.get(buff)获取一个字符的用法
#
=============================================================================*/

#include<iostream>

using namespace std;

int main(int argc,char *argv[])
{
    char buff = 'n';

    cout<<"before the first input :"<<buff<<endl;
    cout<<"please input a char : ";
    cin.get(buff);
    cout<<"after the first input :"<<buff<<endl;

    cout<<"before the second input :"<<buff<<endl;
    cout<<"please input a char : ";
    cin.get(buff);
    cout<<"after the second input :"<<buff<<endl;

    cout<<"before the third input :"<<buff<<endl;
    cout<<"please input a char : ";
    cin.get(buff);
    cout<<"after the third input :"<<buff<<endl;

    return 0;
}
