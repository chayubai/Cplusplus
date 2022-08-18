#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std; 

//������Ĭ�ϸ�һ����4��������Ĭ�Ϲ��캯���������������������캯����ǳ����-�򵥵�ֵ��������operator=()��ǳ����-�򵥵�ֵ������
//operator=()�Ϳ������캯��������ʵ���������ͻ����Զ������͵����㣬������ǳ���������ܻᵼ���ظ��ͷſ�һ��ռ�
//�����Ҫ�ԵȺŲ������Ϳ������캯������Ҫ�����������ʵ��

#if 0
class Person
{
public:
	Person(const char* name, int age)
	{
		this->m_Name = new char[strlen(name) + 1];
		strcpy(this->m_Name, name);
		this->m_Age = age;
	}

	//��Ա����ʵ�֣�����=������
	//�������
	//1����������Ϊvoid,����const����ֹ�ڲ�ͨ��p��˽�г�Ա���޸�
	/*void operator=(const Person& p)
	{
		//�Ƚ�ԭ����p2�������ͷŸɾ�
		//�����ж�ԭ�������ͷ��Ƿ������ݣ���������ͷ�
		if (this->m_Name != NULL)
		{
			delete[] this->m_Name;
			this->m_Name = NULL;
		}

		//�����,��p1�����ݸ�ֵ��p2��
		this->m_Name = new char[strlen(p.m_Name) + 1];
		strcpy(this->m_Name, p.m_Name);
		this->m_Age = p.m_Age;
	}*/

	//2����������ΪPerson&,����const����ֹ�ڲ�ͨ��p��˽�г�Ա���޸�
	Person& operator=(const Person& p)
	{
		if (this->m_Name != NULL)
		{
			delete[] this->m_Name;
			this->m_Name = NULL;
		}

		this->m_Name = new char[strlen(p.m_Name) + 1];
		strcpy(this->m_Name, p.m_Name);
		this->m_Age = p.m_Age;

		return *this;
	}

	//�������캯����д
	Person(const Person &p)
	{
		//�������캯�����ǲ���Ҫ�ж�ԭ�����Ƿ������ݣ���Ϊ�����û������
		this->m_Name = new char[strlen(p.m_Name) + 1];
		strcpy(this->m_Name, p.m_Name);
		this->m_Age = p.m_Age;
	}

	~Person()
	{
		if (this->m_Name != NULL)
		{
			delete[] this->m_Name;
			this->m_Name = NULL;
		}
	}
	char* m_Name;
	int m_Age;
};
void test1()
{
	Person p1("Tom",10);

	//Person p2 = p1;//�˴��ǵ���Ĭ�Ͽ������캯������Person p2(p1);

	Person p2("Jerry",19);
	p2 = p1;//�˴��ǵ���Ĭ��operator=()����������ʱ���ظ��ͷ�ͬһ��ռ䣬���³������
	//��ˣ����� = �����������ñ��ʣ�p2.operator=(p1)

	cout << "p2.name = "<<p2.m_Name << ",p2.age = " << p2.m_Age << endl;
}

void test2()
{
	Person p1("Tom", 10);

	Person p2("Jerry", 19);
	p2 = p1;

	//�����Զ����������Ϳ�����=����
	Person p3("",20);
	p3 = p2 = p1;//���Ȳ��������ڷ�������Ϊvoid������p2 = p1ʱ����void�����ٸ�ֵ��p3���±���
	
	//��˷�������Ϊ���ã�p2 = p1����p2�ı���,p3 = p2����p3�ı���

	cout << "p3.name = " << p3.m_Name << ",p3.age = " << p3.m_Age << endl;
}

void test3()
{
	Person p1("Tom", 10);

	Person p2("Jerry", 19);
	p2 = p1;

	Person p3("", 20);
	p3 = p2 = p1;

	Person p4 = p3;//Ĭ�ϵ��ÿ�������Person p4(p3);ǳ��������������ʱ���ظ��ͷ�ͬһ��ռ䣬�ᵼ�³������
	//���ñ��ʣ�p4.Person(p3)
	//���ҲҪ��Ҫ��д�������캯����ʵ�����

	cout << "p4.name = " << p4.m_Name << ",p4.age = " << p4.m_Age << endl;
}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}
#endif

class Student
{
public:
	Student()
	{
		this->id = 0;
		this->name = NULL;
	}
	Student(int id, const char *name)
	{
		this->id = id;
		//���ʹ��this->name = name;ʹ�ó�����ʼ�������ᵼ������
		//�磺Student s(1,"123123");
		
		//���ʹ��this->name = name;��ʼ�������·����Ķ��壬�ᵼ������
		//char name[64] = "zhangsan";Student s(1,name);
		//char *name = new char[64];strcpy(name,"zhangsan");Student s1(1,name);delete[] name;s1.printS();

		int len = strlen(name);
		this->name = new char[len + 1];
		strcpy(this->name, name);
	}
	Student(const Student &another)
	{
		this->id = another.id;

		//���
		int len = strlen(another.name);
		this->name = new char[len + 1];
		strcpy(this->name, another.name);
	}
	~Student()
	{
		if (this->name != NULL)
		{
			delete[] this->name;
			this->name = NULL;
			this->id = 0;
		}
	}
	Student& operator=(const Student &another)
	{
		//��ֹ����ֵ
		if (this == &another)//&anotherȡ��ַ
		{
			return *this;
		}
		//�Ƚ�������⿪�ٵĿռ���յ�
		if (this->name != NULL)
		{
			delete[] this->name;
			this->name = NULL;
			this->id = 0;
		}
		//ִ�����
		int len = strlen(another.name);
		this->name = new char[len + 1];
		strcpy(this->name, another.name);

		return *this;
	}
	void printS()
	{
		cout << name << endl;
	}
private:
	int id;
	char* name;//�����char name[64]��ջ�Ͽ��ٵ����飬����Ҫ�������ǳ����
};

void test()
{
	//����вι����ָ���ʼ����ʽΪthis->name = name;
	//����Ǵ�����������ԡ��磺Student s(1, "12121");
	//����Ǵ��������������⡣

	char name[64] = "zhangsan";
	Student s(1,name);//�������name
	//��ʱ����char* nameά������ջ�ϵ�����name[64],ָ��ͬһ����ַ
	//��������������������������ͬ
	//��name�����ˣ����е�char* nameҲ���������ʱs����ͻ�������

	//�������·�ʽ
	char *name = new char[64];
	strcpy(name,"zhangsan");
	Student s1(1,name);//�������name
	//��ʱ����char* nameά�����Ƕ��ϵ�name = new char[64];,ָ��ͬһ����ַ
	//��������������������������ͬ
	//��name�����ˣ����е�char* nameҲ���������ʱs1����ͻ�������

	delete[] name;
	//��name�ͷ�ʱ�����е�char* nameҲ���ͷ�
	s1.printS();
}

int main()
{

	Student s1(1, "zhangsan");
	Student s2 = s1;//��������

	Student s3(2, "lisi");
	s2 = s3;//s2�ĵȺŸ�ֵ������������������ֵ������s2����

	s1.printS();
	s2.printS();
	s3.printS();

	return 0;
}

//ע�⣺Ĭ�Ͽ������캯����Ĭ�ϸ�ֵ�����������Ĺ��ܶ���һ���ģ�����ǳ��������

//Student s1(1, "zhangsan");
//Student s2 = s1;//��������
//
//Student s3(2, "lisi");
//s2 = s3;
//���ڴ�ͼ������Ĭ�ϸ�ֵ������������ֱ�ӽ�s2.name�ĸ�ֵ����s2.name
//����s2��s3��name��ָ��ͬһ��ռ䣬����ʱ�����ͷ�ͬһ��ռ����Ρ�
//ͬʱԭs2.name�е����ݵ����ڴ�й©
//������ظ�ֵ��������������Ҫ���ж�s2.name�Ƿ񿪱��˿ռ䣬���ͷſռ䣬�ٽ����������

//���ɣ������غ�����һ��Ҫ�ṩ=���������غͿ������캯������ֹ����ʹ�����Դ��ʱ������Ϊ�Լ�д�Ĵ��뱨��