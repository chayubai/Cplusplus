#pragma once
#include <iostream>
#include <string>

using namespace std;


class Employee
{
public:
	Employee();


	virtual ~Employee();

	//得到员工的薪水的方法
	virtual void getPay() = 0;

	//员工的升级方法
	virtual void uplevel(int addLevel) = 0;

	//显示员工的信息的接口
	void displayStatus();

	//提供一个显示的初始化接口
	virtual void init() = 0;

protected:
	string name;//员工的姓名
	int id; //员工的编号
	double salary;// 员工的薪水
	int level; //员工的等级

	static int startnum; //静态的编号计数
};
