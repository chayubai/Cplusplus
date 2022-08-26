#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Animal
{
public: 
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
	/*virtual void eat()
	{
		cout << "动物在吃饭" << endl;
	}*/
	virtual void eat()
	{
		cout << "动物在吃饭" << endl;
	}
	/*virtual void eat(int a)
	{
		cout << "动物在吃饭" << endl;
	}*/
};

class Cat :public Animal
{
public:
	virtual void speak()
	{
		cout << "小猫在说话" << endl;
	}

	void eat()
	{
		cout << "小猫在吃饭" << endl;
	}

	/*void eat(int a)
	{
		cout << "小猫在吃饭" << endl;
	}*/
};

void doSpeak(Animal& animal)
{
	animal.speak();
}

void test1()
{
	Cat cat;
	doSpeak(cat);
}

void test2()
{
	cout << "size of Ainmal = " << sizeof(Animal) << endl;
	//当没有添加父类virtual关键字，此时是一个空类，占1个字节

	//当添加了virtual关键字，此时该类占4个字节

	//当父类Animal添加了virtual关键字后，类的内部多出来一个指针，即vfptr（virtual function pointer 虚函数表指针）
	//该指针指向虚函数表（vftable），由于是成员函数，虚函数表的内部记录了虚函数的入口地址&Animal::speak
	//当Cat类仅仅是继承Animal类，则Cat类内部结构的虚函数指针指向Cat类的虚函数表的内容也是：&Animal::speak
	//当Cat类发生父类虚函数重写，则Cat类内部结构的虚函数指针指向Cat类的虚函数表的内容变为：&Cat::speak

	//注意：
	//重写：指的是子类重写父类中的虚函数
	//1、函数返回值相同，2、函数名相同，3、形参列表相同 为前提

	//Animal* animal = new Cat;//创建Cat对象，让父类引用接收，animal本质上还是Cat对象
	//animal -> speak();//此时就会调用Cat::speak()

	//验证：
	//通过开发人员命令提示工具，查看
	//1、当父类没有virtual关键字的父类，此时的Cat类布局情况：为空类 - 继承的是空
	//2、当父类加上virtual关键字，但Cat类没有重写speak函数（没有该函数时），此时的Cat类的布局情况：继承了父类的一个虚函数指针
	//从父类继承了vfptr指针，指向自己的vftable，入口地址0处为&Animal::speak

	//3、当父类加上virtual关键字，但Cat类重写speak函数，此时的Cat类的布局情况：也是继承了父类的一个虚函数指针
	//从父类继承了vfptr指针，指向自己的vftable，入口地址0处为&Cat::speak
}

//当父类写了虚函数后，类内部结构发生改变，多了一个vfptr虚函数指针，vfptr指向虚函数表
//虚函数表内部记录着虚函数入口地址
//当父类指针或引用指向子类对象，发生多态，调用的时候从虚函数中找函数入口地址
//注意：子类和父类，虽然有相同的虚函数指针，但指向的虚函数表是各自的
//如果发生了重写，会替换虚函数表中原有的speak

//虚函数深入剖析：通过指针偏移
void test3()
{
	Animal* animal = new Cat;
	
	//*(int *)animal 强转，找到Animal类的步长，解引用到虚函数表中
	//*(int *)*(int *)animal 强转，找到Cat类的步长，解引用到函数speak地址
	//由于void speak(),该函数指针是void (*ptr)() = &speak
	//(void (*) ()) 该函数指针的类型
	//(void (*) ())(*(int*)*(int*)animal 强转，转为(void (*) ())指针类型
	//调用函数：ptr()

	//调用小猫在说话
	( (void (*) ())(*(int*)*(int*)animal) )();

	//调用小猫在吃饭
	( (void (*) ())(*( (int*)*(int*)animal + 1 )))();//由虚函数表关系，直接步长+1即可
}

void test4()
{
	Animal* animal = new Cat;
	//如果将父类函数加上int a形参，子类重写后

	//调用小猫在吃饭
	//( (void (*) (int))(*((int*)*(int*)animal + 1 )))(10);//这样直接调用会失败

	//原因：
	//用上面调用的时候，真实的调用惯例是 __stdcall
	//而C/C++默认调用惯例是 __cdecl
	
	//重新定义函数指针调用惯例为：__stdcall
	typedef void(__stdcall *FUNCPOINT)(int);

	( FUNCPOINT (*((int*)*(int*)animal + 1 )))(10);
}

int main()
{
	//test1();
	//test2();
	test3();
	//test4();
	return 0;
}