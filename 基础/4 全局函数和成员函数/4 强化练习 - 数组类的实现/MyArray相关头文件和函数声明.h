#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
using namespace std;

class MyArray
{
public:
	//无参构造函数，用户没有指定容量，则初始化为100
	MyArray();

	//有参构造函数，用户指定容量初始化
	explicit MyArray(int capacity);//explicit防止MyArray arr = 100的创建方式

	//拷贝构造函数
	MyArray(const MyArray& arr);

	//用户操作接口
	//根据位置添加元素
	void setData(int pos, int val);

	//获取指定位置数据
	int getData(int pos);

	//尾插法
	void pushBack(int val);

	//获取数组容量
	int getCapcity();

	//获取数组大小
	int getSize();

	//析构函数，释放堆区上数组空间
	~MyArray();

	//重载[]运算符
	//int operator[](int index);
	int& operator[](int index);

private:
	int m_Capacity;//数组一共可容纳多少个元素，即数组容量

	int m_Size;//当前有多少个元素，即数组大小

	int* pAdress;//指向存储数据的空间，用来维护堆区上开辟的数组空间的指针
};