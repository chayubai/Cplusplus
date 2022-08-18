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

		//���
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
int getA(int* a)//��һ��constʵ����һ����const�βν��գ��ǲ����ݵ�
{
	*a = 10;
	return 0;
}

const int a = 10;
getA(&a);//������һ��constʵ����һ����const�βν��գ��ǲ����ݵ�
*/

ostream& operator<<(ostream& os, const MyArray& array)//����Ϊ�˷�ֹarray[i]�������޸ģ���constΪʲô����
{
	os << "�����������飺";
	for (int i = 0; i < array.getLen(); i++)//array.getLen() == getLen(&array);��getLen(MyArray *const this)
	{//����array.getLen()������һ��const MyArray* ���͵�&array,����һ����const���βΣ���MyArray *const this�����ǲ����ݵ�
		//�����Ҫ��const����thisָ�룬��getLen()�����const
		os << array[i] << " ";//array.operator[](i) == operator[](&array,i);
		//ͬ��array[i] ����Ҳ��Ҫ��operator[]()�����const

		//ע�⣺Դ������������ֲ�ͬ����ĺ������ã�����Ϊ������thisָ��
		//��������ú���ʱ���Ὣ����ĵ�ַ����thisָ�룬
		//���������const���εı�����this�Ƿ�const���͵�ָ����վͻ᲻���ݱ���

		//����˭������˭�ĺ����const
	}

	os << "������<<����������";
	return os;
}

istream& operator>>(istream& is, MyArray& array)//�������û���õ���Ԫ������������
{
	cout << "������" << array.getLen() << "����: ";
	for (int i = 0; i < array.getLen(); i++)
	{
		cin >> array[i];
	}

	return is;
}

//ȫ��
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

//�ֲ�
bool MyArray::operator!=(MyArray& another)
{
	return !(*this == another);//����*this == another����==����������
}