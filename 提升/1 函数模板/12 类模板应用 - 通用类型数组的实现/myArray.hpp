#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>

template<class T> 
class MyArray
{
public:

	//默认构造，
	//MyArray(){}

	//有参构造
	explicit MyArray(int capacity)//防止隐式类型转换，即防止这种MyArray arr = 10;写法
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];//这里由于在堆区上创建Person类型的空间，一定会的调用Person默认构造，
		//但由于Person类自定义了有参构造，编译器不会提供默认构造，因此自定义类型Person的类中一定要加上默认构造。
		
		//建议：定义类的同时最好显式的自定义一个默认构造函数。
	}

	//拷贝构造
	MyArray(const MyArray& arr)//MyArray(const MyArray<T>& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		//将arr数组的内容复制一份放入pAddress指向的数组中
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//重载 = 
	MyArray& operator=(const MyArray& arr)//const防止修改arr。MyArray<T>& operator=(const MyArray<T>& arr)
	{
		//判断原数组是否有数据
		if (this->pAddress)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;//arr2 = arr1。即arr2.operator=(arr1)，返回arr2
	}

	//重载 []
	T& operator[](int index)
	{
		return this->pAddress[index];//arr[i]可以当左值，即，返回数据类型的引用，数值可以当左值
	}

	//尾插法
	void pushBack(const T& val)//这里要加const，否则测试通不过，因为T& val = 数值;是不合法的。
	{//void pushBack(T& val);arr.pushBack(100)报错
		if (this->m_Capacity == this->m_Size)//满了，不是>=或者this->m_Size >= this->m_Capacity
		{
			return;
		}
		//调用拷贝构造，=操作符函数
		//1、对象元素必须能够被拷贝
		//2、容器都是值寓意，而非引用寓意。即：向容器中放入元素，放的都是元素的拷贝份
		//3、如果对象元素的成员有指针，注意深拷贝和浅拷贝问题(深拷贝--指针指向的空间也拷贝)
		this->pAddress[this->m_Size] = val;//有=操作符，会调用拷贝构造，=操作符函数
		this->m_Size++;
	}
	//重载pushBack
	void pushBack(T&& val)//C11新标准，对右值取引用，可以实现T& val = 数值 赋值操作。或者直接使用T val，形参是实参的临时拷贝，这种方式不适合修改函数外边的数值
	{//void pushBack(T&& val);arr.pushBack(100)可以运行
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//尾删法
	void popBack()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}
	//获取数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//获取数组大小
	int getSize()
	{
		return this->m_Size;
	}
	//析构
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	T* pAddress;
	int m_Capacity;
	int m_Size;
};

//注意：
//由于各成员函数中，都使用=赋值号，可能存在调用拷贝构造，=操作符函数，因此需要对其重载好，防止浅拷贝
//如：	MyArray<Person> myPersonArr(100);
//		Person p1("孙悟空", 1000);
//		Person p2("猪八戒", 800);
//		myPersonArr.pushBack(p1);//此时pushBack(p1)中存在调用拷贝构造，=操作符函数
//		myPersonArr.pushBack(p2);//此时pushBack(p1)中存在调用拷贝构造，=操作符函数