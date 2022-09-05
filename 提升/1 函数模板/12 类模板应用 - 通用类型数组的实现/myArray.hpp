#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>

template<class T> 
class MyArray
{
public:

	//Ĭ�Ϲ��죬
	//MyArray(){}

	//�вι���
	explicit MyArray(int capacity)//��ֹ��ʽ����ת��������ֹ����MyArray arr = 10;д��
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];//���������ڶ����ϴ���Person���͵Ŀռ䣬һ����ĵ���PersonĬ�Ϲ��죬
		//������Person���Զ������вι��죬�����������ṩĬ�Ϲ��죬����Զ�������Person������һ��Ҫ����Ĭ�Ϲ��졣
		
		//���飺�������ͬʱ�����ʽ���Զ���һ��Ĭ�Ϲ��캯����
	}

	//��������
	MyArray(const MyArray& arr)//MyArray(const MyArray<T>& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		//��arr��������ݸ���һ�ݷ���pAddressָ���������
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//���� = 
	MyArray& operator=(const MyArray& arr)//const��ֹ�޸�arr��MyArray<T>& operator=(const MyArray<T>& arr)
	{
		//�ж�ԭ�����Ƿ�������
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

		return *this;//arr2 = arr1����arr2.operator=(arr1)������arr2
	}

	//���� []
	T& operator[](int index)
	{
		return this->pAddress[index];//arr[i]���Ե���ֵ�����������������͵����ã���ֵ���Ե���ֵ
	}

	//β�巨
	void pushBack(const T& val)//����Ҫ��const���������ͨ��������ΪT& val = ��ֵ;�ǲ��Ϸ��ġ�
	{//void pushBack(T& val);arr.pushBack(100)����
		if (this->m_Capacity == this->m_Size)//���ˣ�����>=����this->m_Size >= this->m_Capacity
		{
			return;
		}
		//���ÿ������죬=����������
		//1������Ԫ�ر����ܹ�������
		//2����������ֵԢ�⣬��������Ԣ�⡣�����������з���Ԫ�أ��ŵĶ���Ԫ�صĿ�����
		//3���������Ԫ�صĳ�Ա��ָ�룬ע�������ǳ��������(���--ָ��ָ��Ŀռ�Ҳ����)
		this->pAddress[this->m_Size] = val;//��=������������ÿ������죬=����������
		this->m_Size++;
	}
	//����pushBack
	void pushBack(T&& val)//C11�±�׼������ֵȡ���ã�����ʵ��T& val = ��ֵ ��ֵ����������ֱ��ʹ��T val���β���ʵ�ε���ʱ���������ַ�ʽ���ʺ��޸ĺ�����ߵ���ֵ
	{//void pushBack(T&& val);arr.pushBack(100)��������
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//βɾ��
	void popBack()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}
	//��ȡ��������
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//��ȡ�����С
	int getSize()
	{
		return this->m_Size;
	}
	//����
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

//ע�⣺
//���ڸ���Ա�����У���ʹ��=��ֵ�ţ����ܴ��ڵ��ÿ������죬=�����������������Ҫ�������غã���ֹǳ����
//�磺	MyArray<Person> myPersonArr(100);
//		Person p1("�����", 1000);
//		Person p2("��˽�", 800);
//		myPersonArr.pushBack(p1);//��ʱpushBack(p1)�д��ڵ��ÿ������죬=����������
//		myPersonArr.pushBack(p2);//��ʱpushBack(p1)�д��ڵ��ÿ������죬=����������