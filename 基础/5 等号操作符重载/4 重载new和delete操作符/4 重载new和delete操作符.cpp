#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class A
{
public:
	A()
	{
		cout << "A()..." << endl;
	}
	A(int a)
	{
		cout << "A(int a)..." << endl;

		this->a = a;
	}
	//���ص�new����������Ȼ�ᴥ������Ĺ��캯��
	void* operator new(size_t size)
	{
		cout << "������new������" << endl;
		return malloc(size);
	}
	void* operator new[](size_t size)
	{
		cout << "������new[]������" << endl;
		return malloc(size);
	}

	void operator delete(void *p)
	{
		cout << "������delete������" << endl;
		if (p != NULL)
		{
			free(p);
			p = NULL;
		}
	}
	void operator delete[](void* p)
	{
		cout << "������delete[]������" << endl;
		if (p != NULL)
		{
			free(p);
			p = NULL;
		}
	}
	~A()
	{
		cout << "~A()..." << endl;
	}
private:
	int a;
};
int main()
{
	//int* value_p = new int;
	//A* pa = new A(10);//������һ��A���͵Ŀռ䣬������ֵΪ10
	//��pa->operator new(sizeof(A))
	//delete pa;

	//int* array_p = malloc(sizeof(int) * 10);
	A* parray = new A[10];
	//��parray->operator new[](sizeof(A[10]))
	delete[] parray;
	
	return 0;
}