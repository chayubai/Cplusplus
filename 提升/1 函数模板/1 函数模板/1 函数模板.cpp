#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//1、普通函数实现不同数据类型的两个值的交换
void mySwapInt(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void mySwapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}
void test1()
{
	int a = 10;
	int b = 20;
	mySwapInt(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	double c = 3.14;
	double d = 5.16;
	mySwapDouble(c, d);
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
}

//2、利用模板实现通用交换函数
template<typename T> //template 模板  typename 类型名称  模板声明。等价template<class T> 
//T 数据类型名(可以取任意名)，代表一个通用的数据类型，告诉编译器如果下面紧跟着的函数或者类中出现T不要报错
//函数中需要几个变量，就定义几个T。template<typename T1,typename T2,...>
void mySwap(T& a, T& b)//函数模板实现
{
	T temp = a;
	a = b;
	b = temp;
}
//以上template<typename T>下面 紧跟着 是函数，就是函数模板，紧跟着是类，就是类模板

template<typename T>//下面必须紧跟着函数或类，即：只对第一个函数生效。
//如果只注释掉上面一行，只是根据上面的模板声明，mySwap2中是无法使用T的，因为没有紧跟着
void mySwap2()//如果该函数是void mySwap2(T a)调用是参数进行匹配
{//虽然没有参数，但函数体可能会用到T
	//T a;//如果只注释掉该行，该函数无法使用，报错。模板不能单独使用，必须指定T才能使用
}

void test2()
{
	int a = 10;
	int b = 20;

	//1、自动类型推导，必须推导出和模板一致的T数据类型，才可以正常的使用模板
	//使用自动类型推导，模板函数的T必须和传入的值严格类型匹配
	mySwap(a, b);//编译器根据你传的值，进行类型自动推导，去替换T
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	double c = 3.14;
	double d = 5.16;
	mySwap(c, d);
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	char c = 'a';
	//mySwap(a, c);//推导不出一致的T，不知道T到底是int类型还是char类型。因此无法调用
	//自动类型推导不能发生隐式类型转换，函数模板可以设计成template<typename T1,typename T2>void mySwap(T1& a, T2& b)

	//通过调试可知道，是调用普通函数还是模板函数
}

void test3()
{
	int a = 10;
	int b = 20;

	//2、显式指定类型
	mySwap<int>(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	char c = 'a';
	//mySwap<int>(a, c);//报错。引用的类型必须一致，才能取别名，即char c = 'a';int &a = c;这种操作是错误的
	
	//如果将上面的函数模板的参数改为mySwap(T a, T b)，此时mySwap<int>(a, c)可以调用，因为char可以转换为int类型

}

void test4()
{
	//mySwap2();//报错。无参函数模板无法自动类型推导。模板不能单独使用，必须确定T的类型才能使用
	//即1、如果紧跟着的函数没有使用T，要么调用的时候显式指定T的类型 2、要么函数中使用T，模板不能单独使用

	//不管是自动推导还是显式指定类型，都是在告诉编译器T是什么数据类型，因此这种情况下使用显式指定类型
	mySwap2<int>();//告诉编译器T的类型为int
}
int main()
{
	//test1();
	//test2();
	test3();

	return 0;
}

//总结：函数模板：
//1、泛型编程 - 模板技术 特点：类型参数化