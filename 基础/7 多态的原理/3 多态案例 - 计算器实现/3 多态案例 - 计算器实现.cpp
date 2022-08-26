#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>

#if 0 
//非多态方式：
class calculator
{
public:
	int getResult(string oper)//char oper
	{
		if (oper == "+")//oper == '+'
		{
			return m_A + m_B;
		}
		else if (oper == "-")
		{
			return m_A + m_B;
		}
		else if (oper == "*")
		{
			return m_A * m_B;
		}
		else if (oper == "/")
		{
			return m_A / m_B;
		}
	}

	int m_A;
	int m_B;
};

int main()
{
	calculator c;
	c.m_A = 10;
	c.m_B = 20;
	cout << c.getResult("+") << endl;
}
#endif

//对于上面代码，当添加功能时，需要修改源码，且当功能出现问题，维护不方便

//设计原则：开闭原则
//		对扩展进行开放，对修改进行关闭

//利用多态实现计算器

//基类
class AbstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}

	int m_A;
	int m_B;
};
//加法计算器类
class AddCalculator:public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A + m_B;
	}
};
//减法计算器类
class SubCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A - m_B;
	}
};
//乘法计算器类
class MulCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A * m_B;
	}
};

//当若干年后想要提供更多新功能，只需要追加代码即可

int main()
{
	//利用多态调用不同的计算器类的功能
	AbstractCalculator *c = new AddCalculator;//父类指针指向子类对象
	c->m_A = 10;
	c->m_B = 20;
	cout << c->getResult() << endl;

	delete c;

	c = new SubCalculator;
	c->m_A = 10;
	c->m_B = 20;
	cout << c->getResult() << endl;

	delete c;
	c = NULL;
}
//多态：代码可读性强，组织结构清晰，扩展性强