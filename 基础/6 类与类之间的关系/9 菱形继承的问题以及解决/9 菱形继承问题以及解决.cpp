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
	//st.m_Age = 10;//�������ʲ���ȷ
	st.Sheep::m_Age = 10;//��ʼ����10��
	st.Tuo::m_Age = 20;//��ʼ����20��

	cout << "Sheep::m_Age = " << st.Sheep::m_Age << endl;//10
	cout << "Tuo::m_Age = " << st.Tuo::m_Age << endl;//20
	//����޷�������յ��׶�����

	//ͨ��������Ա������ʾ���߲鿴SheepTuo��ģ���Ա�ֲ��������Ĵ�С��8�ֽڣ�

	//���μ̳�������ν����
	//��̳еķ������ؼ���virtual
	//����������Sheep��Tuo�ļ̳з�ʽ��Ϊ��̳У�������̳м̳����ǵĸ���Animal����ʱ���ǵĸ���Ϊ�����
	//�������ǹ����һ������
}

void test2()
{
	//��̳еķ������ؼ���virtual
	SheepTuo st;
	st.Sheep::m_Age = 10;
	st.Tuo::m_Age = 20;

	cout << "Sheep::m_Age = " << st.Sheep::m_Age << endl;//20
	cout << "Tuo::m_Age = " << st.Tuo::m_Age << endl;//20

	cout << "SheepTuo.m_Age = " << st.m_Age << endl;//�������ж�����
	//��ʱ��һ�γ�ʼ����10�꣬�ڶ��γ�ʼ����20�꣨���ǣ�����������20�꣬��ʱ���Ψһ��

	//��ͨ��������Ա������ʾ���߲鿴SheepTuo��ģ���Ա�ֲ��������Ĵ�С��12�ֽڣ�
	//��ʱSheepTuo��̳е����������е�m_Age��Ϊvbptr = virtual base pointer�����ָ��
	//���Ե������ָ�붼��ָ����Ե�vbtbale������ͨ���������и��Ե�ƫ�����������ҵ�������е�m_Age
	//8 <SheepTuod<Sheep+0>Animal>,ǰ���8��Ϊƫ������ͨ��ָ��0 + 8�ҵ�m_Age

	//��������̳к�sheep��tuo���м̳���һ��bvptrָ�룬��Ϊ�����ָ�룬ָ�����������vbtable
	//�������м�¼�� ƫ������ͨ��ƫ���������ҵ�Ψһ��m_Age��������ռ̳е���Animal���m_Age
}

//��̳е��ڲ�����ԭ��
void test3()
{
	SheepTuo st;
	st.m_Age = 10;

	//ͨ��Sheep�ҵ�ƫ����
	//�Ϳ�����Ա������ʾ����SheepTuo��ĳ�Ա�ֲ��Աȣ���֤
	//&st//�ҵ��׵�ַ
	//(int*)&st  ǿתΪint* �ҵ�����Ĳ���
	//*(int*)&st  �����õ��� ��������
	//(int*)*(int*)&st ǿתΪint* �ҵ��������еĲ���
	//((int*)*(int*)&st + 1)  +1����������ָ��m_Age��λ��
	//*((int*)*(int*)&st + 1) �������ҵ�m_Age
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