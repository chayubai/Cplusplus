#define _CRT_SECURE_NO_WARNINGS 1
#include "MyArray相关头文件和函数声明.h"
 
//无参构造函数，用户没有指定容量，则初始化为100
MyArray::MyArray()
{
	cout << "默认构造函数调用" << endl;//用来捕捉函数是否调用
	this->m_Capacity = 100;
	this->m_Size = 0;
	this->pAdress = new int[this->m_Capacity];
}

//有参构造函数，用户指定容量初始化
MyArray::MyArray(int capacity)//explicit防止MyArray arr = 100的创建方式
{
	cout << "有参构造函数调用" << endl;//用来捕捉函数是否调用
	this->m_Capacity = capacity;
	this->m_Size = 0;
	this->pAdress = new int[this->m_Capacity];
}

//拷贝构造函数
MyArray::MyArray(const MyArray& arr)
{
	cout << "拷贝构造函数调用" << endl;//用来捕捉函数是否调用

	//同类之间无私处,*this和arr是同类
	
	//编译器默认提供的拷贝构造函数的实现
	/*this->m_Capacity = arr.m_Capacity;
	this->m_Size = arr.m_Size;
	this->pAdress = arr.pAdress;//浅拷贝
	*/

	this->m_Capacity = arr.m_Capacity;
	this->m_Size = arr.m_Size;
	//深拷贝
	this->pAdress = new int[arr.m_Capacity];
	//将数组元素复制一份
	for (int i = 0; i < m_Size; i++)
	{
		this->pAdress[i] = arr.pAdress[i];
	}
}

//用户操作接口
//尾插法
void MyArray::pushBack(int val)
{
	this->pAdress[this->m_Size] = val;
	this->m_Size++;
	//注意：尾插时，数组越界问题
}
//根据位置添加元素
void MyArray::setData(int pos, int val)
{
	this->pAdress[pos] = val;
}

//获取指定位置数据
int MyArray::getData(int pos)
{
	return this->pAdress[pos];
}

//获取数组容量
int MyArray::getCapcity()
{
	return this->m_Capacity;
}

//获取数组大小
int MyArray::getSize()
{
	return this->m_Size;
}

//析构函数，释放堆区上数组空间
MyArray::~MyArray()
{
	if (this->pAdress != NULL)
	{
		cout << "析构造函数调用" << endl;//用来捕捉函数是否调用
		delete[] this->pAdress;//开辟数组用new 数据类型[数据大小]，释放需要用[]
		this->pAdress = NULL;
	}
}

//重载[]运算符
/*int MyArray::operator[](int index)
{
	return this->pAdress[index];
}*/

int& MyArray::operator[](int index)
{
	return this->pAdress[index];
}