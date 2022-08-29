#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

//如何定义一个数组指针

//方法一
//定义一个数组类型
typedef int(ARRAY_INT_10_TYPE)[10];

//方法二
//直接定义一种数组指针
typedef int(*ARRAY_INT_10_TYPE_POINTER)[10];

int main(void)
{
	int array[10];//数组类型为int[10]
	ARRAY_INT_10_TYPE array2 = { 0 };

	ARRAY_INT_10_TYPE* array_p = NULL; //指向数组类型的指针
	ARRAY_INT_10_TYPE_POINTER array_p2 = NULL;

	int* p = array;//*array数组第一个元素  int ， array是数组的名字，首元素的地址
			//是一个存放int数组的第一个元素。array+1步长为一个int大小
	array_p = &array;//*array_p是一个存放数组（int[10]）的数组的第一个元素。
			 //*(&array) = array	array_p+1步长为一个int[10]大小	
	
	for (int i = 0; i < 10; i++) {
		(*array_p)[i] = i + 10;
	}

	for (int i = 0; i < 10; i++) {
		//cout << array[i] = 10 << endl;//这样打印会报错
		cout << array[i] << endl;
		cout << array2[i] << endl;
	}

	//方法三
	int* p1[10] = { 0 };//p是指针数组 - 存放指针的数组
	int(*p2)[10] = &array;//p是数组指针 - 存放数组的指针
	for (int i = 0; i < 10; i++) {
		//cout << (*p2)[i] = i + 10 << endl;//这样打印会报错
		cout << (*p2)[i] << endl;//(*p2)[i]  = array[i]
	}
	return 0;
}