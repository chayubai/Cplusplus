#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <fstream>//文件流

#include <string>

void test1()
{
	const char* fileName1 = "D:\\VS2019\\C++code\\C++code\\Cplusplus\\提升\\1 静态类型转换\\14 文本文件操作\\source.txt";
	const char* fileName2 = "D:\\VS2019\\C++code\\C++code\\Cplusplus\\提升\\1 静态类型转换\\14 文本文件操作\\target.txt";
	
	//读文件 -- 从文件中读取到程序
	ifstream ifs(fileName1, ios::in);
	//写文件 -- 从程序中输出到文件中
	ofstream ofs(fileName2, ios::out | ios::trunc);//ios::app往文件里面追加内容

	if (!ifs)
	{
		cout << "文件打开失败" << endl;
		return;
	}

	char c;
	while ((ifs.get(c)))
	{
		cout << c;
		ofs.put(c);
	}

	//关闭文件
	ifs.close();
	ofs.close();
}

int main()
{
	test1();
	return 0;
}