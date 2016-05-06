/*=============================================================================
#
# Author        : enjoy5512
#
# E-mail        : enjoy5512@163.com
#
# Last modified : 2016-05-06 15:07
#
# Filename      : get_string_5.cpp
#
# Description   : 本代码测试了，使用cin.get(buff，limit).get()来清空缓冲区遗留的\n的方法，不过这个方法有局限性，必须第一次get把所有的缓冲区内的数据都读取完了，否则后面的.get()并不能解决缓冲区\n的问题
#
=============================================================================*/

#include<iostream>

using namespace std;

int main(int argc,char *argv[])
{
    char buff[5] = "aaaa";

    cout<<"before the first input :"<<buff<<endl;
    cout<<"please input a string : ";
    cin.get(buff,3).get();
    cout<<"after the first input :"<<buff<<endl;

    cout<<"before the second input :"<<buff<<endl;
    cout<<"please input a string : ";
    cin.get(buff,3).get();
    cout<<"after the second input :"<<buff<<endl;

    cout<<"before the third input :"<<buff<<endl;
    cout<<"please input a string : ";
    cin.get(buff,3).get();
    cout<<"after the third input :"<<buff<<endl;

    return 0;
}
