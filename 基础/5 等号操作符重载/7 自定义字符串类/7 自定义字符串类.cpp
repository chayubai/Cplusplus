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
//	s3 = s1;//����=
//	cout << s1 + s2 << endl;//����+������֧��-
//
//	s2[1] = 'X';//����[]
//	cout << s2 << endl;//����<<
//
//	if (s1 == s2)//����==
//	{
//
//	}
//	if (s1 != s2)//����!=
//	{
//
//	}
//	return 0;
//}