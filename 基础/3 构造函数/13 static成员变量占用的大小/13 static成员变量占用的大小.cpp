#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0 
//static成员变量，是属于类的，而不属于某个对象的，它的空间不在栈上，而在静态区
class C1
{
public:
	int i;//4
	int j;//4
	int k;//4
};
class C2
{
public:
	int i;
	int j;
	int k;
	static int m;//4
public:
	int getK()//4
	{
		return k;
	}
	void setK(int val)//4
	{
		k = val;
	}
};
struct S1
{
	int i;
	int j;
	int k;
};
struct S2
{
	int i;
	int j;
	int k;
	static int m;
};
int main()
{
	//只有对象的非静态的成员变量才在栈上占用空间，静态成员变量的空间在静态区共享开辟的空间
	cout << "C1:" << sizeof(C1) << endl;
	cout << "C2:" << sizeof(C2) << endl;
	//成员函数的空间不属于对象
	C2 c1, c2;
	c1.getK();//为什么会return c1.k
	c2.getK();//为什么会return c2.k

	cout << "---------------" << endl;

	//只有非静态的变量才在栈上占用空间，静态变量的空间在静态区共享开辟的空间
	cout << "S1:" << sizeof(S1) << endl;
	cout << "S2:" << sizeof(S2) << endl;
	return 0;
}
#endif

class Test
{
public:
	Test(int i)
	{
		mI = i;
	}
	int getI()
	{
		return mI;
		//this就是指向调用该成员函数方法的对象的地址
		//return this->mI;
	}
#if 0
	int getI(Test *this)
	{
		return this->mI;
	}
#endif

private:
	int mI;
};
#if 0
//会将上面的类翻译为下面这种指针类型
//Test t1(10);即Test(&t1,10);和t1.getI();即getI(&t1);
struct Test 
{
	int mI;
};
void Test(struct Test* pthis,int i)
{
	pthis->mI = i;
}
int getI(struct Test *pthis)
{
	return pthis->mI;
}
#endif
int main()
{
	Test t1(10);//即Test(&t1,10);
	t1.getI();//即getI(&t1);
	Test t2(20);//即Test(&t2,10);
	t2.getI();//即getI(&t2);
	return 0;
}