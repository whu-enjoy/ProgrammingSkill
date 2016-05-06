/*=============================================================================
#
# Author        : enjoy5512
#
# E-mail        : enjoy5512@163.com
#
# Last modified : 2016-05-06 15:02
#
# Filename      : get_string_4.cpp
#
# Description   : 这个代码测试了，当指定终结符后，读取的字符串超过申请的buff的长度时的用法
#
=============================================================================*/

#include<iostream>

using namespace std;

int main(int argc,char *argv[])
{
    char buff[5] = "aaaa";

    cout<<"before the first input :"<<buff<<endl;
    cout<<"please input a string : ";
    cin.get(buff,7,'s');
    cout<<"after the first input :"<<buff<<endl;

    cout<<"before the second input :"<<buff<<endl;
    cout<<"please input a string : ";
    cin.get(buff,7,'s');
    cout<<"after the second input :"<<buff<<endl;

    cout<<"before the third input :"<<buff<<endl;
    cout<<"please input a string : ";
    cin.get(buff,7,'s');
    cout<<"after the third input :"<<buff<<endl;

    return 0;
}
