#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <string>
class MyPrint
{
public:
	void operator()(string text)
	{
		cout << text << endl;
	}
};
void MyPrint2(string str)
{
	cout << str << endl;
}
void test1()
{
	MyPrint myPrint;
	myPrint("hello world");//�º���������������ص�()�������������һ������ͨ�������ֶ���Ϊ��������
	//ʹ�õ�ʱ��������ĵ��ã���˳�Ϊ�º���

	MyPrint2("hello world");//��ͨ����
}

class MyAdd
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};

void test2()
{
	MyAdd myAdd;
	cout << myAdd(1, 1) << endl;

	//()�����غ����

	cout << MyAdd()(1, 1) << endl;// MyAdd() - ��������������ڵ�()����������Գ�Ϊ�����ĺ�������
	//���������ص㣺��ǰ��ִ���������ͷţ��������ڷº���
}
int main()
{
	//test1();
	test2();
	return 0;
}








#if 0

class Sqr
{
public:
	Sqr(int a)
	{
		this->a = a;
	}
	int operator()(int value)
	{
		return value * value;
	}
	int operator()(int value1,int value2)
	{
		return value1 * value2;
	}
private:
	int a;
};
int main()
{
	Sqr s(10);
	int value = s(2);//s.operator()(2)
	//��һ�����󵱳���ͨ���������á������ֶ����Ƿº���/α����/��������
	cout << value << endl;
	value = s(10, 20);
	cout << value << endl;

	return 0;
}
#endif