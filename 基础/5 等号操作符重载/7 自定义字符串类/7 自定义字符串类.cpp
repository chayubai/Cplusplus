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
		this->name = name;//����string��Ŀ������캯��
	}
private:
	int a;
	string name;//name��string��Ķ���
};

#if 0
int main()
{
	string s1 = "123";//��string s1("123");�����вι���
	string s2 = "abc";
	string s3(s2);//string��֧������� - ��������
	s3 = s1;//string��֧��������=
	cout << s1 + s2 + s1 << endl;//string��֧��������+������֧��-
	//s1 + s2 ������������
	s2[1] = 'X';//string��֧��������[]
	cout << s2 << endl;//string��֧��������<<

	if (s1 == s2)//string��֧��������==
	{

	}
	if (s1 != s2)//string��֧��������!=
	{

	}
	return 0;
}
#endif