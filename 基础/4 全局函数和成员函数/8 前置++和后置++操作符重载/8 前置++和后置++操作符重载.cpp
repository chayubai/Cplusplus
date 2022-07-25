#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>
class MyInter
{
	friend ostream& operator<<(ostream& cout, const MyInter& myInt);

public:
	MyInter()
	{
		this->m_num = 0;
	}

	//��Ա����ʵ��:ǰ��++����
	//1����������Ϊvoid
	/*void operator++()
	{
		this->m_num++;
	}*/

	//2����������ΪMyInter&
	MyInter& operator++()
	{
		this->m_num++;
		return *this;//���ر���
	}

	//3����������ΪMyInter
	/*MyInter operator++()
	{
		this->m_num++;
		return *this;//MyInter temp = *this;
	}*/

	//��Ա����ʵ��:����++����
	//4����������ΪMyInter��
	//�������������MyInter&���򷵻ؾֲ����������ûᵼ�·Ƿ������ڴ�
	//����������(b++)++�ǲ������
	MyInter operator++(int)//ͨ��ռλ����int������ǰ��++�ͺ���++�ĺ�����
	{
		//�ȼ�¼��ʼֵ�����ڷ���
		MyInter temp = *this;
		//��++
		this->m_num++;
		return temp;//����Ϊ֮ǰ��¼��ֵ,���ÿ������캯��
	}

private:
	int m_num;
};

//���ｫMyInter& myInt��Ϊconst MyInter& myInt
//���� VS2019<<���ضԺ���++������ᱨ��
ostream& operator<<(ostream& cout, const MyInter& myInt)
{
	cout << myInt.m_num;
	return cout;
}

void test1()
{
	MyInter myInt;
	++myInt;
	cout << myInt << endl;
}

void test2()
{
	MyInter myInt;

	//cout << ++myInt << endl;//����operator++()����void�����void������ͻᱨ��

	/*int a = 0;
	cout << ++(++a) << endl;
	cout << a << endl;*/

	//���������ͣ���֪++a�������ص���a

	//��ˣ��Զ�����������ͣ���Ҫʵ������++��������ʽ��̣��������Զ�����������

	cout << ++(++myInt) << endl;
	cout << myInt << endl;
}

void test3()
{
	MyInter myInt;
	//��������Զ������ͣ�������

	cout << ++(++myInt) << endl;// 2  ++myInt����temp��++(++myInt) = ++(temp)
	cout << myInt << endl;// 1

	//��ΪmyInt��һ��++�󣬲�����++������++(++myInt)���յĽ���᷵�����һ����ʱ����temp��ֵ
	//��һ��++�󣬺���++���Ƕ���ʱ��������++

	//������˵������ǰ��++��������Ҫ��������
	//����Ϊʲô���ض�������ͣ��ᱨ��
}

void test4()
{
	MyInter myInt;

	cout << myInt++ << endl;
	cout << myInt << endl;

	//������˵�����غ���++���������ܷ�����Ķ��󡣵���Ϊʲô���ᱨ��
	//��Ӧ�÷��ض�������ͣ���������ʵ��myInt++++��������++������ȴ�ᱨ��Ϊʲô��
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}

//ע�⣺ǰ��++/--���Ⱥ���++/--��Ч�ʸߣ���Ϊǰ��++/--�������ã�û�д�������
//����++/--�����ض�������ͣ�����ÿ������캯����������ʱ���󣬼���������