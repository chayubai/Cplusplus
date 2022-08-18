#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>
 
//对于自定义的数据类型，编译器不知道如何进行比较
//因此需要对==/!=进行重载

class Person
{

public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	bool operator==(Person &p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(Person& p)
	{
		return !(this->m_Name == p.m_Name && this->m_Age == p.m_Age);
	}
	string m_Name;
	int m_Age;
};

void test()
{
	Person p1("Tom", 18);
	Person p2("Tom", 18);

	if (p1 == p2)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;
	}

	if (p1 != p2)
	{
		cout << "p1 != p2" << endl;
	}
	else
	{
		cout << "p1 == p2" << endl;
	}
}

int main()
{
	test();
	return 0;
}