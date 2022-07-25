#define _CRT_SECURE_NO_WARNINGS 1

#include "MyArray.h"

int main()
{
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
	array3 = array1;//调用默认的=操作符函数
	cout << "array3:";

	for (int i = 0; i < array3.getLen(); i++)
	{
		cout << array3.getData(i) << " ";
	}
	cout << endl;

	return 0;
}