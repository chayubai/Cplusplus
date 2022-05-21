#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <iostream>
using namespace std;
void change_value1(int p)
{
	p = 30;
}
void change_value2(int* p)
{
	*p = 30;
}
void change_value3(int& r)//int &r = a
{
	r = 50;//r是a的别名
}
int main()
{
	int a = 10;
	change_value1(a);
	cout << "a = " << a << endl;
	a = 10;
	change_value2(&a);
	cout << "a = " << a << endl;
	a = 10;
	change_value3(a);
	cout << "a = " << a << endl;
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
//数据作为值传递
void swap1(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
//地址传递
void swap2(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//地址作为值传递
void swap3(int* a, int* b)
{
	int* tmp = a;
	a = b;
	b = tmp;
}
//引用传递
void swap4(int& ra, int& rb)
{
	int tmp = ra;
	ra = rb;
	rb = tmp;
}

void test1()
{
	int a = 10;
	int b = 20;
	swap1(&a, &b);
	swap2(&a, &b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "---------- " << endl;
	swap3(a, b);
	swap4(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

//引用注意事项
int& func()
{
	int a = 10;//当func()执行完后，a被释放掉了
	return a;//int& temp = a
}
void test2()
{
	//int& a = 10;//1、引用必须引一块合法的内存空间

	//2、不要返回局部变量的引用
	int& ref = func();//int& ref = temp = a，即ref也是a的别名
	cout << "ref = " << ref << endl;
	cout << "ref = " << ref << endl;
	cout << "ref = " << ref << endl;
}

int& func2()
{
	static int a = 10;
	return a;
}
void test3()
{
	int& ref = func2();
	cout << "ref = " << ref << endl;
	cout << "ref = " << ref << endl;
	cout << "ref = " << ref << endl;

	//当函数返回值是引用，那么函数的调用可以作为左值
	func2() = 1000;//对ref进行赋值
	cout << "ref = " << ref << endl;

}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
struct student
{
	int id;
	char name[20];
};
void printS1(struct student s)//不推荐
{
	cout << s.id << " " << s.name << endl;
}
void printS2(struct student* ps)
{
	cout << ps->id << " " << ps->name << endl;
}
void printS3(struct student& rs)
{
	cout << rs.id << " " << rs.name << endl;
}
int main()
{
	struct student s = { 19, "zhangsan" };
	printS1(s);//值传递

	struct student* ps = &s;
	printS2(ps);//址传递

	printS3(s);

	return 0;
}
#endif
 