#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

struct Person1
{
	//struct���Ͳ�д����Ȩ�ޣ� Ĭ��public����Ȩ��
	char name[64];
	int age;
	void PersonEating()
	{
		cout << name << "���ڳԷ�" << endl;
	}
};

struct Dog1
{
public:
	char name[64];
	int age;
	void DogEating()
	{
		cout << name << "���ڹ���" << endl;
	}
};

class Person2
{
public:	//class��д����Ȩ�ޣ�Ĭ��private����Ȩ��
	char name[64];
	int age;
	void PersonEating()
	{
		cout << name << "���ڳԷ�" << endl;

	}
};

class Dog2
{
public:
	char name[64];
	int age;
	void DogEating()
	{
		cout << name << "���ڹ���" << endl;
	}
};
void test1()
{
	Person1 p;
	strcpy(p.name, "����");
	p.PersonEating();

	Dog1 d;
	strcpy(d.name, "����");
	d.DogEating();

	Person1 p2;
	strcpy(p2.name, "����");
	//p2.DogEating();//�ǽṹ�����͵ı����޷����ʽṹ���ڵĳ�Ա
}
void test2()
{
	Person2 p;
	//˽��Ȩ�޲��ɷ���
	//strcpy(p.name, "����");
	//p.PersonEating();

	Dog2 d;
	strcpy(d.name, "����");
	d.DogEating();

	Dog2 d2;
	strcpy(d2.name, "����");
	//d2.PersonEating();//����Ķ����޷��������ڵĳ�Ա
}
//C++��װ���
//1�������Ժ���Ϊ��Ϊһ�����壬�����������е�����
//2�������Ժ���Ϊ������Ȩ�޿��ƣ����ϸ������ת��

//struct ��class����
//1��classĬ��Ȩ����˽��Ȩ�ޣ�structĬ���ǹ���Ȩ��
//2������Ȩ�ޣ�
//public:������������ں����ⶼ�ܷ��ʳ�Ա
//private:������������ڷ��ʳ�Ա�������޷����ʳ�Ա�����಻���Է��ʸ���privateȨ��
//protected:������������ڷ��ʳ�Ա�������޷����ʳ�Ա��������Է��ʸ���protectedȨ��
//private��protected��Ҫ����ļ̳�ʱ������

#include <string>
class Person3
{
public:
	string m_name;
protected:
	string m_Car;
private:
	int m_pwd;
	void func()
	{
		m_name = "zhangsan";//"zhangsan"Ϊconst char*���ͣ���ʽת��Ϊstring���� 
		m_Car = "������";
		m_pwd = 123456;
	}
};

void test3()
{
	Person3 p3;
	p3.m_name = "lisi";//����ɷ��ʡ�
	//p3.m_Car = "��˹��˹";//���ⲻ�ɷ���
	//p3.m_pwd = 888888;//���ⲻ�ɷ���
}
int main()
{
	//test1();
	//test2();
	return 0;
}