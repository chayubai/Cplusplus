#define _CRT_SECURE_NO_WARNINGS 1
#include "MyArray相关头文件和函数声明.h"

void test1()
{
	MyArray arr;//测试无参构造
	for (int i = 0; i < 10; i++)
	{
		arr.pushBack(i);
	}
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr.getData(i) << " ";
	}
	cout << endl;
}

void test2()
{
	MyArray arr;
	for (int i = 0; i < 10; i++)
	{
		arr.pushBack(i);
	}
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr.getData(i) << " ";
	}
	cout << endl;

	MyArray arr2(arr);//测试拷贝构造
	for (int i = 0; i < arr2.getSize(); i++)
	{
		cout << arr2.getData(i) << " ";
	}
	cout << endl;
}

void test3()
{
	MyArray arr;
	for (int i = 0; i < 10; i++)
	{
		arr.pushBack(i);
	}
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr.getData(i) << " ";
	}
	cout << endl;

	arr.setData(0, 1000);
	cout << "arr下标为0的位置的数据：" << arr.getData(0) << endl;
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr.getData(i) << " ";
	}
	cout << endl;

	cout << "数组容量为："<<arr.getCapcity() << endl;
	cout << "数组大小为：" << arr.getSize() << endl;

	//如何：利用[]方式去索引数组中的元素，可读可写？
	//arr[0] = 100;
	//cout << arr[0] << endl;
}

void test4()
{
	MyArray arr;
	for (int i = 0; i < 10; i++)
	{
		arr.pushBack(i);
	}
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr.getData(i) << " ";
	}
	cout << endl;
	//如何：利用[]方式去索引数组中的元素，可读可写？
	//arr[0] = 100;
	//cout << arr[0] << endl;

	cout << arr[9] << endl;

	arr[9] = 100;//由于返回类型是int，所以arr[9]的返回值是数值，不允许作为左值

	//因此需要返回引用，才能作为左值
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr.getData(i) << " ";
	}
}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}