#define _CRT_SECURE_NO_WARNINGS 1
#if 0
//1、全局变量检查增强，C++检测出重定义
#include <iostream>
using namespace std;
//C++语言全局变量定义，不可以重复定义，会报错
int g_val;
int g_val = 20;
int main()
{
	cout << g_val << endl;
	return 0;
}
#endif

#if 0
//2、函数检测增强：返回类型检测，返回值检测，形参类型检测，函数调用参数个检测
#include <iostream>
using namespace std;
func()
{
	return 10;
}
int gunc(int a)
{
	return 20;
}
int main()
{
	//C++语言的函数实现，可以有返回值，一定需要有返回类型，否则会报错
	func();
	//C++语言的函数实现，当无参数时，而传入参数时或传入不匹配的数量的参数时，程序编译报错
	gunc(10, 20, 30);

	return 0;
}
#endif

#if 0
//3、类型转换检测增强
#include <iostream>
using namespace std;
int main()
{
	//必须类型转换
	char* p = (char*)malloc(64);

	return 0;
}
#endif

#if 0
//4、struct增强:C++可以放函数（声明），变量定义可以不加关键字struct
#include <iostream>
using namespace std;
struct student
{
	int id;
	char name[20];
	void func()
	{

	}
};
int main()
{
	//C++语言结构体变量的定义，可以加上struct
	struct student s1;
	student s2;
	s2.func();
	return 0;
}
#endif

#if 0
//5、bool类型扩展，C语言下没有这个类型，C++有bool类型
#include <iostream>
using namespace std;
int main()
{
	//C++语言的真1、假0。非0为真，0为假。且增加了bool类型，该类型的值只能取1或0
	bool flag = true;
	cout << "flag(true):" << flag << endl;

	flag = false;
	cout << "flag(false):" << flag << endl;

	flag = -20;
	cout << "flag(-20):" << flag << endl;

	//bool类型的大小为1个字节
	cout << "bool的大小:" << sizeof(bool) << endl;

	return 0;
}
#endif

#if 0
//6、三目运算符增强
#include <iostream>
using namespace std;
int main()
{
	//C++语言的三目运算符
	int a = 10;
	int b = 20;
	int c = a < b ? a : b;
	cout << c << endl;

	//C++语言的三目运算符，访问的是变量的引用，可以直接当左值
	//返回的是引用
	(a < b ? a : b) = 50;//C++下返回的是变量，a = 50
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	a < b ? a : b = 50;//C++下返回的是变量，即a < b ? a : (b = 50)
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	return 0;
}
#endif

#if 0
//7、const增强
#include <iostream>
using namespace std;
const int m_A = 100;//全局const，和C语言结论一致
int main()
{
	//C++语言，const修饰的变量a的值可以通过指针不能被改变
	const int a = 10;//局部const  a是真正的常量
	//const存放在符号表中，以key，value键值对的形式对应，即key：a，value：10

	int* p = (int*)&a;//这里C++严格类型转换，由于&a是const int*类型，要强转为int*
	*p = 50;//*p改变的是临时开辟的temp
	
	cout << "a = " << a << endl;
	//这里a的值没有发生变化
	cout << "*p = " << *p << endl;
	//*p = 50修改的是什么？
	//int temp = a;int *p = &temp;
	//当对const修饰的局部变量取地址的时候，编译器在栈上给变量分配临时内存空间temp
	//p指针指向的是temp

	//C++语言，const修饰的变量a，是常量，可以初始化数组
	int array[a] = { 0 };
	return 0;
}
#endif

#if 0
//8、
#include <iostream>
using namespace std;
int main()
{
	int a = 10;
	cout << a << endl;

	int i = 0;
	//C++变量的定义，随用随定义
	for (i = 0; i < 10; i++)
	{
		cout << i << " ";
	}
	return 0;
}
#endif



#if 0
//9、
#include <iostream>
enum season
{
	SPR = 0,
	SUM,
	AUT,
	WIN
};
int main()
{
	//C++语言枚举类型变量，不可以赋值为整型值，否则会报错
	//enum season s = 0;
	enum season s = SPR;
	if (s == 3)
	{
		//...
	}
	return 0;
}
#endif