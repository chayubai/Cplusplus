#define _CRT_SECURE_NO_WARNINGS 1

//文件流类和文件流对象
//iostream同时管输入输出的类
//istream管输入的类				ostream管输出的类
//ifstream管文件输入的类		ofstream管文件输出的类
//fsteam同时管文件输入输出的类

#include <iostream>
using namespace std;

#include <fstream>//文件流

#include <string>

void test1()
{
	//写文件 --输出  程序中输出到文件
	ofstream ofs;//ofstream ofs("./test.txt", ios::out | ios::trunc);

	ofs.open("./test.txt", ios::out | ios::trunc);//设置打开方式，以及路径

	if (!ofs.is_open())//或者直接使用!ofs
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//ofstream类中重载了<<操作符
	ofs << "姓名：孙悟空" << endl;//向文件写内容
	ofs << "年龄：999" << endl;
	ofs << "性别：男" << endl;

	//关闭文件
	ofs.close();
}

void test2()
{
	//读文件 --输入 - 从文件读入到程序
	
	ifstream ifs;
	ifs.open("./test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//第一种方式：
	/*char buf[1024] = { 0 };
	//ifstream类重载了>>操作符
	while (ifs >> buf)//将读到的数据一行一行的输入到buf中
	{
		cout << buf << endl;//读一行输出一行
	}*/

	//第二种方式：
	/*char buf[1024] = {0};

	while (ifs.getline(buf,sizeof(buf)))//将读到的数据一行一行的输入到buf中 - 成员函数
	{
		cout << buf << endl;
	}
	或者
	while (!ifs.eof())//eof 读到文件尾
	{
		ifs.getline(buf,sizeof(buf))//不是strlen
		cout << buf << endl;
	}
	*/

	//第三种方式：
	/*string buf;

	while (getline(ifs,buf))//将读到的数据一行一行的输入到buf中 - 全局函数
	{
		cout << buf << endl;
	}*/

	//第四种方式：
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}
	//或者
	/*while ((ifs.get(c)))
	{
		cout << c;
	}*/

	//关闭文件
	ifs.close();
}

int main()
{
	//test1();
	test2();
	return 0;
}