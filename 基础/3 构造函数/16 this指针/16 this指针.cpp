#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0
//1、this的含义
//对于静态成员函数是没有this指针的
class Person1
{
public:
	int m_A;

	//this指针，隐式加在每个成员函数中
	void func()//this指向对象
	{}
};
void test1()
{
	Person1 p1;
	p1.func();//this指向p1

	Person1 p2;
	p2.func();//this指向p2

	//this可以区分是谁调用函数
	//this指针 指向 被调用的成员函数 所属的 对象
}

//2、this的用法
class Person2
{
public:
	Person2(int age)
	{
		age = age;//这种赋值，发现：函数内的三个age是同一个变量，与成员变量age无关
	}
	int age;
};
void test2()
{
	Person2 p2(18);
	cout << "p2的年龄：" << p2.age << endl;
}

class Person3
{
public:
	Person3(int age)
	{
		m_Age = age;//当可以区分形参和成员变量时，可以不加this
	}
	int m_Age;//member_age
};
void test3()
{
	Person3 p3(18);
	cout << "p3的年龄：" << p3.m_Age << endl;
}

class Person
{
public:
	Person(int age)
	{
		//用途1：解决名称冲突
		this->age = age;
	}
	//this指针，隐式加在每个成员函数中
	bool compareAge(Person & p)//compareAge(Person *this,Person & p)
	{
		if (age == p.age)//this->age == p.age//当可以区分形参和成员变量时，可以不加this
		{
			return true;
		}
		return false;
	}

	//返回void,只能相加一次，结果为对象的age。
	//返回Person&引用，可以连续加，每次结果的返回值都是对象本身
	/*void personAddPerson(Person & p)
	{
		this->age += p.age;
	}*/
	//Person& personAddPerson(Person& p)
	//{
	//	this->age += p.age;
	//	return *this;//this指针指向调用对象，*this即对象本身
	//}

	//如果返回类型改为非引用类型，结果？
	Person personAddPerson(Person& p)
	{
		this->age += p.age;
		return *this;//this指针指向调用对象，*this即对象本身//Person temp = *this
	}

	int age;
};
void test4()
{
	Person p1(10);
	cout << "p1的年龄：" << p1.age << endl;
	Person p2(10);
	cout << "p2的年龄：" << p2.age << endl;

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
	//cout << "p1的年龄：" << p1.age << endl;

	p1.personAddPerson(p2).personAddPerson(p2).personAddPerson(p2);//链式编程
	//        p1.personAddPerson(p2).personAddPerson(p2);
	//                  p1.personAddPerson(p2);
	//                            p1
	//每次结果都返回本身，因此函数的返回类型是类的引用类型。因此实现连续加，返回的结果为对象本身
	cout << "p1的年龄：" << p1.age << endl;//cout也是链式编程，每次返回的都是cout

	//注意：当返回类型为Person时，返回的虽然是对象本身，但是会发生拷贝构造函数的调用（拷贝构造函数调用的时机）
	//p1.personAddPerson(p2).personAddPerson(p2).personAddPerson(p2);
	//Person temp1 = *this = p1.personAddPerson(p2)
	//Person temp2 = *this = p1.personAddPerson(p2)
	//Person temp3 = *this = p1.personAddPerson(p2)，每次返回的结果都为临时变量，只有第一次进行了相加
}

int main()
{
	//test2();
	//test3();
	test4();
}
#endif

class Test
{
public:
	Test(int i)//Test(const Test* this,int i)
	{
		mI = i;//this->mI = i;
	}
	int getI()//实际上是int getI(Test *const this)
	{
		//this->mI = 100;//没有报错，说明this指针不是const Test*类型
		//this++;//报错，说明this指针是常指针，Test* const 类型
		//由于this可以修改mI的值，如何让this不能修改？ -- int getI()const
		return mI;//return this->mI;
	}
#if 0
	int getI() const//成员函数尾部出现const，修饰的是this指针
	{
		this->mI = 100;//报错，防止this指针修改其他内容，即const Test* const this
		return this->mI;
	}
	//static成员函数，只能返回static成员变量
	static int s_getI()
	{
		//普通成员变量，是属于某个对象的，而static成员变量，没有this指针
		//return this->mI;//报错
		//return mI;//报错
		return s_k;//正确
	}
#endif
private:
	int mI;
	static int s_k;
};

int Test::s_k = 0;

/*
struct Test
{
	int mI;
};
void Test_init(Test* pthis,int i)
{
	pthis->mI = i;
}
int Test_getI(struct Test * pthis)
{
	return pthis->mI;
}
*/

int main()
{
	Test t1(10);//即Test(&t1,10);
	Test t2(20);//即Test(&t2,10);
	//成员函数通过this指针，调用各自对象的属性/方法

	t1.getI();//即getI(&t1);
	t2.getI();//即getI(&t2);

	return 0;
}