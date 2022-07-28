#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Base1
{
public:
	Base1()
	{
		this->m_A = 10;
		this->m_F = 0;
	}
	int m_A;
	int m_F;
};

class Base2
{
public:
	Base2()
	{
		this->m_B = 20;
		this->m_F = 1;
	}
	int m_B;
	int m_F;
};

//��̳�

class Son :public Base1, public Base2
{
public:
	int m_C;
	int m_D;
};

void test1()
{
	cout << "size of Son = " << sizeof(Son) << endl;

	Son s;
	cout << "s.m_A = " << s.m_A << endl;
	cout << "s.m_B = " << s.m_B << endl;
}

void test2()
{
	Son s;
	//��̳��к���������������
	//cout << "m_F = " << s.m_F << endl; 
	//����̳е�������������ͬ�ĳ�Ա����������ʱ��Ҫ���������������
	cout << "Base1.m_F = " << s.Base1::m_F << endl;
	cout << "Base2.m_F = " << s.Base2::m_F << endl;

	//ͨ��������Ա������ʾ���߲鿴
}
int main() 
{
	//test1();
	test2();
	return 0;
}

#if 0
//��̳�

class Furniture
{
public:
	int m;//����
};
class Bed :public Furniture
{
public:
	void sleep()
	{
		cout << "˯��" << endl;
	}
};
class Sofa :public Furniture
{
public:
	void sit()
	{
		cout << "��Ϣ" << endl;
	}
};

class SofaBed :public Bed, public Sofa
{
public:
	void SleepAndSit()
	{
		sleep();
		sit();
	}
};

int main()
{
	Bed b;
	b.sleep();

	Sofa s;
	s.sit();

	cout << "------------" << endl;

	SofaBed sb;
	sb.SleepAndSit();

	//sb.m = 100;//���ʲ���ȷ
	sb.Bed::m = 100;
	sb.Sofa::m = 200;

	//��̳е���һ��ɳ���������ֲ���
	return 0;
}
#endif

#if 0
//��̳�

class Furniture//�Ҿ���
{
public:
	int m;//����
};
//virtual:��������̳�үү�࣬��Ϊ��̳У���ֹ���Ӷ�̳и����ʱ�򣬳���үү���еı����´����ݡ�
class Bed :virtual public Furniture
{
public:
	void sleep()
	{
		cout << "˯��" << endl;
	}
};
class Sofa :virtual public Furniture
{
public:
	void sit()
	{
		cout << "��Ϣ" << endl;
	}
};

class SofaBed :public Bed, public Sofa
{
public:
	void SleepAndSit()
	{
		sleep();
		sit();
	}
};

int main()
{
	Bed b;
	b.sleep();

	Sofa s;
	s.sit();

	cout << "------------" << endl;

	SofaBed sb;
	sb.SleepAndSit();

	sb.m = 100;//��ʱֻ��һ��m
	return 0;
}
#endif