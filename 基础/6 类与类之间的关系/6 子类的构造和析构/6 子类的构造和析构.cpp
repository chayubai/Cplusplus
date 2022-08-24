#define _CRT_SECURE_NO_WARNINGS 1
 
#include <iostream>
using namespace std;
class Parent
{
public:
	Parent()
	{
		cout << "Parent()..." << endl;
		a = 0;
	}
	Parent(int a)
	{
		cout << "Parent(int a)..." << endl;
		this->a = a;
		
	}
	~Parent()
	{
		cout << "~Parent()..." << endl;
	}
	int a;
};

class Child:public Parent
{
public:

	//子类对象创建的时候，父类先构造，子类后构造
	
	//在构造子类对象的时候，默认一定会调用父类的默认构造方法
	//如果只定义父类的有参构造，不定义父类的默认构造，就会报错，因为不知道怎么构造父类
	//或者使用参数列表，调用父类的有参构造初始化

	//注意：父类中的属性是public，才能在子类直接初始化
	Child(int a,int b)//:Parent(10)
	{
		cout << "Child(int a,int b)..." << endl;
		this->a = a;//一般而言，类的属性是谁的，就用谁的构造函数初始化
		this->b = b;
	}
	void printC()
	{
		cout << "b = " << b << endl;
	}
	~Child()
	{
		cout << "~Child()..." << endl;
	}
	int b;
};
int main()
{
	Child c(10, 20);
	c.printC();
	return 0;
}