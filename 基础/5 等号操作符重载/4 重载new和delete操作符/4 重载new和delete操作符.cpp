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
	//重载的new操作符，依然会触发对象的构造函数
	void* operator new(size_t size)
	{
		cout << "重载了new操作符" << endl;
		return malloc(size);
	}
	void* operator new[](size_t size)
	{
		cout << "重载了new[]操作符" << endl;
		return malloc(size);
	}

	void operator delete(void *p)
	{
		cout << "重载了delete操作符" << endl;
		if (p != NULL)
		{
			free(p);
			p = NULL;
		}
	}
	void operator delete[](void* p)
	{
		cout << "重载了delete[]操作符" << endl;
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
	//A* pa = new A(10);//开辟了一个A类型的空间，并赋初值为10
	//即pa->operator new(sizeof(A))
	//delete pa;

	//int* array_p = malloc(sizeof(int) * 10);
	A* parray = new A[10];
	//即parray->operator new[](sizeof(A[10]))
	delete[] parray;
	
	return 0;
}