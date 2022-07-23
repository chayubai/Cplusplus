#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//利用多态实现计算器

//基类
class AbstractCalculator
{
public:

	/*virtual int getResult()
	{
		return 0;
	}*/

	//纯虚函数
	//如果一个类中包含了纯虚函数，那么这个类就无法实例化对象，这个类通常称为 抽象类
	//抽象类的子类，也必须要重写父类中的纯虚函数，否则也属于抽象类
	virtual int getResult() = 0;

	int m_A;
	int m_B;
};
//加法计算器类
class AddCalculator :public AbstractCalculator
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

class Test :public AbstractCalculator
{

};
void test1()
{
	//利用多态调用不同的计算器类的功能
	AbstractCalculator* c = new AddCalculator;
	c->m_A = 10;
	c->m_B = 20;
	cout << c->getResult() << endl;

	delete c;

	c = new SubCalculator;
	c->m_A = 10;
	c->m_B = 20;
	cout << c->getResult() << endl;

	//由于整个过程中父类的虚函数用不到，可以改为纯虚函数
}

void test2()
{
	//AbstractCalculator abc;//此时会报错：抽象类不能实例化对象
	//Test t;//子类继承抽象父类，也不能实例化对象报错
	//解决方法：子类中，对父类虚函数重写
}

int main()
{
	return 0;
}
