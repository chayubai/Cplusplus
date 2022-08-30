#pragma once
#include "Employee.h"

class SaleMan : virtual public Employee
{
public:
	SaleMan();
	~SaleMan();


	//得到员工的薪水的方法
	virtual void getPay();

	//员工的升级方法
	virtual void uplevel(int addLevel);

	virtual void init();

protected:
	//当月的销售总额
	int saleAmount;
	//提成比率
	double salePersent;
};
