#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

struct Date 
{
	//ע�⣺һ���ṹ����ڲ���Ĭ�ϵķ��ʿ���Ȩ����public
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
	//�������һ�����룬Ҳ���Զ�������
}
void print_date(struct Date& d)
{
	cout << d.year << "��" << d.month << "��" << d.day << "��" << endl;
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
	//ע�⣺һ������ڲ���Ĭ�ϵķ��ʿ���Ȩ����private
public:
	void init_date()
	{
		cout << "year month day" << endl;
		cin >> year;
		cin >> month;
		cin >> day;
		//�������һ�����룬Ҳ���Զ�������
	}
	void print_date()
	{
		cout << year << "��" << month << "��" << day << "��" << endl;
	}
	bool is_leap_year()
	{
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		{
			return true;
		}
		return false;
	}
	//ͨ�����ù��з�����ʵ�ֶ�˽�г�Ա�ķ���
	int get_year()
	{
		return year;
	}
	void set_year(int new_year)
	{
		//���Զ����õ����ݣ�����Ч����֤
		if (new_year < 0 || new_year >= 5000)
		{
			return;
		}
		else
		{
			year = new_year;
		}
	}
protected://��������Ȩ�ޡ�
	//����ļ̳��и�private�������ڵ������У���private��һģһ����
private:
	//��������Ա��������Ϊ˽�У�
	//1�����Կ��ƶ�дȨ��
	//2�����Զ����õ����ݣ�����Ч����֤
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
		cout << "������" << endl;
	}
	else
	{
		cout << "��������" << endl;
	}
	cout << "--------------" << endl;
	
	MyDate d2;
	d2.init_date();
	d2.print_date();
	if (d2.is_leap_year() == true)
	{
		cout << "������" << endl;
	}
	else
	{
		cout << "��������" << endl;
	}

	//��Ȼ���ܷ���˽�г�Ա���������ڹ�����ͨ���Զ���get��set����������˽�г�Ա
	//��������ͨ��d2.year����year��Ҳ����ͨ��d2.year = 2000
	
	cout << d2.get_year() << endl;
	
	d2.set_year(2000);
	cout << d2.get_year() << endl;
	return 0;
}