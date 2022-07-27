#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

#include <string>

using namespace std;

class Test
{
public:
	Test(int a, string name)
	{
		this->a = a;
		this->name = name;//调用string类的拷贝构造函数
	}
private:
	int a;
	string name;//name是string类的对象
};

#if 0
int main()
{
	string s1 = "123";//即string s1("123");调用有参构造
	string s2 = "abc";
	string s3(s2);//string类支持了深拷贝 - 拷贝构造
	s3 = s1;//string类支持了重载=
	cout << s1 + s2 + s1 << endl;//string类支持了重载+，但不支持-
	//s1 + s2 返回匿名对象
	s2[1] = 'X';//string类支持了重载[]
	cout << s2 << endl;//string类支持了重载<<

	if (s1 == s2)//string类支持了重载==
	{

	}
	if (s1 != s2)//string类支持了重载!=
	{

	}
	return 0;
}
#endif