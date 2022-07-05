#pragma once
#include <iostream>
using namespace std;

class MyArray
{
public:
	//无参构造函数
	MyArray();

	//有参构造函数，用户指定长度初始化
	MyArray(int len);

	//用户操作接口
	MyArray(const MyArray& another);	

	//根据位置添加元素
	void setData(int index, int data);

	//获取指定位置数据
	int getData(int index);

	//获取长度
	int getLen();

	void operator=(const MyArray& another);

	//析构函数，释放数组空间
	~MyArray();
private:
	int len;
	int* space;
};

