#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <iostream>
using namespace std;//如果不添加这一行代码，cout和endl会报“未声明的标识符”
//iostream 提供了一个叫命名空间的东西，已经定义好了一个标准的命名空间是std，
//即需要使用cout，要指明是那个命名空间的cout
//由于方便后续代码中要使用命名空间std下的变量，于是告诉编译器使用命名空间std
int main()
{
	cout << "hello world" << endl;

	return 0;
}
#endif 

#if 0
#include <iostream>
int main()
{
	//方法一
	std::cout << "hello world" << std::endl;
	//std::cout iostream库下的标准命名空间std的cout,“::表示从属关系”
	//即iostream库定义了一个std的空间，通过外部声明using namespace std才能使用里面的变量
	//为了防止命名冲突，如定义了一个全局变量为cout，此时主函数中使用cout就会冲突
	//故，使用前需要指定命名空间
	std::cout << "nihao shijie" << std::endl;
	//这种方法不方便
	return 0;
}
# endif

#if 0
#include <iostream>
//方法二，全局声明，所有使用的cout、endl都是来自std命名空间
using std::cout;//using 关键字，用来声明命名空间的一个变量
using std::endl;

int main()
{
	cout << "nihao shijie" << endl;
	return 0;
}
#endif

#if 0
//C的输入输出
#include <stdio.h>
int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("a = %d\n", a);

	return 0;
}
#endif

#if 0
//C++的输入输出
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
//由于每次使用一个输入输出，就需要引入一个对应的命名空间的变量，不方便
int main()
{
	int a = 0;
	cin >> a;//cin >> 可暂时理解为，从键盘上输入，流向变量a中，等同于cin.get()或者getchar()
	cout << "a =" << a << endl;

	return 0;
}
#endif

#include <iostream>
//方法三，将整个命名空间，作为全局引入
using namespace std;
int main()
{
	int a = 0;
	cin >> a;
	cout << "a = " << a << endl;
	return 0;
}
