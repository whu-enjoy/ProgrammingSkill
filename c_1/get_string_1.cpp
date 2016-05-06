/*=============================================================================
#
# Author        : enjoy5512
#
# E-mail        : enjoy5512@163.com
#
# Last modified : 2016-04-19 12:32
#
# Filename      : get_string_1.cpp
#
# Description   : 本程序测试的是cin.get(buff,limit)当limit比sizeof（buff）小时
#				  的情况
#
=============================================================================*/

#include<iostream>

using namespace std;

int main(int argc,char *argv[])
{
    char buff[5] = "aaaa";

    cout<<"before the first input :"<<buff<<endl;
    cout<<"please input a string : ";
    cin.get(buff,3);
    cout<<"after the first input :"<<buff<<endl;

    cout<<"before the second input :"<<buff<<endl;
    cout<<"please input a string : ";
    cin.get(buff,3);
    cout<<"after the second input :"<<buff<<endl;

    cout<<"before the third input :"<<buff<<endl;
    cout<<"please input a string : ";
    cin.get(buff,3);
    cout<<"after the third input :"<<buff<<endl;

    return 0;
}
