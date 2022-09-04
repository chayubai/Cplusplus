#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

template<class T>
class Base
{
public:
	T m_A;
};

//由于子类继承父类的时候，也继承了T m_A;
//当创建该类型的对象时，由于不知道T的数据类型是多大，导致父类对象和子类对象无法分配内存，导致报错
//class Son :public Base{};//报错
//必须要指定出父类中的T的数据类型，才能给子类分配内存，即在继承的父类后面显式声明T的类型
class Son :public Base<int>//但是这样写死了，无法实现通用化
{

};//类模板派生普通类

template<class T>
class Base2
{
public:
	T m_A;
};

template<class T1,class T2>
class Son2 :public Base2<T2>
{
public:
	Son2()
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
	T1 m_B;
};//类模板派生类模板

int main()
{
	Son s1;//Son类不是模板类
	Son2<int, double> s;//即m_B的类型是int,m_A的类型是double	Son2类是模板类
	return 0;
}