#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//需求：通过一个通用排序函数，实现对char和int类型的数据排序，排序顺序从大到小。算法：选择排序
template<typename T>//typename 和 class 一样 一般typename用于函数模板，class用于类模板
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//算法：选择排序
template<typename T>//再次声明模板，告诉编译器紧跟着下面的函数中或类中的T不要报错
void mySort1(T arr[], int sz)
{
	//外层循环：n个最大值
	for (int i = 0; i < sz; i++)
	{
		int max = i;//假设依次第i个下标的元素值最大
		//内层循环：与后面n - i个元素比较，找出最大值的下标
		for (int j = i + 1; j < sz; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		//判断算出的max和开始认定的i是否一致，如果不同交换数据
		//将每轮最终的最大数，依次放到下标为i的位置
		if (i != max)
		{
			mySwap(arr[i], arr[max]);//降序
		}
	}
}

//需求：通过一个通用排序函数，实现对char和int类型的数据排序，排序顺序从小到大。
//算法：冒泡排序
template<typename T>
void mySort2(T arr[], int sz)//void mySort2(T* arr, int sz)
{
	bool flag = false;
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)//可以对有序数组特例，进行代码优化
		{
			if (arr[j] > arr[j + 1])
			{
				flag = true;
				mySwap(arr[j], arr[j + 1]);
			}
		}
		if (flag == false)
			break;
	}
	//或者
#if 0
	for (int i = 0; i < sz; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if (arr[j] > arr[i])//从大到小
			{
				mySwap(arr[j], arr[i]);
			}
		}
	}
#endif
}

template<typename T>
void printArray(T arr[],int len)//void printArray(T* arr,int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
}

void test1()
{
	int arr[] = { 1,9,30,3,2,0,17,5,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	mySort1(arr, sz);
	printArray(arr, sz);
	cout << endl;

	char ch1[] = "helloworld";
	//int sz = sizeof(ch1) / sizeof(ch1[0]) - 1;//会计算'\0'
	int len = strlen(ch1);
	mySort1(ch1, len);
	printArray(ch1, len);
	cout << endl;

	char ch2[] = { 'b','d','n','a','e','z','c','y','w' };
	sz = sizeof(ch2) / sizeof(ch2[0]);
	mySort1(ch2, sz);
	printArray(ch2, sz);
}
void test2()
{
	int arr[] = { 1,9,30,3,2,0,17,5,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	mySort2(arr,sz);
	printArray(arr, sz);
	cout << endl;

	char ch1[] = "helloworld";
	//int sz = sizeof(ch1) / sizeof(ch1[0]) - 1;//会计算'\0'
	int len = strlen(ch1);
	mySort2(ch1, len);
	printArray(ch1, len);
	cout << endl;

	char ch2[] = { 'b','d','n','a','e','z','c','y','w' };
	sz = sizeof(ch2) / sizeof(ch2[0]);
	mySort2(ch2, sz);
	printArray(ch2, sz);
}

int main()
{
	//test1();
	test2();
	return 0;
}