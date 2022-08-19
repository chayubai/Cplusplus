#include "MyString.h"
//无参构造
MyString::MyString()//MyString mystring;假设调用无参构造，字符串地址为空
{
	this->len = 0;
	this->str = NULL;//‘\0’== NULL 0字符或空指针  ""  == "\0" 空字符串
}
//有参构造 
MyString::MyString(const char* str)
{
	if (str == NULL)//char* c = NULL;MyString s(c);传入NULL,开辟一个空字符串
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
		//cout << this->str << "执行了析构函数" << endl;
		delete[] this->str;//这里需要delete数组
		this->str = NULL;
		this->len = 0;
	}
}
//初始化的时候调用的 没有垃圾 - 拷贝构造
MyString::MyString(const MyString& another)
{
	this->len = another.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, another.str);
}

//重载<<
ostream& operator<<(ostream& os, MyString& s)//注意：这个不需要作用域
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
istream& operator>>(istream& is, MyString& s)//这个不需要作用域
{
	//1、将s之前的字符串释放掉
	if (s.str != NULL)
	{
		delete[] s.str;
		s.str = NULL;
		s.len = 0;
	}
	//2、通过cin添加新的字符串

	//is >> s.str;//char *str = NULL;cin >> str;往空指针里面写数据，程序会崩溃
	//此时在上一步，s.str被置空了
	char temp_str[4096] = { 0 };
	
	cin >> temp_str;

	int len = strlen(temp_str);
	s.str = new char[len + 1];
	strcpy(s.str, temp_str);
	s.len = len;
	return is;
}

//重载操作符+
MyString MyString::operator+(MyString& another)//如果是MyString& 不能返回局部变量的引用
{
	MyString temp;
	int len = this->len + another.len;
	temp.len = len;
	temp.str = new char[len + 1];

	memset(temp.str, 0, len + 1);//清空，否则会往后面继续追加
	strcat(temp.str, this->str);
	//可以直接使用strcpy(temp.str, this->str)则可以不需要上一行代码

	strcat(temp.str, another.str);

	return temp;
}