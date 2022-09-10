#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//�쳣�Ļ���
class BaseException
{
public:
	virtual void printError() = 0;
};

//��ָ���쳣
class NULLPointerException:public BaseException
{
public:
	void printError()
	{
		cout << "NULLPointerException�쳣" << endl;
	}
};

//Խ���쳣
class OutOfRangeException :public BaseException
{
public:
	void printError()
	{
		cout << "OutOfRangeException�쳣" << endl;
	}
};

void doWork()
{
	//throw NULLPointerException();
	throw OutOfRangeException();
}

void test()
{
	try
	{
		doWork();
	}
	catch (BaseException& e)//BaseException& e = OutOfRangeException();��������ָ���������
	{
		e.printError();
	}
}

int main()
{
	test();
	return 0;
}