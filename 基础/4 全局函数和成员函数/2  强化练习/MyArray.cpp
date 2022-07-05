#include "MyArray.h"
//�������װ
//Ŀ�꣺���ʵ�����⣬ѵ�����캯����copy���캯����Ϊ������������׼����

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
		//��space���ٿռ�
		this->space = new int[this->len];
		cout << "MyArray(int len)..." << endl;
	}
}
MyArray::MyArray(const MyArray& another)
{
	if (another.len >= 0)
	{
		this->len = another.len;

		//���
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

int MyArray::getLen()
{
	return this->len;
}
void MyArray::operator=(const MyArray& another)
{
	if (another.len >= 0)
	{
		this->len = another.len;

		//���
		this->space = new int[this->len];
		for (int i = 0; i < this->len; i++)
		{
			this->space[i] = another.space[i];
		}
		cout << "operator=(const MyArray& another)..." << endl;
	}
}
