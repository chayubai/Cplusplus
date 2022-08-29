#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

//抽象类
class Programmer
{
public:
	Programmer(double salary)
	{
		this->salary = salary;
	}
	virtual void printMoney() = 0;

	virtual ~Programmer()
	{

	}
protected:
	double salary; //工资
};

class  Junior_programmer :public Programmer
{
public:
	Junior_programmer(double salary) :Programmer(salary)
	{

	}
	virtual void printMoney() {
		cout << "初级成员的工资是 " << this->salary << endl;
	}
};

class Mid_programmer :public Programmer
{
public:
	Mid_programmer(double salary) :Programmer(salary)
	{

	}
	virtual void printMoney() {
		cout << "中级成员的工资是 " << this->salary << endl;
	}
};

class Adv_programmer :public Programmer
{
public:
	Adv_programmer(double salary) :Programmer(salary)
	{

	}
	virtual void printMoney() {
		cout << "高级级成员的工资是 " << this->salary << endl;
	}
};

//针对抽象类封装的一个架构函数
void printSalary(Programmer* p)
{
	p->printMoney();
}

int main(void)
{
	Programmer* p = new Junior_programmer(8000);

	printSalary(p);
	delete p;

	p = new Mid_programmer(18000);
	printSalary(p);
	delete p;


	p = new Adv_programmer(20000);
	printSalary(p);
	delete p;

	p = NULL;


	return 0;
}