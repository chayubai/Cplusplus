#pragma once
#include "Employee.h"
class Manager : virtual public Employee
{
public:
	Manager();
	~Manager();

	//得到员工的薪水的方法
	virtual void getPay();

	//员工的升级方法
	virtual void uplevel(int addLevel);

	virtual void init();


protected:
	double fixSalary; //固定薪水
};


