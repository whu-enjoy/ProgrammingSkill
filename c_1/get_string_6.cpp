/*=============================================================================
#
# Author        : enjoy5512
#
# E-mail        : enjoy5512@163.com
#
# Last modified : 2016-05-06 15:38
#
# Filename      : get_string_6.cpp
#
# Description   : 本代码测试了使用ignore()函数来解决cin.get()因为缓冲区遗留\n的问题
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
    cout<<"cin.fail():"<<cin.fail()<<endl;  
    cout<<"cin.eof():"<<cin.eof()<<endl;  
    cout<<"cin.bad():"<<cin.bad()<<endl;  
    cout<<"cin.good:"<<cin.good()<<endl;  
    cin.clear();
    cin.ignore(1,'\n');
    cout<<"cin.fail():"<<cin.fail()<<endl;  
    cout<<"cin.eof():"<<cin.eof()<<endl;  
    cout<<"cin.bad():"<<cin.bad()<<endl;  
    cout<<"cin.good:"<<cin.good()<<endl;  
    cout<<"after the first input :"<<buff<<endl;

    cout<<"before the second input :"<<buff<<endl;
    cout<<"please input a string : ";
    cin.get(buff,3);
    cin.clear();
    cin.ignore(1,'\n');
    cout<<"after the second input :"<<buff<<endl;

    cout<<"before the third input :"<<buff<<endl;
    cout<<"please input a string : ";
    cin.get(buff,3);
    cin.clear();
    cin.ignore(1,'\n');
    cout<<"after the third input :"<<buff<<endl;

    return 0;
