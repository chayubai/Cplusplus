#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/*                       公共继承                     */

class Base1
{
	//控制访问权限
public:
	int m_A;//在类的内部和外部都可以访问
protected:
	int m_B;//在类的内部可以访问，在类的外部不可以访问
private:
	int m_C;//在类的内部可以访问，在类的外部不可以访问
};

class Son1:public Base1//以public方式继承父类
{
public:
	void func()
	{
		m_A = 100;//父类Base1中公共权限，子类Son1中仍为 公共权限，公共权限下子类Son1内可以访问
		m_B = 100;//父类Base1中保护权限，子类Son1中仍为 保护权限，保护权限下子类Son1内可以访问
		//m_C = 100;//父类中私有成员，子类Son1内无法访问
	}
};

void test1()
{
	Son1 s1;
	s1.m_A = 100;//在Son1中 m_A是公共权限，公共权限下子类Son1外可以访问
	//s1.m_B = 100;//在Son1中 m_B是保护权限，保护权限下子类Son1外不可以访问
	//s1.m_C = 100;//父类中私有成员，子类Son1外无法访问
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
		m_A = 100;//父类Base2中公共权限，子类Son2中变为 保护权限，保护权限下子类Son2内可以访问
		m_B = 100;//父类Base2中保护权限，子类Son2中仍为 保护权限，保护权限下子类Son2内可以访问
		//m_C = 100;//父类中私有成员，子类Son2内无法访问
	}
};

void test2()
{
	Son2 s2;
	//s2.m_A = 100;//在Son2中 m_A是保护权限，保护权限下子类Son2外不可以访问
	//s2.m_B = 100;//在Son2中 m_B是保护权限，保护权限下子类Son2外不可以访问
	//s2.m_C = 100;//父类中私有成员，子类Son2外无法访问
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
		m_A = 100;//父类Base3中公共权限，子类Son3中变为 私有权限，私有权限下子类Son3内可以访问
		m_B = 100;//父类Base3中保护权限，子类Son3中变为 私有权限，私有权限下子类Son3内可以访问
		//m_C = 100;//父类中私有成员，子类Son3内无法访问
	}
};

void test3()
{
	Son3 s3;
	//s3.m_A = 100;//在Son3中 m_A是私有权限，私有权限下类外不可以访问
	//s3.m_B = 100;//在Son3中 m_B是私有权限，私有权限下类外不可以访问
	//s3.m_C = 100;//父类中私有成员，子类Son3外无法访问
}

class GrandSon3 :public Son3
{
public:
	void func()
	{
		//m_A = 100;//在Son3中 m_A已经变为私有权限，私有权限下子类GrandSon3内外均不可访问
		//m_B = 100;//在Son3中 m_B已经变为私有权限，私有权限下子类GrandSon3内外均不可访问
		//m_C = 100;//父类中私有成员，子类GrandSon3内外均无法访问
	}
};

//注意：父类的私有属性，是可以被继承的，只是访问不到
