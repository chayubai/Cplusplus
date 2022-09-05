#define _CRT_SECURE_NO_WARNINGS 1
//1������д��myArray.hpp��
//2�����ԣ�
//			a.T * pAddress;ָ�����������ָ��
//			b.int m_Capacity;��������
//			c.int m_Size;�����С
//3����Ϊ��
//			a.myArray(int capacity)
//			b.myArray(const MyArray& arr)
//			c.operator=()
//			d.operator[]()
//			e.~myArray()
//			f.getCapacity()
//			g.getSize()
//			d.operator[]()
//			e.pushBack()

#include "myArray.hpp"

void myPrintInt(MyArray<int> &myIntArr)
{
	for (int i = 0; i < myIntArr.getSize(); i++)
	{
		cout << myIntArr[i] <<" ";
	}
}
void test1()
{
	MyArray<int> myIntArr(100);
	for (int i = 0; i < 10; i++)
	{
		myIntArr.pushBack(i + 100);//pushBack��ʵ����i + 100��ֵ�� T& val = 100�����Ϸ����β�Ҫ��const������ᱨ��
	}
	//int a = 10;
	//myIntArr.pushBack(a);���ʱ�� T& val = a���ǺϷ���
	
	myPrintInt(myIntArr);
}

class Person
{
public:
	//����һ��Ҫ�ṩ�޲ι��캯�����������ᱨ��
	Person()//��Ϊ��������������ʱ��Ĭ�ϻ����Ĭ�Ϲ���
	{

	}

	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void myPrintPerson(MyArray<Person> &myPersonArr)
{
	for (int i = 0; i < myPersonArr.getSize(); i++)
	{
		cout << "������" << myPersonArr[i].m_Name << " �����䣺" << myPersonArr[i].m_Age << endl;
	}
}
//ע�⣺��ӡ��������ʵ�ֺ���ģ�壬��Ϊ��ͬ�����������ݵĽṹһ�㲻ͬ

void test2()
{
	MyArray<Person> myPersonArr(100);//���ﴴ������ʱ�������Ĭ�Ϲ���
	Person p1("�����", 1000);
	Person p2("��˽�", 800);
	Person p3("����", 10000); 
	Person p4("ɳ��", 300);
	Person p5("������", 500);

	myPersonArr.pushBack(p1);
	myPersonArr.pushBack(p2);
	myPersonArr.pushBack(p3);
	myPersonArr.pushBack(p4);
	myPersonArr.pushBack(p5);

	myPrintPerson(myPersonArr);

	cout << "�����������" << myPersonArr.getCapacity()<< endl;
	cout << "����Ĵ�С��" << myPersonArr.getSize() << endl;

}
int main()
{
	//test1();
	test2();
	return 0;
}