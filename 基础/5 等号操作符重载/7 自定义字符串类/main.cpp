#define _CRT_SECURE_NO_WARNINGS 1

#include "MyString.h"

int main()
{
#if 0
	MyString s1("abc");//有参构造
	MyString s2(s1);//拷贝构造
	MyString s3 = "123";

	cout << s1 << endl;
	cout << s2 << endl;

	s1[1] = 'X';//重载[]
	cout << s1 << endl;

	s1 = s3;//重载=
	cout << s1 << endl;

	cin >> s1;
	cout << s1 << endl;
#endif

#if 0
	MyString s4("abc");
	cin >> s4;
	cout << s4 << endl;
#endif

	MyString s1("123");
	MyString s2("456");
	MyString s = s1 + s2 + s1;//s1 + s2 调用拷贝构造返回临时对象，返回匿名对象
	
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s << endl;

	//cout << (s1 + s2 + s1) << endl;//报错，为什么？
	return 0;
}