#define _CRT_SECURE_NO_WARNINGS 1
 
#include "MyArray.h"
#include <iostream>
using namespace std;

int main()
{
#if 0
	MyArray array1(10);//开辟10个元素的数组
	//赋值操作
	for (int i = 0; i < 10; i++)
	{
		array1.setData(i, i + 10);
	}
	cout << "------------" << endl;
	cout << "array1:";
	//打印
	for (int i = 0; i < 10; i++)
	{
		cout << array1.getData(i) << " ";
	}
	cout << endl;

	MyArray array2 = array1;//array2的拷贝构造函数
	cout << "array2:";

	for (int i = 0; i < array2.getLen(); i++)
	{
		cout << array2.getData(i) << " ";
	}
	cout << endl;

	MyArray array3;
	array3 = array1;
	cout << "array3:";

	for (int i = 0; i < array3.getLen(); i++)
	{
		cout << array3.getData(i) << " ";
	}
	cout << endl;
#endif

#if 0
	MyArray array1(10);//开辟10个元素的数组
	//赋值操作
	for (int i = 0; i < 10; i++)
	{
		array1[i] = i + 10;//space[i] = i+10
	}
	cout << "------------" << endl;
	cout << "array1:";
	//打印
	for (int i = 0; i < 10; i++)
	{
		cout << array1[i] << " ";
	}
	cout << endl;

	MyArray array2 = array1;//array2的拷贝构造函数
	cout << "array2:";

	for (int i = 0; i < array2.getLen(); i++)
	{
		cout << array2[i] << " ";
	}
	cout << endl;

	MyArray array3;
	array3 = array1;
	cout << "array3:";

	for (int i = 0; i < array3.getLen(); i++)
	{
		cout << array3[i] << " ";
	}
	cout << endl;
#endif

#if 0
	MyArray array1(10);//开辟10个元素的数组
	//赋值操作
	for (int i = 0; i < 10; i++)
	{
		array1[i] = i + 10;//space[i] = i+10
	}

	cout << "array1:";
	//打印
	for (int i = 0; i < 10; i++)
	{
		cout << array1[i] << " ";
	}
	cout << endl;

	cout << "------------" << endl;

	MyArray array3(20);//原数组有内容
	array3 = array1;
	cout << "array3:";
	cout << array3 << endl;
#endif

#if 0
	MyArray array3(5);
	cin >> array3;
	cout << "array3:";
	cout << array3 << endl;
#endif

#if 0
	MyArray array1(10);//开辟10个元素的数组
	//赋值操作
	for (int i = 0; i < 10; i++)
	{
		array1[i] = i + 10;//返回的是space[i],由于可以当左值，返回类型为引用
	}

	cout << "array1:";
	//打印
	for (int i = 0; i < 10; i++)
	{
		cout << array1[i] << " ";
	}
	cout << endl;

	MyArray array3(10);
	cin >> array3;
	cout << "array3:" << array3 << endl;

	if (array3 == array1)
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}
#endif

	MyArray array1(10);//开辟10个元素的数组
	//赋值操作
	for (int i = 0; i < 10; i++)
	{
		array1[i] = i + 10;//space[i] = i+10
	}

	cout << "array1:";
	//打印
	for (int i = 0; i < 10; i++)
	{
		cout << array1[i] << " ";
	}
	cout << endl;

	MyArray array3(10);
	cin >> array3;
	cout << "array3:" << array3 << endl;

	if (array3 != array1)
	{
		cout << "不相等" << endl;
	}
	else
	{
		cout << "相等" << endl;
	}
	return 0;
}