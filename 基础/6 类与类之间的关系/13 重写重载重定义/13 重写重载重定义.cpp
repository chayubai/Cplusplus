#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//��������
//һ����ͬһ���������¡�
#if 0
int main()
{
	void func()
	{
		
	}
	void func(int a)
	{

	}
	return 0;
}
#endif

//�ض��壺������������ͬ�����У�һ���Ǹ��࣬һ��������
//1����ͨ�����ض��壺�������������ͨ��Ա��������������д����˵���ض���
//2���麯����д�����������麯������������д�������麯����д����������ᷢ����̬
#if 0
class A
{
public:
	void print()
	{

	}

};
class B :public A
{
	void print()
	{
		
	}
};
#endif

//��д��
#if 0
class A
{
	virtual void print()
	{
		cout << "A :" << this->p << endl;
	}
};

class B :public A
{
	virtual void print()
	{
		cout << "B :" << this->p << endl;
	}
};
#endif