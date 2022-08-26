#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Parent
{
public: 
	Parent(int a)
	{
		cout << "Parent(int a)..." << endl;
		this->a = a;

		print();//�ǵ��ø����print�����������print? - �����print
	}
	virtual void print()
	{
		cout << "Parent::print()...a = " << a << endl;
	}
private:
	int a;
};
class Child:public Parent
{
public:
	Child(int a,int b):Parent(a)
		//�ڵ��ø���Ĺ�������ʱ�򣬻Ὣvptr��������������
		//��ʱ����ʱָ������麯����
	{
		//��������������vptrָ��ʹ�ָ������麯���� ��� ָ��������麯����
		cout << "Child(int a, int b)..." << endl;
		this->b = b;
		print();//�ǵ��ø����print�����������print? - �����print
	}
	virtual void print()
	{
		cout << "Child::print()...b = " << b << endl;
	}
private:
	int b;
};

void test()
{
	Parent* pp = new Child(10, 20);//�����������new Child(10, 20)�����Ȼṹ�츸�࣬�����ø����(�޲�/�в�)���캯��
	
	//delete pp;
	
	//�������������ڴ�ֲ�ͼ��
	//�����츸�����ʱ����vptrָ���a�����ǰ�����Ĺ��������н���������������vptrָ�����

	//���������������󣬣�vptrָ���a������ʼ����ɺ󣩰���������vptrָ�����

	//�ʣ���������vptrָ��ĳ�ʼ���Ƿֲ���ʼ����

	//ע�⣺�������У����캯���У���Ҫдҵ������麯����ʹ�ã����Ĺ���ֻ��һ�������Խ��г�ʼ��
}

int main()
{
	test();

	return 0;
}