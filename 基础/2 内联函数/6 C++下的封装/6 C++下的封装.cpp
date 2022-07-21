#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

struct Person1
{
	//struct类型不写控制权限， 默认public控制权限
	char name[64];
	int age;
	void PersonEating()
	{
		cout << name << "正在吃饭" << endl;
	}
};

struct Dog1
{
public:
	char name[64];
	int age;
	void DogEating()
	{
		cout << name << "正在狗粮" << endl;
	}
};

class Person2
{
public:	//class不写控制权限，默认private控制权限
	char name[64];
	int age;
	void PersonEating()
	{
		cout << name << "正在吃饭" << endl;

	}
};

class Dog2
{
public:
	char name[64];
	int age;
	void DogEating()
	{
		cout << name << "正在狗粮" << endl;
	}
};
void test1()
{
	Person1 p;
	strcpy(p.name, "张三");
	p.PersonEating();

	Dog1 d;
	strcpy(d.name, "旺财");
	d.DogEating();

	Person1 p2;
	strcpy(p2.name, "李四");
	//p2.DogEating();//非结构体类型的变量无法访问结构体内的成员
}
void test2()
{
	Person2 p;
	//私有权限不可访问
	//strcpy(p.name, "张三");
	//p.PersonEating();

	Dog2 d;
	strcpy(d.name, "旺财");
	d.DogEating();

	Dog2 d2;
	strcpy(d2.name, "来福");
	//d2.PersonEating();//非类的对象无法访问类内的成员
}
//C++封装理念：
//1、将属性和行为作为一个整体，来表现生活中的事物
//2、将属性和行为，加以权限控制，有严格的类型转换

//struct 和class区别？
//1、class默认权限是私有权限，struct默认是公共权限
//2、访问权限：
//public:对象可以在类内和类外都能访问成员
//private:对象可以在类内访问成员，类外无法访问成员，子类不可以访问父类private权限
//protected:对象可以在类内访问成员，类外无法访问成员，子类可以访问父类protected权限
//private和protected主要在类的继承时有区别

#include <string>
class Person3
{
public:
	string m_name;
protected:
	string m_Car;
private:
	int m_pwd;
	void func()
	{
		m_name = "zhangsan";//"zhangsan"为const char*类型，隐式转换为string类型 
		m_Car = "拖拉机";
		m_pwd = 123456;
	}
};

void test3()
{
	Person3 p3;
	p3.m_name = "lisi";//类外可访问。
	//p3.m_Car = "劳斯莱斯";//类外不可访问
	//p3.m_pwd = 888888;//类外不可访问
}
int main()
{
	//test1();
	//test2();
	return 0;
}