#include "MyString.h"
//无参构造
MyString::MyString()
{
	this->len = 0;
	this->str = NULL;
}
//有参构造
MyString::MyString(const char* str)
{
	if (str == NULL)
	{
		this->len = 0;
		this->str = new char[0 + 1];
		strcpy(this->str, "");
	}
	else
	{
		int len = strlen(str);
		this->len = len;
		this->str = new char[len + 1];
		strcpy(this->str, str);
	}
}
//析构函数
MyString::~MyString()
{
	if (this->str != NULL)
	{
		cout << this->str << "执行了析构函数" << endl;
		delete this->str;
		this->str = NULL;
		this->len = 0;
	}
}
//初始化的时候调用的 - 拷贝构造
MyString::MyString(const MyString& another)
{
	this->len = another.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, another.str);
}

//重载<<
ostream& operator<<(ostream& os, MyString& s)
{
	os << s.str;
	return os;
}
//重载[]
char& MyString::operator[](int index)
{
	return this->str[index];
}
//重载=
MyString& MyString::operator=(const MyString& another)
{
	//判断自身比较
	if (this == &another)
	{
		return *this;
	}
	if (this->str != NULL)
	{
		delete[] this->str;
		this->str = NULL;
		this->len = 0;
	}
	//深拷贝
	this->len = another.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, another.str);

	return *this;
}
//重载>>
istream& operator>>(istream& is, MyString& s)
{
	//is >> s.str;//char *str = NULL;cin >> str;程序会崩溃
	
	//1、将s之前的字符串释放掉
	if (s.str != NULL)
	{
		delete[] s.str;
		s.str = NULL;
		s.len = 0;
	}
	//2、通过cin添加新的字符串
	char temp_str[4096] = { 0 };
	
	cin >> temp_str;

	int len = strlen(temp_str);
	s.str = new char[len + 1];
	strcpy(s.str, temp_str);
	s.len = len;
	return is;
}

//重载操作符+
MyString MyString::operator+(MyString& another)
{
	MyString temp;
	int len = this->len + another.len;
	temp.len = len;
	temp.str = new char[len + 1];
	memset(temp.str, 0, len + 1);
	strcat(temp.str, this->str);
	strcat(temp.str, another.str);
	return temp;
}