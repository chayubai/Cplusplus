#pragma once
#include "Employee.h"
#include "Manager.h"
#include "SaleMan.h"

class SalesManager : public Manager, public SaleMan
{
public:
	SalesManager();
	~SalesManager();

	//得到员工的薪水的方法
	virtual void getPay();

	//员工的升级方法
	virtual void uplevel(int addLevel);

	virtual void init();

};


