#define _CRT_SECURE_NO_WARNINGS 1

//1、Linux下,index.cpp中编写代码
#include <iostream>
using namespace std;

#define MAX 1024

int main()
{
	cout << MAX << endl;

	return 0;
}
//2、预编译(器)
//	g++ -E index.cpp -o index.i//-o输出文件
//	查看vim index.i的代码最后
//	预定义代码中的MAX被替换成1024

//3、编译(器)
//	g++ -S index.i -o index.s
//	查看vim index.s的代码

//4、汇编(器)
//	g++ -c index.s -o index.o
//	查看vim index.o的代码

//5、链接(器)
//	g++ index.s -o index
//	file index	可知为executale
//	./index	执行