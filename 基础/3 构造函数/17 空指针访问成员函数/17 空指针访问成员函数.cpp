#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Person
{
public:

	void showClass()
	{
		cout << "class Name is Person" << endl;
	}
	void showAge()
	{
		/*if (this == NULL)
		{
			return;
		}*/
		m_age = 0;
		cout << "age = " << this->m_age << endl;
	}
	int m_age;
};

int main() 
{
	Person* p = NULL;
	p->showClass();

	//p->showAge();//报错：由于this指向p = NULL，用空指针访问m_age，导致错误

	//因此需要加一个if判断，防止这种情况发生
}