#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Person
{ 
public:

	void showClass()//这个成员函数没有使用this
	{
		cout << "class Name is Person" << endl;
	}
	void showAge()//这个成员函数使用了this
	{
		//需要加一个if判断，防止空指针解引用
		/*if (this == NULL)
		{
			return;
		}*/
		m_age = 0;
		cout << "age = " << m_age << endl;//this->m_age 用空指针访问m_age
	}

	int m_age;
};

int main() 
{
	Person* p = NULL;
	p->showClass();//第一个可以运行成功，因为没有this指针

	//p->showAge();//报错：由于this指向p = NULL，用空指针访问m_age，导致错误

	//因此需要加一个if判断，防止这种情况发生
}
//总结：空指针访问成员函数
//1如果成员函数中没有用到this指针，可以用空指针调用成员函数
//2如果成员函数中用到了this，那么这个this需要加判断，防止空指针解引用