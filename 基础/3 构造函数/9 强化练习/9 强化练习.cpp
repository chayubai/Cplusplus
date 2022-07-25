#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0
class ABCD
{
public:
	ABCD(int a, int b, int c)
	{
		_a = a;
		_b = b;
		_c = c;
		printf("ABCD()  construct, a:%d,b:%d,c:%d\n", _a, _b, _c);
	}
	~ABCD()
	{
		printf("~ABCD()  construct, a:%d,b:%d,c:%d\n", _a, _b, _c);
	}
	int getA()
	{
		return _a;
	}
private:
	int _a;
	int _b;
	int _c;
};

class MyE
{
public:
	MyE():abcd1(1,2,3),abcd2(4,5,6),m(100)
	{
		cout << "MyE()" << endl;
	}
	~MyE()
	{
		cout << "~MyE()" << endl;
	}
	MyE(const MyE &obj):abcd1(7, 8, 9), abcd2(10, 11,12), m(100)
	{
		cout << "MyE(const MyE &obj)" << endl;
	}
public:
	ABCD abcd1;
	ABCD abcd2;
	const int m;
};

int doThing(MyE mye1)//mye1拷贝构造
{
	printf("doThing()  mye1.abc1.a:%d\n", mye1.abcd1.getA());
	return 0;
}
int run()
{
	MyE myE;
	doThing(myE);
	return 0;
}
int run2()
{
	printf("run2  start...\n");
	//匿名对象，创建后，立即调用析构函数
	ABCD(400, 500, 600);
	printf("run2  end...\n");
	return 0;
}
int run3()
{
	printf("run2  start...\n");
	ABCD abcd = ABCD(100, 200, 300);
	printf("run2  end...\n");
	return 0;
}

int main()
{
	//run();
	run2();
	//run3();
	return 0;
}
#endif

//构造中调用构造是危险的行为
class MyTest
{
public:
	MyTest(int a, int b, int c)
	{
		_a = a;
		_b = b;
		_c = c;
	}
	MyTest(int a, int b)
	{
		_a = a;
		_b = b;
		//产生新的匿名对象与t无关，后会立即销毁
		MyTest(a, b, 100);
	}
	~MyTest()
	{
		printf("MyTest~:%d,%d,%d\n", _a, _b, _c);
	}
	int getC()
	{
		return _c;
	}
	void setC(int val)
	{
		_c = val;
	}

private:
	int _a;
	int _b;
	int _c;
};

int main()
{
	MyTest t1(1, 2);
	printf("c:%d\n", t1.getC());
}