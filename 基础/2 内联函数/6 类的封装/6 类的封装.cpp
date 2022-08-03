#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

struct Date 
{
	//注意：一个结构体的内部，默认的访问控制权限是public
	int year;
	int month;
	int day;
};
void init_date(struct Date& d)
{
	cout << "year month day" << endl;
	cin >> d.year;
	cin >> d.month;
	cin >> d.day;
	//这里可以一行输入，也可以多行输入
}
void print_date(struct Date& d)
{
	cout << d.year << "年" << d.month << "月" << d.day << "日" << endl;
}
bool is_leap_year(struct Date& d)
{
	if (((d.year % 4 == 0) && (d.year % 100 != 0)) || (d.year % 400 == 0))
	{
		return true;
	}
	return false;
}

class MyDate
{
	//注意：一个类的内部，默认的访问控制权限是private
public:
	void init_date()
	{
		cout << "year month day" << endl;
		cin >> year;
		cin >> month;
		cin >> day;
		//这里可以一行输入，也可以多行输入
	}
	void print_date()
	{
		cout << year << "年" << month << "月" << day << "日" << endl;
	}
	bool is_leap_year()
	{
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		{
			return true;
		}
		return false;
	}
	//通过调用公有方法，实现对私有成员的访问
	int get_year()
	{
		return year;
	}
	void set_year(int new_year)
	{
		//可以对设置的内容，加有效性验证
		if (new_year < 0 || new_year >= 5000)
		{
			return;
		}
		else
		{
			year = new_year;
		}
	}
protected://保护控制权限。
	//在类的继承中跟private有区别，在单个类中，跟private是一模一样的
private:
	//尽量将成员属性设置为私有：
	//1、可以控制读写权限
	//2、可以对设置的内容，加有效性验证
	int year;
	int month;
	int day;
};

int main()
{
	Date d1;
	init_date(d1);
	print_date(d1);
	if (is_leap_year(d1) == true)
	{
		cout << "是闰年" << endl;
	}
	else
	{
		cout << "不是闰年" << endl;
	}
	cout << "--------------" << endl;
	
	MyDate d2;
	d2.init_date();
	d2.print_date();
	if (d2.is_leap_year() == true)
	{
		cout << "是闰年" << endl;
	}
	else
	{
		cout << "不是闰年" << endl;
	}

	//虽然不能访问私有成员，但可以在公有下通过自定义get、set方法来访问私有成员
	//即，不能通过d2.year访问year，也不能通过d2.year = 2000
	
	cout << d2.get_year() << endl;
	
	d2.set_year(2000);
	cout << d2.get_year() << endl;
	return 0;
}