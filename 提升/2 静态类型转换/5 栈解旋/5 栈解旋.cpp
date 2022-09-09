#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class MyException
{
public:
	void printError()
	{
		cout << "���Լ����쳣" << endl;
	}
};

class Person
{
public:
	Person()
	{
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}

	~Person()
	{
		cout << "Person��������������" << endl;
	}
};

int myDivision(int a, int b)
{
	Person p1;//�ͷ�
	if (b == 0)
	{
		//��try����鿪ʼ����throw�׳��쳣֮ǰ������ջ�ϵ����ݶ��ᱻ�ͷŵ����ͷŵ�˳��͵��ù��캯����˳���෴
		//������̳�Ϊջ����
		Person p2;//�ͷ�

		throw MyException();//�׳�MyException����������
	}
	return a / b;
}
void test()
{
	int a = 10;
	int b = 0;
	try//����ִ�����´������Ƿ��쳣������쳣����д������û���쳣catch�δ����ǲ���ִ��
	{
		Person p3;//�ͷ�
		myDivision(a, b);
	}
	catch (int)//�����쳣�Ĳ���
	{
		cout << "int�����쳣����" << endl;
	}
	//ע�⣺���û����ȥ�����׳����쳣������ͻ���ֹ
	catch (char)
	{
		cout << "char�����쳣����" << endl;
	}
	catch (MyException e)//�Զ������͵��쳣����
	{
		e.printError();
	}
	catch (double)
	{
		throw;//�������쳣�����ǲ��봦�����������׳�����쳣
	}
	catch (...)//...������������
	{
		cout << "���������쳣����" << endl;
	}
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
