#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Test
{
public:
	Test(int a, int b)
	{
		//为了防止产生阅读歧义，使用this指针区别
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
	//2、局部的成员函数
	Test TestAdd1(Test& another)
	{
		//同类中之间（this和another）无私处
		Test temp(this->a + another.a, this->b + another.b);
		return temp;
	}

	//3、+=方法
	void TestAdd2(Test& another)
	{
		this->a += another.a;
		this->b += another.b;
	}
	//连+=
	/*
	Test TestAdd3(Test& another)
	{
		this->a += another.a;
		this->b += another.b;
		return *this;//Test tmp = *this;
		//t1.TestAdd3(t2).TestAdd3(t2);
		//第一次t1.TestAdd3(t2)返回的了是tmp
		//第二次tmp.TestAdd3(t2)
	}
	*/
   	Test& TestAdd3(Test& another)
	{
		this->a += another.a;
		this->b += another.b;
		return *this;//如果想要返回一个对象的本身，在成员方法中，返回用*this
	}
private:
	int a;
	int b;
};

//1、在全局提供一个“两个Test相加的函数”
Test TestAdd1(Test& t1, Test& t2)
{
	Test t(t1.getA() + t2.getA(), t1.getB() + t2.getB());
	return t;//调用拷贝构造函数，Test tmp = t;
}

void test1()
{
	//1、
	Test t1(10, 20);
	Test t2(100, 200);

	Test t3 = TestAdd1(t1, t2);//Test t3 = tmp;

	t3.printT();
}

void test2()
{
	//2、
	Test t1(10, 20);
	Test t2(100, 200);

	Test t3 = t1.TestAdd1(t2);
	t3.printT();
}

void test3()
{
	//3、t1 += t2
	Test t1(10, 20);
	Test t2(100, 200);

	t1.TestAdd2(t2);
	t1.printT();
}

void test4()
{
	Test t1(10, 20);
	Test t2(100, 200);

	//如果想对一个对象连续调用成员方法，每次都会改变对象本身，成员方法需要返回引用。
	//4、(t1 += t2) += t2
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