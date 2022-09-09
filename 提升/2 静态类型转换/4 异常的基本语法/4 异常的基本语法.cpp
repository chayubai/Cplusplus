#define _CRT_SECURE_NO_WARNINGS 1

//异常处理就是处理程序中的错误。所谓错误是指在程序运行的过程中发生的一些异常事件
//(如：除0溢出，数组下标越界，所要读取的文件不存在，空指针，内存不足等等。)

#if 0
#include <stdio.h>
//C语言中的异常，有缺陷，返回值不统一，返回值只有一个，无法区分是结果还是异常。
int myDivision(int a, int b)
{
	if (b == 0)
	{
		return -1;//假设10 -10，就会造成误判
	}
	return a / b;
}
void test1()
{
	int a = 10;
	int b = 0;
	int ret = myDivision(a, b);
	if (ret == -1)
	{
		printf("异常");
	}
}
void test2()
{
	int a = 10;
	int b = -10;
	int ret = myDivision(a, b);
	if (ret == -1)
	{
		printf("异常");
	}
}//如果异常不处理，经过多层函数调用，最终程序就会异常

int main()
{
	test1();
	test2();
	return 0;
}
#endif

#include <iostream>
using namespace std;

class MyException
{
public:
	void printError()
	{
		cout << "我自己的异常"<< endl;
	}
};

int myDivision(int a, int b)
{
	if (b == 0)
	{
		//抛出的异常数据类型，必须严格匹配
		//throw -1;//-1代表int类型，也可以用其他int数据。表示抛出int类型的异常
		//throw 'a';//抛出char类型的异常
		//throw 3.14;//抛出double类型的异常
		//...
		/*string str = "abc";
		throw str;*///抛出string类型的异常

		throw MyException();//抛出MyException的匿名对象
	}
	return a / b;
}
void test()
{
	int a = 10;
	int b = 0;
	try//尝试执行以下代码检测是否异常，如果异常则进行处理，如果没有异常catch段代码是不会执行
	{
		myDivision(a, b);
	}
	//异常的捕获后，进行处理
	catch (int)//异常时，根据抛出的值的类型进行匹配。
	{
		cout << "int类型异常捕获" << endl;
	}
	//如果程序监测到异常，当抛出的异常，没有与之对应的异常捕获和处理，就会报错终止
	//注意：如果没有人去处理抛出的异常，程序就会终止
	catch (char)
	{
		cout << "char类型异常捕获" << endl;
	}
	catch (MyException e)//自定义类型的异常处理
	{
		e.printError();
	}
	/*catch (double)
	{
		throw;//捕获到了异常，但是不想处理，继续向上抛出这个异常
		cout << "double类型异常捕获" << endl;//这一行不会执行
	}
	catch (...)//...代表其他类型
	{
		cout << "其他类型异常捕获" << endl;
	}*/

}
int main()
{
	try
	{
		test();
	}
	catch(double)
	{
		cout << "main函数中 double类型异常捕获" << endl;
	}
	catch (...)
	{
		cout << "main函数中 其他类型异常捕获" << endl;
	}
	//先尝试执行main函数中的test()并检测是否异常，
	//当执行到调用myDivision(a, b)时，再尝试执行myDivision(a, b)并检测是否异常，
	//如果此时代码异常了就会抛出相应的异常信息，让上一层test处理异常 (此时test会先处理异常，而不是上上一层main处理) 。
	//如果test是最后一层，没有处理异常也不抛出异常，程序就会终止。如果test不是最后一层，且没有对异常进行处理，但是下一层对其进行处理了，则程序不会终止。
	
	//如果此时上一层不想处理该异常可以使用关键字throw继续抛出异常，给test的上一层即main来处理。
	//如果main中没人去处理抛出的异常，程序就会终止

	//即如果有异常就需要进行处理，必须有一层去处理，否则程序就会自动调用terminate函数，让程序终止
	
	return 0;
}