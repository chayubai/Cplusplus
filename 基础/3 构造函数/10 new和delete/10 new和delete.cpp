#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0 
//C语言中，在堆上开辟空间,需要手动释放空间
void test1()
{
	//开辟变量空间
	int* p = (int*)malloc(sizeof(int));
	//判断开辟是否成功
	*p = 10;
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	//开辟数组空间
	int* array_p = (int*)malloc(sizeof(int)*10);
	//判断开辟是否成功
	for (int i = 0; i < 10; i++)
	{
		array_p[i] = i + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", array_p[i]);
	}
	printf("\n");
	if (array_p != NULL)
	{
		free(array_p);
		array_p = NULL;
	}
}

//C语言下，动态开辟空间的问题：
//1、程序必须确定对象的长度，如果长度错误，导致程序出问题
//2、malloc返回一个void*指针c++不允许将void*赋值给其他任何指针,必须强转。
//3、malloc可能申请内存失败，所以必须判断返回值来确保内存分配成功。
//4、用户在使用对象之前必须记住对他初始化，构造函数不能显示调用初始化(构造函
//数是由编译器调用)用户有可能忘记调用初始化函数。

//C++语言中，在堆上开辟空间,也需要手动释放空间,C++也可以使用malloc和free
void test2()
{
	//开辟变量空间
	int* p = new int;//开辟一个int空间，调用默认无参构造函数
	*p = 10;
	if (p != NULL)
	{
		delete p;
		p = NULL;
	}

	//int a(10);//int 本身也是一个类，调用有参构造函数赋值为10。等价于int a = 10;

	//开辟数据空间
	int* array_p = new int[10];//开辟int10个元素的数组空间，调用10次默认无参构造函数

	//int* array_p = new int(10);//开辟一个int空间，调用有参构造函数赋值为10

	for (int i = 0; i < 10; i++)
	{
		array_p[i] = i + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << array_p[i] << " ";
	}
	cout << endl;
	if (array_p != NULL)
	{
		delete[] array_p;
		array_p = NULL;
	}

}
//注意：malloc可以和delete、new可以和free相互使用
int main()
{
	test1();
	test2();
	return 0;
}
#endif

class Person
{
public:
	Person()//最好提供无参构造
	{
		cout << "调用Person()构造" << endl;
	}
	Person(int a)
	{
		cout << "调用Person(int a)构造" << endl;
	}
	~Person()
	{
		cout << "调用~Person()析构函数" << endl;
	}
};
//注意：析构函数会释放，类的成员变量和成员函数，以类为类型的变量，但不会析构引用和堆上的空间
void test()
{
	/*Person a;//栈区开辟
	Person* p = &a;
	Person* &b = p;
	cout << p << endl;
	cout << b << endl;*/

	Person* p2 = new Person;//堆区开辟
	//所有new出来的对象，都会返回该类型的指针
	//malloc返回void* 需要强转

	//以上一行代码相当于：
	/*Person* person = (Person*)malloc(sizeof(Person));
	if (person == 0)
	{
		return 0;
	}
	person->Init();//构造函数*/

	//delete p2;//delete会触发析构函数的调用
}

//malloc 和 new 区别
//1、malloc 和free 属于库函数，new和delete属于运算符
//2、malloc不会调用构造函数，free不会调用析构函数，new会调用构造函数，delete会调用析构函数
//3、malloc返回void* C++下需要强转，new返回创建的对象类型的指针
//4、malloc开辟的空间，默认没有初始化，需要显式提供init方法对空间进行初始化
//5、new开辟空间，会调用默认构造函数进行初始化

//注意事项：不要用void* 去接受new出来的对象，利用void* 无法调用析构函数
//因为不知道类型，不知道要释放多大的空间
void test2()
{
	void* p = new Person;//创建对象，并调用无参构造
	delete p;//不会触发析构函数

	//注意：C++new关键字类似与Java语言的new关键字
}

//利用new开辟数组
void test3()
{
	//int* pInt = new int[10];
	//double* pD = new double[10];

	//***堆区开辟数组，一定会调用编译器默认构造函数***，
	//即必须要有默认构造函数，否则会报错
	//如果重载了默认构造，默认构造就会没有了，无法调用默认构造函数，会导致报错
	//因此需要显示提供无参构造
	Person* p = new Person[10];//一定会调用默认构造函数

	//释放数组的时候，需要加[]
	delete[] p;//这里这样写delete p;此时只会释放一个对象，会报错
	//delete[] p;会有一个对象个数的记录，用于逐个释放数组中的所有对象
	
	//假设无参构造函数注释了
	//如果自定义了有参构造函数，没有显式定义无参构造函数，将开辟以上数据时会报错
	//因此定义有参构造的时候，建议把无参构造一起写上

	//Person* p2 = new Person(2)[10];//这样创建是错误的

	//栈上开辟数组，可以没有默认构造
	Person parr[10] = { Person(10),Person(20) };

	//Person* p2 = new Person[10]{ Person(10),Person(20) };
	//此方法不建议，因为很多编译器无法执行
}

void test4()
{
	//栈上开辟数组，可以没有默认构造函数
	Person arr[10] = { Person(10),Person(20) };
	//观察打印现象
}
int main()
{
	//test();
	//test2();
	//test3();
	test4();
	return 0;
}
