#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

class Person1
{
public:
	void showPerson1()
	{
		cout << "showPerson1����"<< endl;
	}
};
class Person2
{
public:
	void showPerson2()
	{
		cout << "showPerson2����" << endl;
	}
};

//��ģ���еĳ�Ա������������һ��ʼ�����ģ����������н׶�ȷ����T���������Ͳ�ȥ������
template<class T>
class myClass
{
public:

	void func1()
	{
		obj.showPerson1();//Person1���͵Ķ���
	}
	void func2()
	{
		obj.showPerson2();//Person2���͵Ķ���
	}

	T obj;//����T�������޷�ȷ����myClass���µĳ�Ա�����޷��ڱ���׶δ���
};

void test()
{
	myClass<Person1> p1;//����һ��myClass��Ķ�����ʽָ��T������ΪPerson1
	//p1��������myClass��func1��func2��p1����ĳ�Ա
	p1.func1();//����ʱ��func1�ű�����
	//p1.func2();//������func2ʱ������������������func2��Person1����û��showPerson2��Ա�������޷�����

	//������ģ���еĳ�Ա����fun1��func2��������ʱ���������ܲ��ܴ����ɹ���ȡ���ڶ�������Ƿ��иó�Ա����
	//ע�⣺��ͨ���еĳ�Ա�����Ǳ���׶�һ��ʼ�ͱ�������ģ�����еĳ�Ա�����ǵ����ǲű�����
}
int main()
{
	test();
	return 0;
}