#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/*                       公共继承                     */

class Base1
{
	//控制访问权限
public:
	int m_A;//在本类的内部和外部都可以访问
protected:
	int m_B;//在本类的内部可以访问，在类的外部不可以访问
private:
	int m_C;//在本类的内部可以访问，在类的外部不可以访问
};

class Son1:public Base1//以public方式继承父类
{
public:
	void func()
	{
		m_A = 100;//父类Base1中公共权限，子类Son1中m_A仍为 公共权限，公共权限下子类Son1内可以访问
		m_B = 100;//父类Base1中保护权限，子类Son1中m_B仍为 保护权限，保护权限下子类Son1内可以访问
		//m_C = 100;//父类中私有成员，子类Son1内不可见
	}
};

void test1()
{
	Son1 s1;
	s1.m_A = 100;//在Son1中 m_A是公共权限，公共权限下子类Son1外可以访问
	//s1.m_B = 100;//在Son1中 m_B是保护权限，保护权限下子类Son1外不可以访问
	//s1.m_C = 100;//父类中私有成员，子类Son1外不可见
}

/*                       保护继承                     */

class Base2
{
public:
	int m_A;//在类的内部和外部都可以访问
protected:
	int m_B;//在类的内部可以访问，在类的外部不可以访问
private:
	int m_C;//在类的内部可以访问，在类的外部不可以访问
};

class Son2 :protected Base2//以protected方式继承父类
{
public:
	void func()
	{
		m_A = 100;//父类Base2中公共权限，子类Son2中m_A变为 保护权限，保护权限下子类Son2内可以访问
		m_B = 100;//父类Base2中保护权限，子类Son2中m_B仍为 保护权限，保护权限下子类Son2内可以访问
		//m_C = 100;//父类中私有成员，子类Son2内不可见
	}
};

void test2()
{
	Son2 s2;
	//s2.m_A = 100;//在Son2中 m_A是保护权限，保护权限下子类Son2外不可以访问
	//s2.m_B = 100;//在Son2中 m_B是保护权限，保护权限下子类Son2外不可以访问
	//s2.m_C = 100;//父类中私有成员，子类Son2外不可见
}

/*                       私有继承                     */

class Base3
{
public:
	int m_A;//在类的内部和外部都可以访问
protected:
	int m_B;//在类的内部可以访问，在类的外部不可以访问
private:
	int m_C;//在类的内部可以访问，在类的外部不可以访问
};

class Son3 :private Base3//以private方式继承父类
{
public:
	void func()
	{
		m_A = 100;//父类Base3中公共权限，子类Son3中m_A变为 私有权限，私有权限下子类Son3内可以访问
		m_B = 100;//父类Base3中保护权限，子类Son3中m_B变为 私有权限，私有权限下子类Son3内可以访问
		//m_C = 100;//父类中私有成员，子类Son3内不可见
	}
};

void test3()
{
	Son3 s3;
	//s3.m_A = 100;//在Son3中 m_A是私有权限，私有权限下类外不可以访问
	//s3.m_B = 100;//在Son3中 m_B是私有权限，私有权限下类外不可以访问
	//s3.m_C = 100;//父类中私有成员，子类Son3外不可见
}

class GrandSon3 :public Son3
{
public:
	void func()
	{
		//m_A = 100;//在Son3中 m_A已经变为私有权限，私有权限下子类GrandSon3内外均不可访问
		//m_B = 100;//在Son3中 m_B已经变为私有权限，私有权限下子类GrandSon3内外均不可访问
		//m_C = 100;//父类中私有成员，子类GrandSon3内外均不可见
	}
};

//注意：父类的私有属性，是可以被继承的，只是访问不到
//注意：访问权限和继承方式的区别
//1、访问权限 是本类对象对其属性或方法的访问进行控制的权限
//2、继承方式 是类和类之间，继承方式不同，子类继承的父类属性后，本类对象的访问权限也不同

//注意：父类的私有成员属性，可以被继承，但继承下来后，子类的访问权限，是不可见，不是private权限
//即，子类对象，类内类外都不可访问

//注意：只有最开始的父类，私有成员属性，访问控制权限是类内可以访问，类外不可以访问
//而继承下来的私有成员属性，都是不可见的，不可访问的