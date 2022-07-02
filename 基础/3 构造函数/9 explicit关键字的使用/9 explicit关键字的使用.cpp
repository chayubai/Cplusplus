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
	//explicit关键字的作用：防止使用隐式法初始化对象
	//MyString str5 = 10;//"10"?这样的初始化会产生误解，explicit修饰起到防止使用隐式法初始化对象
	
	return 0;
}