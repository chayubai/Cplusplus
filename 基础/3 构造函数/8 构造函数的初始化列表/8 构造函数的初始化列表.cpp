#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Person
{
public:
	/*Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}*/
	/*Person() :m_A(10), m_B(20)
	{

	}*/

	//���캯���ĳ�ʼ���б�
	Person(int a, int b) :m_A(a), m_B(b)
	{

	}
	int m_A;
	int m_B;
};

int main()
{
	Person p(10, 20);

	return 0;
}