#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Base1
{
public:
	Base1()
	{
		this->m_A = 10;
		this->m_F = 0;
	}
	int m_A;
	int m_F;
};

class Base2
{
public:
	Base2()
	{
		this->m_B = 20;
		this->m_F = 1;
	}
	int m_B;
	int m_F;
};

//多继承
class Son :public Base1, public Base2
{
public:
	int m_C;
	int m_D;
};

void test1()
{
	cout << "size of Son = " << sizeof(Son) << endl;

	Son s;
	cout << "s.m_A = " << s.m_A << endl;
	cout << "s.m_B = " << s.m_B << endl;
}

void test2()
{
	Son s;
	//多继承中很容易引发二义性
	//cout << "m_F = " << s.m_F << endl; 
	
	//当多继承的两个父类有相同的成员属性名，此时需要加作用域才能区分
	cout << "Base1.m_F = " << s.Base1::m_F << endl;
	cout << "Base2.m_F = " << s.Base2::m_F << endl;

	//注意：
	//1、多继承下，多个父类同名成员的情况，会产生二义性，调用方法需要各自都加作用域，才能访问各自的同名成员
	//2、与子类和父类同名成员的情况不同。子类对象会隐藏父类同名成员，默认调用子类的同名成员
	//调用子类同名成员可不加作用域，调用父类同名成员需要加作用域
	
	//通过开发人员命令提示工具查看，多继承下的类的内存布局
}
int main() 
{
	//test1();
	test2();
	return 0;
}

#if 0
//多继承

class Furniture
{
public:
	int m;//材质
};
class Bed :public Furniture
{
public:
	void sleep()
	{
		cout << "睡觉" << endl;
	}
};
class Sofa :public Furniture
{
public:
	void sit()
	{
		cout << "休息" << endl;
	}
};

class SofaBed :public Bed, public Sofa
{
public:
	void SleepAndSit()
	{
		sleep();
		sit();
	}
};

int main()
{
	Bed b;
	b.sleep();

	Sofa s;
	s.sit();

	cout << "------------" << endl;

	SofaBed sb;
	sb.SleepAndSit();

	//sb.m = 100;//访问不明确
	sb.Bed::m = 100;
	sb.Sofa::m = 200;

	//多继承导致一个沙发床有两种材质
	return 0;
}
#endif

#if 0
//虚继承 - 菱形继承问题的解决

class Furniture//家具类
{
public:
	int m;//材质
};
//virtual:将父亲类继承爷爷类，改为虚继承，防止儿子多继承父类的时候，出现爷爷类中的变量会拷贝多份。
class Bed :virtual public Furniture
{
public:
	void sleep()
	{
		cout << "睡觉" << endl;
	}
};
class Sofa :virtual public Furniture
{
public:
	void sit()
	{
		cout << "休息" << endl;
	}
};

class SofaBed :public Bed, public Sofa
{
public:
	void SleepAndSit()
	{
		sleep();
		sit();
	}
};

int main()
{
	Bed b;
	b.sleep();

	Sofa s;
	s.sit();

	cout << "------------" << endl;

	SofaBed sb;
	sb.SleepAndSit();

	sb.m = 100;//此时只有一个m
	return 0;
}
#endif