#include "Manager.h"
Manager::Manager()
{
#if 0
	cout << "请输入经理的姓名" << endl;
	cin >> name;

	//经理的固定薪水是8000
	fixSalary = 8000;
#endif
}


Manager::~Manager()
{
	cout << "~Manager()" << endl;
}

void Manager::init()
{
	cout << "请输入经理的姓名" << endl;
	cin >> name;

	//经理的固定薪水是8000
	fixSalary = 8000;
}


//得到员工的薪水的方法
void Manager::getPay()
{
	//计算经理的薪资方法
	this->salary = fixSalary;
}

//员工的升级方法
void Manager::uplevel(int addLevel)
{
	this->level += addLevel;
	if (level == 1)
		this->fixSalary = 8000;
	else if (level == 2)
		this->fixSalary = 10000;
}