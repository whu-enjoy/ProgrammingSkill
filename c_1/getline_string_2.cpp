/*=============================================================================
#
# Author        : enjoy5512
#
# E-mail        : enjoy5512@163.com
#
# Last modified : 2016-04-19 12:52
#
# Filename      : getline_string_2.cpp
#
# Description   : 本程序测试的是cin.getline(buff,limit)limit比sizeof(buff)大时
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
    cin.getline(buff,7);
    cout<<"after the first input :"<<buff<<endl;

    cout<<"before the second input :"<<buff<<endl;
    cout<<"please input a string : ";
    cin.getline(buff,7);
    cout<<"after the second input :"<<buff<<endl;

    cout<<"before the third input :"<<buff<<endl;
    cout<<"please input a string : ";
    cin.getline(buff,7);
    cout<<"after the third input :"<<buff<<endl;

    return 0;
}
