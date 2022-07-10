#include "MyArray.h"
//数组类封装
//目标：解决实际问题，训练构造函数，copy构造函数等为操作符重载做准备。

MyArray::MyArray()
{
	cout << "MyArray()..." << endl;
	this->len = 0;
	this->space = NULL;
}
MyArray::MyArray(int len)
{
	if (len <= 0)
	{
		this->len = 0;
		return;
	}
	else
	{
		this->len = len;
		//给space开辟空间
		this->space = new int[this->len];
		cout << "MyArray(int len)..." << endl;
	}
}
MyArray::MyArray(const MyArray& another)
{
	if (another.len >= 0)
	{
		this->len = another.len;

		//深拷贝
		this->space = new int[this->len];
		for (int i = 0; i < this->len; i++)
		{
			this->space[i] = another.space[i];
		}
		cout << "MyArray(const MyArray& another)..." << endl;
	}
}
MyArray::~MyArray()
{
	if (this->space != NULL)
	{
		delete[] this->space;
		this->space = NULL;
		len = 0;
		cout << "~MyArray()..." << endl;
	}
}
void MyArray::setData(int index, int data)
{
	if (this->space != NULL)
	{
		this->space[index] = data;
	}
}
int MyArray::getData(int index)
{
	return this->space[index];
}

int MyArray::getLen() const
{
	return this->len;
}
MyArray& MyArray::operator=(const MyArray& another)
{
	if (this == &another)
	{
		return *this;
	}

	if (this->space != NULL)
	{
		delete[] this->space;
		this->space = NULL;
		this->len = 0;
	}

	if (another.len >= 0)
	{
		this->len = another.len;

		//深拷贝
		this->space = new int[this->len];
		for (int i = 0; i < this->len; i++)
		{
			this->space[i] = another.space[i];
		}
		cout << "operator=(const MyArray& another)..." << endl;
	}
	return *this;
}

int& MyArray::operator[](int index) const
{
	return this->space[index];
}
/*
int getA(int* a)//将一个const实参用一个非const形参接收，是不兼容的
{
	*a = 10;
	return 0;
}

const int a = 10;
getA(&a);//将一个const实参用一个非const形参接收，是不兼容的
*/

ostream& operator<<(ostream& os, const MyArray& array)
{
	os << "遍历整个数组：";
	for (int i = 0; i < array.getLen(); i++)//array.getLen() == getLen(&array);而getLen(MyArray *const this)
	{
		os << array[i] << " ";//array.poerator[](i) == poerator[](&array,i);
	}
	os << endl;

	os << "调用了<<操作符重载";
	return os;
}

istream& operator>>(istream& is, MyArray& array)
{
	cout << "请输入" << array.getLen() << "个数: ";
	for (int i = 0; i < array.getLen(); i++)
	{
		cin >> array[i];
	}

	return is;
}

//全局
bool operator==(MyArray& array1, MyArray& array2)
{
	if (array1.len != array2.len)
	{
		return false;
	}
	for (int i = 0; i < array1.len; i++)
	{
		if (array1.space[i] != array2.space[i])
		{
			return false;
		}
	}
	return true;
}

//局部
bool MyArray::operator!=(MyArray& another)
{
	return !(*this == another);
}