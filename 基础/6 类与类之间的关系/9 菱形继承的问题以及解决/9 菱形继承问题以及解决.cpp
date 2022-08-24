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
	//st.m_Age = 10;//报错：访问不明确
	st.Sheep::m_Age = 10;//初始羊驼10岁
	st.Tuo::m_Age = 20;//初始羊驼20岁

	cout << "Sheep::m_Age = " << st.Sheep::m_Age << endl;//10
	cout << "Tuo::m_Age = " << st.Tuo::m_Age << endl;//20
	//最后无法辨别羊驼到底多少岁

	//通过开发人员命令提示工具查看SheepTuo类的，成员分部情况（类的大小：8字节）

	//菱形继承问题如何解决？
	//虚继承的方法，关键字virtual
	//将两个父类Sheep和Tuo的继承方式改为虚继承，即用虚继承继承他们的父类Animal，此时他们的父类为虚基类
	//操作的是共享的一份数据
}

void test2()
{
	//虚继承的方法，关键字virtual
	SheepTuo st;
	st.Sheep::m_Age = 10;
	st.Tuo::m_Age = 20;

	cout << "Sheep::m_Age = " << st.Sheep::m_Age << endl;//20
	cout << "Tuo::m_Age = " << st.Tuo::m_Age << endl;//20

	cout << "SheepTuo.m_Age = " << st.m_Age << endl;//不会再有二义性
	//此时第一次初始羊驼10岁，第二次初始羊驼20岁（覆盖），最终羊驼20岁，此时结果唯一了

	//再通过开发人员命令提示工具查看SheepTuo类的，成员分部情况（类的大小：12字节）
	//此时SheepTuo类继承的两个父类中的m_Age都为vbptr = virtual base pointer虚基类指针
	//各自的虚基类指针都会指向各自的vbtbale虚基类表，通过虚基类表中各自的偏移量都可以找到虚基类中的m_Age
	//8 <SheepTuod<Sheep+0>Animal>,前面的8即为偏移量，通过指针0 + 8找到m_Age

	//当发生虚继承后，sheep和tuo类中继承了一个bvptr指针，称为虚基类指针，指向的是虚基类表vbtable
	//虚基类表中记录了 偏移量，通过偏移量可以找到唯一的m_Age，因此最终继承的是Animal类的m_Age
}

//虚继承的内部工作原理：
void test3()
{
	SheepTuo st;
	st.m_Age = 10;

	//通过Sheep找到偏移量
	//和开发人员命令提示工具SheepTuo类的成员分部对比，验证
	//&st//找到首地址
	//(int*)&st  强转为int* 找到羊类的步长
	//*(int*)&st  解引用到了 虚基类表中
	//(int*)*(int*)&st 强转为int* 找到虚基类表中的步长
	//((int*)*(int*)&st + 1)  +1跳到虚基类表指向m_Age的位置
	//*((int*)*(int*)&st + 1) 解引用找到m_Age
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