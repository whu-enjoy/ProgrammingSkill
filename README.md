<pre>
这里面是一些编程技巧方面的东西，用于测试一些函数的用法之类的

1. struct_translate.c
	这个代码解释了结构体和结构体指针在作为函数参数时的用法
	DNode* testPoint(DNode **Node) 这个函数输入的是二级结构体指针，所以对这个结构体的引用，修改会同步到原结构体指针，如果只采用一级指针，则在本函数体内得到的只是原结构体指针的一个副本，所有对结构体指针的修改不会影响到原结构体指针
	DNode test(DNode *Node) 这个函数输入的是结构体，如果输入的是结构体，而不是结构体指针，则对结构体的修改不会影响到原结构体
	void Destroy(DNode *Node) 这个函数用于释放动态分配的结构体所在的内存，原结构体还是保留着对这个内存的引用，所以记得在释放结构体的时候把指针指向NULL因为这里只修改结构体，不修改结构体指针，所以用了一级指针

2. c_1
	这个文件夹下测试了get和getline的用法

3. c_2
	这个函数是帮学姐做的密码学的一个题,用户给定单目,双目,三目运算符,和四个参与计算的数,遍历出所有跟给定值相等的组合

4. acm
	这个是程序设计训练里面做的题
</pre>
