#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	/*{//模板中的成员函数类内实现
		this->m_Name = name;
		this->m_Age = age;
	}*/

	void showPerson();
	/*{
		cout << "姓名：" << this->m_Name << "，年龄：" << this->m_Age << endl;
	}*/

	//友元函数类外实现
	//方法1：
	//template<class T1, class T2>//加这个模板声明，才是函数模板的声明，否则是普通函数的声明
	//friend ostream& operator<<(ostream& os, Person<T1,T2>& p);//友元函数可以直接访问类内的私有属性
	
	//方法2：
	//该方法不需要再加模板声明
	friend ostream& operator<< <T1,T2>(ostream& os, Person<T1, T2>& p);
private:
	T1 m_Name;
	T2 m_Age;
};

//template<class T1, class T2>
//Person::Person(T1 name, T2 age)
//{
//	this->m_Name = name;
//	this->m_Age = age;
//}//报错：使用类模板需要模板参数列表

template<class T1, class T2>
Person<T1,T2>::Person(T1 name, T2 age)//类模板产生的Person<T1,T2>具体模板类的作用域下
{
	this->m_Name = name;
	this->m_Age = age;
}

template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "姓名：" << this->m_Name << "，年龄：" << this->m_Age << endl;
}

//方法1：
//这是函数模板的实现
template<class T1, class T2>
ostream& operator<<(ostream& os, Person<T1, T2>& p)//friend ostream& operator<<(ostream& os, Person<T1,T2>& p);这是普通函数的友元声明
{
	os << "姓名：" << p.m_Name << "，年龄：" << p.m_Age;
	//操作符重载都是利用原有的操作符来对内置数据类型的运算，
	//以达到就好像是在使用原有的操作符来实现非内置数据类型的运算
	return os;
}

//方法2：
//这是函数模板的实现
template<class T1, class T2>
ostream& operator<< <T1,T2>(ostream& os, Person<T1, T2>& p)//friend ostream& operator<<(ostream& os, Person<T1,T2>& p);这是普通函数的友元声明
{
	os << "姓名：" << p.m_Name << "，年龄：" << p.m_Age;
	//操作符重载都是利用原有的操作符来对内置数据类型的运算，
	//以达到就好像是在使用原有的操作符来实现非内置数据类型的运算
	return os;
}
//编译器根据函数声明生成符号，再去找对应的函数。不一致，导致找不到：使得报错无法解析的外部符合
//方法1：
//在友元函数声明时，加一个模板template<class T1, class T2>//Windows下支持，但Linux下不支持
//方法2：
//在友元函数声明处，friend ostream& operator<< <T1,T2>(ostream& os, Person<T1, T2>& p)，Linux下测试一下
//方法3：空参数模板列表，提前声明函数模板，声明和实现分离。见“11 类模板碰到友元问题以及解决”
//方法4：空参数模板列表，提前声明函数模板，声明和实现一起。见“11 类模板碰到友元问题以及解决”
int main()
{
	Person<string, int> p("Tom", 10);
	//p.showPerson();
	cout << p << endl;
	return 0;
}