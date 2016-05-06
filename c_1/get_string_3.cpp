/*=============================================================================
#
# Author        : enjoy5512
#
# E-mail        : enjoy5512@163.com
#
# Last modified : 2016-04-19 12:47
#
# Filename      : get_string_3.cpp
#
# Description   : 本程序测试的是替换termimator之后的cin.get(buff,n,terminator)
#                 的用法
#
=============================================================================*/

#include<iostream>

using namespace std;

int main(int argc,char *argv[])
{
    char buff[5] = "aaaa";

    cout<<"before the first input :"<<buff<<endl;
    cout<<"please input a string : ";
    cin.get(buff,3,'s');
    cout<<"after the first input :"<<buff<<endl;

    cout<<"before the second input :"<<buff<<endl;
    cout<<"please input a string : ";
    cin.get(buff,3,'s');
    cout<<"after the second input :"<<buff<<endl;

    cout<<"before the third input :"<<buff<<endl;
    cout<<"please input a string : ";
    cin.get(buff,3,'s');
    cout<<"after the third input :"<<buff<<endl;

    return 0;
}
