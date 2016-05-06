<pre>
这个文件夹下是测试cin.get()和cin.getline()的用法

1.get_letter_1.c
	这个代码测试了cin.get()读取一个字符的用法

2.get_letter_2.c
	这个代码测试了cin.get(buff)读取一个字符的用法

3.get_string_1.c
	本程序测试的是cin.get(buff,limit)当limit比sizeof(buff)小时的情况

4.get_string_2.c
	本程序测试的是cin.get(buff,limit)当limit比sizeof(buff)大时的情况

5.get_string_3.c
	本程序测试的是替换termimator之后的cin.get(buff,n,terminator)的用法

6.get_string_4.c
	这个代码测试了，当指定终结符后，读取的字符串超过申请的buff的长度时的用法

7.get_string_5.c
	本代码测试了，使用cin.get(buff，limit).get()来清空缓冲区遗留的\n的方法，不过这个方法有局限性，必须第一次get把所有的缓冲区内的数据都读取完了，否则后面的.get()并不能解决缓冲区\n的问题

8.get_string_6.c
	本代码测试了使用ignore()函数来解决cin.get()因为缓冲区遗留\n的问题

9.getline_string_1.c
	本程序测试的是cin.getline(buff,limit)当limit比sizeof(buff)小的时候的用法

10.getline_string_2.c
	本程序测试的是cin.getline(buff,limit)当limit比sizeof(buff)大的时候的用法

11.getline_string_3.c
	本程序测试的是cin.getline(buff,limit,terminator)，替换了默认输入字符串终结符时的用法

12.getline_string_4.c
	本代码测试了当getline读取过多字符出错的处理方法

</pre>
