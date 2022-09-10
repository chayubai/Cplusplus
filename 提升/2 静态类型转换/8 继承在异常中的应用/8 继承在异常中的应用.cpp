#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//异常基类
class BaseException
{
public:
	virtual void what() = 0;
	virtual ~BaseException() {}
};

class TargetSpaceNullException :public BaseException
{
public:

	//1、继承exception基类
	//2、重载what函数和虚析构
	virtual void what()
	{
		cout << "目标空间为空！" << endl;
	}
	virtual ~TargetSpaceNullException()//触发多态析构
	{

	}
};
class SourceSpaceNullException :public BaseException
{
public:
	virtual void what()
	{
		cout << "源空间为空！" << endl;
	}
	virtual ~SourceSpaceNullException()
	{
	}
};
void copy_str(char* target, const char* source)
{
	if (target == NULL)
	{
		throw TargetSpaceNullException();
	}
	if (source == NULL)
	{
		throw SourceSpaceNullException();
	}
	int len = strlen(source) + 1;
	while (*source != '\0')
	{
		*target = *source;
		target++;
		source++;
	}
}
int main()
{
	const char* source = "abcdefg";
	char buf[1024] = { 0 };

	try
	{
		copy_str(buf, source);
	}
	catch (BaseException &ex)
	{
		ex.what();//这里what返回的是void
	}

	cout << buf << endl;

	return 0;
}