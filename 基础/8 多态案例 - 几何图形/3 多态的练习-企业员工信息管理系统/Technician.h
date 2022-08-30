#pragma once
#include "Employee.h"
//技术人员
class Technician : public Employee
{
public:
	Technician();
	~Technician();

	//得到员工的薪水的方法
	virtual void getPay();

	//员工的升级方法
	virtual void uplevel(int addLevel);

	virtual void init();

private:
	double perHourMoney; //每小时赚多钱
	int workHour; // 一个月工作了多少小时
};

