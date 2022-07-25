#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Test
{
public:
	Test(int a, int b)
	{
		//Ϊ�˷�ֹ�����Ķ����壬ʹ��thisָ������
		this->a = a;
		this->b = b;
	}
	void printT()
	{
		cout << "a = " << this->a << ",b = " << this->b << endl;
	}
	int getA()
	{
		return this->a;
	}
	int getB()
	{
		return this->b;
	}
	//2���ֲ��ĳ�Ա����
	Test TestAdd1(Test& another)
	{
		//ͬ����֮�䣨this��another����˽��
		Test temp(this->a + another.a, this->b + another.b);
		return temp;
	}

	//3��+=����
	void TestAdd2(Test& another)
	{
		this->a += another.a;
		this->b += another.b;
	}
	//��+=
	/*
	Test TestAdd3(Test& another)
	{
		this->a += another.a;
		this->b += another.b;
		return *this;//Test tmp = *this;
		//t1.TestAdd3(t2).TestAdd3(t2);
		//��һ��t1.TestAdd3(t2)���ص�����tmp
		//�ڶ���tmp.TestAdd3(t2)
	}
	*/
   	Test& TestAdd3(Test& another)
	{
		this->a += another.a;
		this->b += another.b;
		return *this;//�����Ҫ����һ������ı����ڳ�Ա�����У�������*this
	}
private:
	int a;
	int b;
};

//1����ȫ���ṩһ��������Test��ӵĺ�����
Test TestAdd1(Test& t1, Test& t2)
{
	Test t(t1.getA() + t2.getA(), t1.getB() + t2.getB());
	return t;//���ÿ������캯����Test tmp = t;
}

void test1()
{
	//1��
	Test t1(10, 20);
	Test t2(100, 200);

	Test t3 = TestAdd1(t1, t2);//Test t3 = tmp;

	t3.printT();
}

void test2()
{
	//2��
	Test t1(10, 20);
	Test t2(100, 200);

	Test t3 = t1.TestAdd1(t2);
	t3.printT();
}

void test3()
{
	//3��t1 += t2
	Test t1(10, 20);
	Test t2(100, 200);

	t1.TestAdd2(t2);
	t1.printT();
}

void test4()
{
	Test t1(10, 20);
	Test t2(100, 200);

	//������һ�������������ó�Ա������ÿ�ζ���ı��������Ա������Ҫ�������á�
	//4��(t1 += t2) += t2
	t1.TestAdd3(t2).TestAdd3(t2);
	t1.printT();
}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}