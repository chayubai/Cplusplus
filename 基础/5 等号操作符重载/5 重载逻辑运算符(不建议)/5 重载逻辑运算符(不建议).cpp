#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
 
class Test
{
public:
	Test(int value)
	{
		this->value = value;
	}
	Test operator+(Test& another)
	{
		cout << "执行了+操作符重载..." << endl;
		Test temp(this->value + another.value);
		return temp;
	}
	Test& operator+=(Test& another)
	{
		cout << "执行了+=操作符重载..." << endl;
		this->value += another.value;
		//Test temp(this->value + another.value);//是错误的
		return *this;
	}
	bool operator&&(Test& another)
	{
		cout << "执行了&&操作符重载..." << endl;
		if (this->value && another.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator||(Test& another)
	{
		cout << "执行了||操作符重载..." << endl;
		if (this->value || another.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	~Test()
	{
		cout << "~Test()..." << endl;
	}
private:
	int value;
};

int main()
{

#if 0
	//内置类型的&&和||操作的运算
	int a = 0;
	if (a && (a = 10))//&& 短路与
	{

	}
	cout << "a = " << a << endl;
	a = 1;
	if (a || (a = 10))//|| 短路与
	{

	}
	cout << "a = " << a << endl;
#endif

	Test t1(0);
	Test t2(20);
	//重载&&操作符，并不会发生短路与现象
	if (t1 && (t1 += t2))//t1.operator&&( t1.operator+=(t2) )，导致(t1 += t2)先执行
	{
		cout << "为真" << endl;
	}
	else
	{
		cout << "为假" << endl;
	}
	cout << "-------------------------------" << endl;

	//重载&&操作符，并不会发生短路或现象
	if (t1 || (t1 += t2))//t1.operator||( t1.operator+=(t2) )
	{
		cout << "为真" << endl;
	}
	else
	{
		cout << "为假" << endl;
	}
	return 0;
}