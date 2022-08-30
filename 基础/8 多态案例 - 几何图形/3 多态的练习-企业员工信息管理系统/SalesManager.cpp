#include "SalesManager.h"


SalesManager::SalesManager()
{
#if 0 //如果这样将业务放在构造函数里，测试这个类的对象时，他会调用SaleMan()和Manager()的构造分别进行初始化
	cout << "请输入销售经理的姓名" << endl;
	cin >> name;
	fixSalary = 5000;
	salePersent = 0.05;
#endif
}


SalesManager::~SalesManager()
{
	cout << "~SalesManager()" << endl;
}

void SalesManager::init()
{
	cout << "请输入销售经理的姓名" << endl;
	cin >> name;

	fixSalary = 5000;
	salePersent = 0.05;
}

//得到员工的薪水的方法
void SalesManager::getPay()
{
	cout << "请输入销售经理当前月的销售额" << endl;
	cin >> this->saleAmount;

	//计算薪水
	this->salary = this->fixSalary + this->saleAmount * this->salePersent;
}

//员工的升级方法
void SalesManager::uplevel(int addLevel)
{
	this->level += addLevel;
	if (level == 1)
		this->salePersent = 0.05;
	else if (level == 2)
		this->salePersent = 0.08;
}