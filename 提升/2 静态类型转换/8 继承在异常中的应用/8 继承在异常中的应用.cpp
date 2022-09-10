#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//�쳣����
class BaseException
{
public:
	virtual void what() = 0;
	virtual ~BaseException() {}
};

class TargetSpaceNullException :public BaseException
{
public:

	//1���̳�exception����
	//2������what������������
	virtual void what()
	{
		cout << "Ŀ��ռ�Ϊ�գ�" << endl;
	}
	virtual ~TargetSpaceNullException()//������̬����
	{

	}
};
class SourceSpaceNullException :public BaseException
{
public:
	virtual void what()
	{
		cout << "Դ�ռ�Ϊ�գ�" << endl;
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
		ex.what();//����what���ص���void
	}

	cout << buf << endl;

	return 0;
}