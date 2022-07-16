#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//������
class Animal
{
public:
	int m_Age;
};

//����
class Sheep:virtual public Animal
{
};

//����
class Tuo :virtual public Animal
{
};

//������
class SheepTuo :public Sheep,public Tuo
{
};

void test1()
{
	SheepTuo st;
	st.Sheep::m_Age = 10;//��ʼ����10��
	st.Tuo::m_Age = 20;//��ʼ����20��

	cout << "Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "Tuo::m_Age = " << st.Tuo::m_Age << endl;
	//����޷�������յ��׶�����

	//ͨ��������Ա������ʾ���߲鿴SheepTuo��ģ���Ա�ֲ����

	//��̳еķ������ؼ���virtual
	//���������࣬����̳м̳����ǵĸ���Animal����ʱ���ǵĸ���Ϊ�����
}

void test2()
{
	//��̳еķ������ؼ���virtual
	SheepTuo st;
	st.Sheep::m_Age = 10;
	st.Tuo::m_Age = 20;

	cout << "Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "Tuo::m_Age = " << st.Tuo::m_Age << endl;

	cout << "SheepTuo.m_Age = " << st.m_Age << endl;
	//��ʱ��һ�γ�ʼ����10�꣬�ڶ��γ�ʼ����20�꣨���ǣ�����������20�꣬��ʱ���Ψһ��

	//��ͨ��������Ա������ʾ���߲鿴SheepTuo��ģ���Ա�ֲ����
	//��ʱSheepTuo��̳е����������е�m_Age��Ϊvbptr = virtual base pointer�����ָ��
	//�����ָ�붼��ָ��vbtbale������ͨ��ƫ�����������ҵ�������е�m_Age

	//��������̳к�sheep��tuo���м̳���һ��bvptrָ�룬��Ϊ�����ָ�룬ָ�����������vbtable
	//�������м�¼�� ƫ������ͨ��ƫ���������ҵ�Ψһ��m_Age��ӡ�����ռ̳е���Animal���m_Age
}

void test3()
{
	SheepTuo st;
	st.m_Age = 10;

	//ͨ��Sheep�ҵ�ƫ����
	//�Ϳ�����Ա������ʾ����SheepTuo��ĳ�Ա�ֲ��Աȣ���֤
	//&st//�ҵ��׵�ַ
	//*(int*)&st//�����õ��� ��������
	cout << *((int*)*(int*)&st + 1) << endl;

	//ͨ��Tuo�ҵ�ƫ����
	cout << *((int *)*((int*)&st + 1) + 1) << endl;

	//ͨ��ƫ��������m_Age
	cout << "SheepTuo.m_Age = " << ((Animal*)((char*)&st + *((int *)*(int *)&st+1)))->m_Age << endl;
	cout << "SheepTuo.m_Age = " << *((int *)((char*)&st + *((int*)*(int*)&st + 1)))<< endl;
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}

















#if 0
class Furniture//����
{
public:
	int m;
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
	return 0;
}

#endif

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

//int main()
//{
//	Bed b;
//	b.sleep();
//
//	Sofa s;
//	s.sit();
//
//	cout << "------------" << endl;
//
//	SofaBed sb;
//	sb.SleepAndSit();
//
//	sb.m = 100;//���ʲ���ȷ
//	return 0;
//}
