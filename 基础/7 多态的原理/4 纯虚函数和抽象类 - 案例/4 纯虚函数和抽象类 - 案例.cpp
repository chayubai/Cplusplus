#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//基类 - 抽象制作饮品
class AbstractDrinking 
{
public:
	//烧水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brev() = 0;
	//倒入杯中
	virtual void PourCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;

	//规定流程
	void MakeDrink()
	{
		Boil();
		Brev();
		PourCup();
		PutSomething();
	}
};
//制作咖啡
class Coffee :public AbstractDrinking
{
public:
	//烧水
	virtual void Boil()
	{
		cout << "煮农夫山泉！" << endl;
	}
	//冲泡
	virtual void Brev()
	{
		cout << "冲泡咖啡！" << endl;
	}
	//倒入杯中
	virtual void PourCup()
	{
		cout << "将咖啡倒入杯中！" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入牛奶！" << endl;
	}
};

//制作茶水
class Tea :public AbstractDrinking
{
public:
	//烧水
	virtual void Boil()
	{
		cout << "煮自来水！" << endl;
	}
	//冲泡
	virtual void Brev()
	{
		cout << "冲泡茶叶" << endl;
	}
	//倒入杯中
	virtual void PourCup()
	{
		cout << "将茶水倒入杯中！" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入食盐！" << endl;
	}
};

//业务函数
void DoBussiness(AbstractDrinking* drink)//父类指针指向子类对象
{
	drink->MakeDrink();
	delete drink;
}
void test()
{
	DoBussiness(new Coffee);
	
	cout << "----------" << endl;

	DoBussiness(new Tea);
}


int main()
{
	test();
	return 0;
}
