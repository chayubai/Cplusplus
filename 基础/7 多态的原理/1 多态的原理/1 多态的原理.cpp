#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;
 
class Parent
{
public:
	Parent(int a)
	{
		this->a = a;
	}
	virtual void func(int a)
	{
		cout << "Paren::func(int )..." << endl;
	}
	void func(int a, int b, int c)
	{
		cout << "Paren::func(int , int, int)..." << endl;
	}
private:
	int a;
};

class Child:public Parent
{
public:
	Child(int a, int b):Parent(a)
	{
		this->b = b;
	}
	/*virtual void func(int a, int b)//�������ᷢ����̬�������麯����д
	{
		cout << "Child::func(int ,int)..." << endl;
	}*/
	void func(int a)
	{
		cout << "Child::func(int)..." << endl;
	}
	void func(int a, int b)
	{
		cout << "Child::func(int , int)..." << endl;
	}
	void func(int a, int b,int c)
	{
		cout << "Child::func(int , int, int)..." << endl;
	}
private:
	int b;
};
void myFunc(Parent* pp)
{
	pp->func(10);
}
int main()
{
	Parent* pp = new Parent(10);
	Parent* cp = new Child(100, 200);
	myFunc(pp);
	myFunc(cp);

	delete pp;
	delete cp;

	Parent p(10);
	Parent* pa = &p;
	Child c(100, 200);
	Parent* pb = &c;
	myFunc(pa);
	myFunc(pb);

	delete pa;
	delete pb;

	return 0;
}

//ÿ��������г�Ա�������麯������ô����ͻ���һ���麯����ָ�루ע�⣺������ʲ��˸�ָ�룬��ָ��ʼ��ָ���麯���������ܸ����Ƿ����̳У��������麯����ָ��
//��ָ��ָ����麯�����¼�ĸ��������麯������ڵ�ַ
//��������д�����麯����Ҳ����һ���麯��ָ�룬�麯�����¼�˸���д��ĺ�������ڵ�ַ�ͱ�������е��麯������ڵ�ַ

//��������̬ʱ��ָ��������ú���ʱ���ͻ���ȥ��Ӧ���麯��������Ƿ�������ĺ��������û�У��ͻ�ȥ�����м�����������ͨ����
//Parent* pp = &p;pp->func(10);���Ҹ�����麯�����Ƿ�������ĺ��������û�У����Ҹ������ͨ���������򱨴�
//Parent* pp = &c;pp->func(10);����������麯�����Ƿ�������ĺ��������û�У��Ȳ��Ҹ�����麯�������Ҹ������ͨ���������򱨴�
// 
//

void test()
{
	Parent* pp = new Child(10,20);
	pp->func(10);//pp���õ���Child����麯�����е�func(int a)
	pp->func(10, 20, 30);//����func(int a, int b, int c)����Child����麯�����У�ppȥ�������ң����ø����func(int a, int b, int c)

	delete pp;
}

void test()
{
	//���踸���func(int a)û���麯���������func(int a)���麯��
	Parent* pp = new Child(10, 20);//��ļ�����ԭ��
	pp->func(10);//��������˭��func�� �����func

	delete pp;
	//��û�з�����̬������̬������������������һ�����㣬��
	//1����������func�ǲ��麯����ֱ�ӵ��ó�Ա����
	//2��ֻ�е������func���麯�����Ż���ȥ���麯����
}