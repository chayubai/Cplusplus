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
		this->name = name;
	}
private:
	int a;
	string name;
};

//int main()
//{
//	string s1 = "123";//s1("123");
//	string s2 = "abc";
//	string s3(s2);
//	s3 = s1;//重载=
//	cout << s1 + s2 << endl;//重载+，但不支持-
//
//	s2[1] = 'X';//重载[]
//	cout << s2 << endl;//重载<<
//
//	if (s1 == s2)//重载==
//	{
//
//	}
//	if (s1 != s2)//重载!=
//	{
//
//	}
//	return 0;
//}