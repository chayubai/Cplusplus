#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//1��this�ĺ���
class Person1
{
public:
	int m_A;

	//thisָ�룬��ʽ����ÿ����Ա������
	void func()//thisָ�����
	{}
};
void test1()
{
	Person1 p1;
	p1.func();//thisָ��p1

	Person1 p2;
	p2.func();//thisָ��p2

	//this����������˭���ú���
	//thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
}

//2��this���÷�
class Person2
{
public:
	Person2(int age)
	{
		age = age;//���ָ�ֵ�����֣�����age��ͬһ������
	}
	int age;
};
void test2()
{
	Person2 p2(18);
	cout << "p2�����䣺" << p2.age << endl;
}

class Person3
{
public:
	Person3(int age)
	{
		m_Age = age;
	}
	int m_Age;//member_age
};
void test3()
{
	Person3 p3(18);
	cout << "p3�����䣺" << p3.m_Age << endl;
}

class Person
{
public:
	Person(int age)
	{
		//��;1��������Ƴ�ͻ
		this->age = age;
	}
	//thisָ�룬��ʽ����ÿ����Ա������
	bool compareAge(Person & p)//compareAge(Person *this,Person & p)
	{
		if (age == p.age)//this->age == p.age
		{
			return true;
		}
		return false;
	}

	//����void,ֻ�����һ�Σ����Ϊ�����age��
	//����Person&���ã����������ӣ�ÿ�ν���ķ���ֵ���Ƕ�����
	/*void personAddPerson(Person & p)
	{
		this->age += p.age;
	}*/
	//Person& personAddPerson(Person& p)
	//{
	//	this->age += p.age;
	//	return *this;//thisָ��ָ����ö���*this��������
	//}

	Person personAddPerson(Person& p)
	{
		this->age += p.age;
		return *this;//thisָ��ָ����ö���*this��������//Person temp = *this
	}
	int age;
};
void test4()
{
	Person p1(10);
	cout << "p1�����䣺" << p1.age << endl;
	Person p2(10);
	cout << "p2�����䣺" << p2.age << endl;

	bool ret = p1.compareAge(p2);
	if (ret)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;
	}

	//p1.personAddPerson(p2);
	//cout << "p1�����䣺" << p1.age << endl;

	p1.personAddPerson(p2).personAddPerson(p2).personAddPerson(p2);//��ʽ���
	//        p1.personAddPerson(p2).personAddPerson(p2);
	//                  p1.personAddPerson(p2);
	//                            p1
	//ÿ�ν�������ر�����˺����ķ�������������������͡����ʵ�������ӣ����صĽ��Ϊ������
	cout << "p1�����䣺" << p1.age << endl;//coutҲ����ʽ��̣�ÿ�η��صĶ���cout

	//ע�⣺����������ΪPersonʱ�����ص���Ȼ�Ƕ��������ǻᷢ���������캯���ĵ��ã��������캯�����õ�ʱ����
	//p1.personAddPerson(p2).personAddPerson(p2).personAddPerson(p2);
	//Person temp1 = *this = p1.personAddPerson(p2)
	//Person temp2 = *this = p1.personAddPerson(p2)
	//Person temp3 = *this = p1.personAddPerson(p2)��ÿ�η��صĽ����Ϊ��ʱ����temp
}

int main()
{
	//test2();
	//test3();
	test4();
}

//class Test
//{
//public:
//	Test(int i)
//	{
//		this->mI = i;
//	}
//	int getI()//ʵ������int getI(Test *const this)
//	{
//		//this->mI = 100;//û�б���˵��thisָ�벻��const Test*����
//		//this++;//����˵��thisָ���ǳ�ָ�룬Test* const ����
//		//����this�����޸�mI��ֵ�������this�����޸ģ�--int getI()const
//		return this->mI;
//	}
//#if 0
//	int getI() const//��Ա����β������const�����ε���thisָ��
//	{
//		this->mI = 100;//����˵��thisָ�벻��const Test*����
//		return this->mI;
//	}
//	//static��Ա������ֻ�ܷ���static��Ա����
//	static int s_getI()
//	{
//		//��ͨ��Ա������������ĳ������ģ���static��Ա������û��thisָ��
//		//return this->mI;//����
//		//return mI;//����
//		return s_k;//��ȷ
//	}
//#endif
//private:
//	int mI;
//	static int s_k;
//};
//int Test::s_k = 0;
//int main()
//{
//	Test t1(10);//��Test(&t1,10);
//	t1.getI();//��getI(&t1);
//
//	return 0;
//}