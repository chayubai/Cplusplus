#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//动物类
class Animal
{
public:
	int m_Age;
};

//羊类
class Sheep:virtual public Animal
{
};

//驼类
class Tuo :virtual public Animal
{
};

//羊驼类
class SheepTuo :public Sheep,public Tuo
{
};

void test1()
{
	SheepTuo st;
	st.Sheep::m_Age = 10;//初始羊驼10岁
	st.Tuo::m_Age = 20;//初始羊驼20岁

	cout << "Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "Tuo::m_Age = " << st.Tuo::m_Age << endl;
	//最后无法辨别羊驼到底多少岁

	//通过开发人员命令提示工具查看SheepTuo类的，成员分部情况

	//虚继承的方法，关键字virtual
	//将两个父类，用虚继承继承他们的父类Animal，此时他们的父类为虚基类
}

void test2()
{
	//虚继承的方法，关键字virtual
	SheepTuo st;
	st.Sheep::m_Age = 10;
	st.Tuo::m_Age = 20;

	cout << "Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "Tuo::m_Age = " << st.Tuo::m_Age << endl;

	cout << "SheepTuo.m_Age = " << st.m_Age << endl;
	//此时第一次初始羊驼10岁，第二次初始羊驼20岁（覆盖），最终羊驼20岁，此时结果唯一了

	//再通过开发人员命令提示工具查看SheepTuo类的，成员分部情况
	//此时SheepTuo类继承的两个父类中的m_Age都为vbptr = virtual base pointer虚基类指针
	//虚基类指针都会指向vbtbale虚基类表，通过偏移量都可以找到虚基类中的m_Age

	//当发生虚继承后，sheep和tuo类中继承了一个bvptr指针，称为虚基类指针，指向的是虚基类表vbtable
	//虚基类表中记录了 偏移量，通过偏移量可以找到唯一的m_Age，印次最终继承的是Animal类的m_Age
}

void test3()
{
	SheepTuo st;
	st.m_Age = 10;

	//通过Sheep找到偏移量
	//和开发人员命令提示工具SheepTuo类的成员分部对比，验证
	//&st//找到首地址
	//*(int*)&st//解引用到了 虚基类表中
	cout << *((int*)*(int*)&st + 1) << endl;

	//通过Tuo找到偏移量
	cout << *((int *)*((int*)&st + 1) + 1) << endl;

	//通过偏移量访问m_Age
	cout << "SheepTuo.m_Age = " << ((Animal*)((char*)&st + *((int *)*(int *)&st+1)))->m_Age << endl;
	cout << "SheepTuo.m_Age = " << *((int *)((char*)&st + *((int*)*(int*)&st + 1)))<< endl;
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}

















#if 0
class Furniture//材质
{
public:
	int m;
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
	return 0;
}

#endif

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

//int main()
//{
//	Bed b;
//	b.sleep();
//
//	Sofa s;
//	s.sit();
//
//	cout << "------------" << endl;
//
//	SofaBed sb;
//	sb.SleepAndSit();
//
//	sb.m = 100;//访问不明确
//	return 0;
//}
