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
getA(&a);//报错，将一个const实参用一个非const形参接收，是不兼容的
*/

ostream& operator<<(ostream& os, const MyArray& array)//这里为了防止array[i]将内容修改，加const为什么报错？
{
	os << "遍历整个数组：";
	for (int i = 0; i < array.getLen(); i++)//array.getLen() == getLen(&array);而getLen(MyArray *const this)
	{//这里array.getLen()报错，用一个const MyArray* 类型的&array,传入一个非const的形参（即MyArray *const this），是不兼容的
		//因此需要用const修饰this指针，在getLen()后面加const
		os << array[i] << " ";//array.operator[](i) == operator[](&array,i);
		//同理，array[i] 报错，也需要在operator[]()后面加const

		//注意：源码里面如何区分不同对象的函数调用，是因为隐藏了this指针
		//当对象调用函数时，会将对象的地址传给this指针，
		//如果对象是const修饰的变量，this是非const类型的指针接收就会不兼容报错

		//调用谁，就在谁的后面加const
	}

	os << "调用了<<操作符重载";
	return os;
}

istream& operator>>(istream& is, MyArray& array)//这个函数没有用到友元，在类外声明
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
	return !(*this == another);//这里*this == another调用==操作符函数
}