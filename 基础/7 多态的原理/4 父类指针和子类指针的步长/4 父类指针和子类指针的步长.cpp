#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 0

class Parent
{
public:
	Parent(int a)
	{
		cout << "Parent(int a)..." << endl;
		this->a = a;
	}
	virtual void print()
	{
		cout << "Parent::print()...a = " << a << endl;
	}

	int a;
};
class Child :public Parent
{
public:
	Child(int a) :Parent(a)
	{
		cout << "Child(int a)..." << endl;
	}
	virtual void print()
	{
		cout << "Child::print()...a = " << a << endl;
	}
};

void test()
{
	Child array[] = { Child(0),Child(1),Child(2) };

	//注意Child(0),Child(1),Child(2)这个不是匿名对象
	//因为：arry[0] = Child(0),arry[1] = Child(1),arry[2] = Child(2),有对象接收

	for (int i = 0; i < 3; i++)
	{
		array[i].print();
	}
}

void test2()
{
	Child array[] = { Child(0),Child(1),Child(2) };

	Parent* pp = &array[0];//父类指针指向子类对象
	Child* cp = &array[0];

	pp->print();
	cp->print();

	pp++;
	cp++;

	//由于父类的指针指向子类的对象时，子类对象和父类对象的空间相同
	//导致两个对象的指针++时，对象增加的步长相同
	pp->print();
	cp->print();
}
void test3()
{
	Child array[] = { Child(0),Child(1),Child(2) };
	Parent* pp = &array[0];
	int i = 0;
	for (pp = &array[0], i = 0; i < 3; i++, pp++)
	{
		pp->print();
	}
	//由于父类的指针指向子类的对象时，子类对象和父类对象的空间相同（内容相同，大小相等）
	//访问子类对象时，当父类对象的指针++时，实际上就是跨的步长就是子类对象的步长
}
#endif

class Parent
{
public:
	Parent(int a)
	{
		cout << "Parent(int a)..." << endl;
		this->a = a;
	}
	virtual void print()
	{
		cout << "Parent::print()...a = " << a << endl;
	}

	int a;
};
class Child :public Parent
{
public:
	Child(int a) :Parent(a)
	{
		cout << "Child(int a)..." << endl;
	}
	virtual void print()
	{
		cout << "Child::print()...a = " << a << endl;
	}

	int b;
};
void test3()
{
	Child array[] = { Child(0),Child(1),Child(2) };
	Parent* pp = &array[0];
	Child* cp = &array[0];
	int i = 0;
	/*for (pp = &array[0], i = 0; i < 3; i++, pp++)
	{
		pp->print();
	}*/
	//由于父类的指针指向子类的对象时，子类对象和父类对象的空间大小不同
	//访问子类对象时，当父类对象的指针++时，子类对象的步长大于父类对象的步长，访问就会出问题

	//解决方法：
	for (cp = &array[0], i = 0; i < 3; i++, cp++)
	{
		cp->print();
	}

	//注意：指针的++不会发生多态，
	//pp指针的++是加的sizeof(Parent)大小
	//cp指针的++是加的sizeof(Child)大小
}

int main()
{
	

	return 0;
}