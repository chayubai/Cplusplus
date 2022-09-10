#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//Ϊexception�����ṩһ���µ����쳣��

#include <string>
//��exception�����£������µ����쳣��
class MyOutOfRangeException:public exception
{
public:

	//MyOutOfRangeException("...")
	MyOutOfRangeException(const char* str)
	{
		//const char* ����ֱ�Ӹ�string��ֵ
		this->m_errorInfo = str;//���Խ�const char* ��ʽ����ת��Ϊstring�����ǲ��ܽ�string��ʽת��Ϊconst char*
	}
	//����
	//MyOutOfRangeException(string("..."))
	MyOutOfRangeException(string str)
	{
		this->m_errorInfo = str;
	}

	//ת������鿴exception������Щ��Ҫ��д�ĳ�Ա��������virtual�ؼ��ֵĳ�Ա������Ҫ��д
	virtual char const* what() const//������const�ؼ��֣���������д(���˺�����ʣ��Ķ�Ҫһ��)��const��������thisָ�룬
	{
		//return m_errorInfo;//�������ܽ�stringֱ��תΪconst char*.��ν�stringתΪconst char*

		return m_errorInfo.c_str();//string���ڲ�����һ����Ա����c_str()�����Խ�stringתΪconst char*
	}

	virtual ~MyOutOfRangeException(){}

	string m_errorInfo;
};

#if 0
class MyOutOfRangeException :public exception
{
public:

	MyOutOfRangeException(const char* error)
	{
		this->m_errorInfo = new char[strlen(error)+1];//���Խ�const char* ��ʽ����ת��Ϊstring�����ǲ��ܽ�string��ʽת��Ϊconst char*
		strcpy(this->m_errorInfo, error);
	}
	~MyOutOfRangeException()
	{
		if (this->m_errorInfo)
		{
			delete[] this->m_errorInfo;
			this->m_errorInfo = NULL;
		}
	}
	//ת������鿴exception������Щ��Ҫ��д���麯��
	virtual char const* what() const//������const�ؼ��֣���������д��const��������thisָ�룬
	{
		return this->m_errorInfo;
	}

	char* m_errorInfo;
};
#endif

class Person
{
public:
	Person(int age)
	{
		if (age < 0 || age > 150)
		{
			//throw MyOutOfRangeException("���������0~150֮��");
			throw MyOutOfRangeException( string("���������0~150֮��") );//string("���������0~150֮��")��string�����������
		}
		else
		{
			this->m_Age = age;
		}
	}
	int m_Age;
};
void test()
{
	try
	{
		Person p(151);
	}
	//catch (MyOutOfRangeException& e)
	catch (exception& e)//��������ָ���������
	{//ע�⣺��û��ʵ�ֿ��������ʱ������ʹ��exception e��Ϊ�βν��н��գ��ᡰUnknown exception��
		cout << e.what() << endl;
	}
}

int main()
{
	test();
	return 0;
}