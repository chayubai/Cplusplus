#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class MyException
{
public:
	MyException(const char* str)
	{
		error = new char[strlen(str) + 1];
		strcpy(error, str);
	}
	MyException(const MyException& ex)
	{
		error = new char[strlen(ex.error) + 1];
		strcpy(error, ex.error);
	}
	MyException& operator=(const MyException& ex)
	{
		if (error != NULL)
		{
			delete[] error;
			error = NULL;
		}

		error = new char[strlen(ex.error) + 1];
		strcpy(error, ex.error);

		return *this;
	}
	void printError()
	{
		cout << "�쳣��Ϣ��" << error << endl;
	}
	~MyException()
	{
		if (error != NULL)
		{
			delete[] error;
			error = NULL;
		}
	}
public://�����Ժ���Ϊ����
	char* error;
};

int myDivision(int a, int b)
{
	if (b == 0)
	{
		//�׳����쳣�������ͣ������ϸ�ƥ��
		//throw ����;	�׳����������͵��쳣
		//throw -1;		//-1����int���ͣ�Ҳ����������int���ݡ���ʾ�׳�int���͵��쳣
		//throw 'a';	//�׳�char���͵��쳣
		//throw 3.14;	//�׳�double���͵��쳣
		//...
		//throw "abc";	//�׳�char*���͵��쳣
		/*
		string str = "abc";
		throw str;
		*/				//�׳�string���͵��쳣

		throw MyException("�Լ�д���쳣");//�׳�MyException����������
	}
	return a / b;
}
void test()
{
	int a = 10;
	int b = 0;
	try
	{
		myDivision(a, b);
	}
	catch (int)
	{
		cout << "int�����쳣����" << endl;
	}
	catch (char)
	{
		cout << "char�����쳣����" << endl;
	}
	catch (MyException e)//�Զ������͵��쳣����������������e�����ÿ������캯��
	{//���������������error���β�e���error��ָ��ͬһ��ռ䡣��������ؿ������캯��������������������e������
		//��ͬһ��ռ��ͷ����Σ��ͻ�������

		//���ɣ�ע�⣺�����������Ҫ�õ�������=��ֵ����ðѿ��������=��ֵ��������������ʵ�ֺ�
		e.printError();
	}
	/*catch (double)
	{
		throw;//�������쳣�����ǲ��봦�����������׳�����쳣
	}
	catch (...)//...������������
	{
		cout << "���������쳣����" << endl;
	}*/
}
int main()
{
	try
	{
		test();
	}
	catch (double)
	{
		cout << "main������ double�����쳣����" << endl;
	}
	catch (...)
	{
		cout << "main������ ���������쳣����" << endl;
	}
	
	return 0;
}