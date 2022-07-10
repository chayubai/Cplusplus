#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//������Ĭ�ϸ�һ����4��������Ĭ�Ϲ��캯���������������������캯����ǳ����-ֵ��������operator=()��ǳ����-ֵ������
//operator=()�Ϳ������캯��������ʵ���������ͻ����Զ������͵����㣬������ǳ���������ܻᵼ���ظ��ͷſ�һ��ռ�
//�����Ҫ�ԵȺŲ������Ϳ������캯����������

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
	Person(const Person&p)
	{
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

	//Person p2 = p1;//�˴���Ĭ�ϵ��ÿ������캯������Person p2(p1);

	Person p2("Jerry",19);
	p2 = p1;//�˴���Ĭ�ϵ���operator=()����������ʱ���ظ��ͷ�ͬһ��ռ䣬���³������
	//��ˣ����� = ������

	cout << "p2.name = "<<p2.m_Name << ",p2.age = " << p2.m_Age << endl;
}

void test2()
{
	Person p1("Tom", 10);

	Person p2("Jerry", 19);
	p2 = p1;

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


#if 0
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
		//���ʹ��this->name = name;��ʼ�������ᵼ������
		//Student s(1,"123123");
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
	char* name;//�����char name[64]������Ҫ�������ǳ����
};
int main()
{
	Student s1(1, "zhangsan");
	Student s2 = s1;//��������

	Student s3(2, "lisi");
	s2 = s3;//s2�ĵȺŸ�ֵ������������������ֵ

	s1.printS();
	s2.printS();
	s3.printS();

	return 0;
}
#endif