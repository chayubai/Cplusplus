#define _CRT_SECURE_NO_WARNINGS 1
//1、将类写到myArray.hpp中
//2、属性：
//			a.T * pAddress;指向堆区的数组指针
//			b.int m_Capacity;数组容量
//			c.int m_Size;数组大小
//3、行为：
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
		myIntArr.pushBack(i + 100);//pushBack的实参是i + 100数值。 T& val = 100，不合法，形参要加const，这里会报错
	}
	//int a = 10;
	//myIntArr.pushBack(a);这个时候 T& val = a，是合法的
	
	myPrintInt(myIntArr);
}

class Person
{
public:
	//这里一定要提供无参构造函数，否则程序会报错
	Person()//因为开辟类对象的数组时，默认会调用默认构造
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
		cout << "姓名：" << myPersonArr[i].m_Name << " ，年龄：" << myPersonArr[i].m_Age << endl;
	}
}
//注意：打印函数不能实现函数模板，因为不同的类的输出内容的结构一般不同

void test2()
{
	MyArray<Person> myPersonArr(100);//这里创建数组时，会调用默认构造
	Person p1("孙悟空", 1000);
	Person p2("猪八戒", 800);
	Person p3("唐增", 10000); 
	Person p4("沙悟净", 300);
	Person p5("白龙马", 500);

	myPersonArr.pushBack(p1);
	myPersonArr.pushBack(p2);
	myPersonArr.pushBack(p3);
	myPersonArr.pushBack(p4);
	myPersonArr.pushBack(p5);

	myPrintPerson(myPersonArr);

	cout << "数组的容量：" << myPersonArr.getCapacity()<< endl;
	cout << "数组的大小：" << myPersonArr.getSize() << endl;

}
int main()
{
	//test1();
	test2();
	return 0;
}