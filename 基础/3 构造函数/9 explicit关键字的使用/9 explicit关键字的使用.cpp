#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class MyString
{
public:
	MyString(const char * str)
	{

	}
	explicit MyString(int len)
	{

	}
};
int main()
{
	MyString str("abcd");
	MyString str2 = "abcde";
	MyString str3(10);
	MyString str4 = MyString(10);
	//explicit�ؼ��ֵ����ã���ֹʹ����ʽ����ʼ������
	//MyString str5 = 10;//"10"?�����ĳ�ʼ���������⣬explicit�����𵽷�ֹʹ����ʽ����ʼ������
	
	return 0;
}