#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//������protected��privateȨ�޿��Ƶĳ�Ա����������ͬ��
class Parent
{
public:
	int pub;//������ڲ����ⲿ�����Է���
protected:
	int pro;//������ڲ����Է��ʣ�������ⲿ�����Է���
private:
	int pri;//������ڲ����Է��ʣ�������ⲿ�����Է���
};

#if 0
//���м̳�
//�����public�Ƿ��ʿ���Ȩ�ޡ������public�Ǽ̳з�ʽ
//������protected��privateȨ�޿��Ƶĳ�Ա�������ǲ���ͬ��
class Child:public Parent
{
public:
	void func()
	{
		cout << "pub" << pub << endl;//pub�Ǹ����public��Ա����public�̳У���ġ��ڲ������Է���

		cout << "pro" << pro << endl;//pub�Ǹ����protected��Ա����public�̳У���ġ��ڲ������Է���
									 //��ʱ��pro���������ܹ����ʣ�˵��pro����private��Ա������protected��Ա
		//cout << "pri" << pri << endl;//pub�Ǹ����private��Ա����public�̳У���ġ��ڲ��������Է���
	}

};
class SubChild :public Child
{
public:
	void func2()
	{
		cout << "pub" << pro << endl;//pub�Ǹ����public��Ա����public�̳У���ġ��ڲ������Է���
	}

};
#endif

//����1��ֻҪ�Ǹ����е�private��Ա��������ʲô�̳з�ʽ�����඼���ʲ���
//����2���������public�̳У������еķ��ʿ���Ȩ�ޱ��ֲ���
//����3���������protected�̳У������еĸ����г���private��Ա�����������඼��protected
//����4���������private�̳У�����ĸ������private��Ա�����������඼��private��Ա

#if 0
//�����̳�
class Child :protected Parent
{
public:
	void func()
	{
		cout << "pub" << pub << endl;//pub�Ǹ����public��Ա����protected�̳У���ġ��ڲ������Է���
									 //pub������ڲ����Է��ʣ�����ⲿ���ʲ��ˣ���Ķ��ӿ��Է���
									 //˵��pub����protected��Ա
		cout << "pro" << pro << endl;//pro�Ǹ����protected��Ա����protected�̳У���ġ��ڲ������Է���
									 //pro��pub��һ�������ʣ�proҲ��protected��Ա
		cout << "pri" << pri << endl;//pri�Ǹ����private��Ա����protected�̳У���ġ��ڲ��������Է���
	}

};
class SubChild :public Child
{
public:
	void func2()
	{
		cout << "pub" << pub << endl;//pub�Ǹ����public��Ա����protected�̳У���ġ��ڲ������Է���
		cout << "pro" << pro << endl;//pro�Ǹ����public��Ա����protected�̳У���ġ��ڲ������Է���
	}
};
#endif

#if 0
//˽�м̳�
class Child :private Parent
{
public:
	void func()
	{
		cout << "pub" << pub << endl;//pub�Ǹ����public��Ա����private�̳У���ġ��ڲ������Է���
									 //pub�ڶ����з��ʲ��ˣ�����ⲿ���ʲ��ˣ�˵��pub��Child����˽�г�Ա
		cout << "pro" << pro << endl;//pro�Ǹ����protected��Ա����private�̳У���ġ��ڲ������Է���
									 //pro��pub��һ�������ʣ�proҲ��private��Ա
		cout << "pri" << pri << endl;//pri�Ǹ����private��Ա����private�̳У���ġ��ڲ��������Է���
}

};
class SubChild :public Child
{
public:
	void func2()
	{
		cout << "pub" << pub << endl;//pub�Ǹ����public��Ա����protected�̳У���ġ��ڲ������Է���
		cout << "pro" << pro << endl;//pro�Ǹ����public��Ա����protected�̳У���ġ��ڲ������Է���
	}
};
#endif

//����ԭ��
//1�����õĳ�Ա������������ڲ������ⲿ
//2������̳з�ʽ
//3����ǰ�����������еı����ڸ����еķ��ʿ���Ȩ��

int main()
{
#if 0
	Child c1;
	c1.func();
	//c1.pub;//pub�Ǹ���Ĺ��г�Ա����public�̳У���ġ��ⲿ�����Է���

	//c1.pro;//pro�Ǹ���ı�����Ա����public�̳У���ġ��ⲿ�������Է���
	
	//c1.pri;//pri�Ǹ����˽�г�Ա����public�̳У���ġ��ⲿ�������Է���
#endif

#if 0
	Child c2;
	c2.func();
	c2.pub;//pub�Ǹ���Ĺ��г�Ա����protected�̳У���ġ��ⲿ�������Է���

	c2.pro;//pro�Ǹ���ı�����Ա����protected�̳У���ġ��ⲿ�������Է���

	c2.pri;//pri�Ǹ����˽�г�Ա����protected�̳У���ġ��ⲿ�������Է���
#endif

#if 0
	Child c3;
	c3.func();
	c3.pub;//pub�Ǹ���Ĺ��г�Ա����private�̳У���ġ��ⲿ�������Է���

	c3.pro;//pro�Ǹ���ı�����Ա����private�̳У���ġ��ⲿ�������Է���

	c3.pri;//pri�Ǹ����˽�г�Ա����private�̳У���ġ��ⲿ�������Է���
#endif

	return 0;
}