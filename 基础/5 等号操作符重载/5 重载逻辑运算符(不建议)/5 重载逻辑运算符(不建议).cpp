#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Test
{
public:
	Test(int value)
	{
		this->value = value;
	}
	Test& operator+=(Test& another)
	{
		cout << "ִ����+=����������..." << endl;
		Test temp(this->value + another.value);
		return temp;
	}
	bool operator&&(Test& another)
	{
		cout << "ִ����&&����������..." << endl;
		if (this->value && another.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator||(Test& another)
	{
		cout << "ִ����||����������..." << endl;
		if (this->value || another.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	~Test()
	{
		cout << "~Test()..." << endl;
	}
private:
	int value;
};
int main()
{

#if 0
	int a = 0;
	if (a && (a = 10))//&& ��·��
	{

	}
	cout << "a = " << a << endl;
	a = 1;
	if (a || (a = 10))//|| ��·��
	{

	}
	cout << "a = " << a << endl;
#endif

	Test t1(0);
	Test t2(20);
	//����&&�������������ᷢ����·������
	if (t1 && (t1 += t2))//t1.operator&&( t1.operator+=(t2) )
	{
		cout << "Ϊ��" << endl;
	}
	else
	{
		cout << "Ϊ��" << endl;
	}
	cout << "-------------------------------" << endl;

	//����&&�������������ᷢ����·������
	if (t1 || (t1 += t2))//t1.operator||( t1.operator+=(t2) )
	{
		cout << "Ϊ��" << endl;
	}
	else
	{
		cout << "Ϊ��" << endl;
	}
	return 0;
}