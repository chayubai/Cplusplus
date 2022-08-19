#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <memory>
using namespace std;
class A 
{
public:
	A(int a)
	{
		cout << " A()..." << endl;
		this->a = a;
	}
	~A()
	{
		cout << " ~A()..." << endl;
	}
	void func()
	{
		cout << "a = " << this->a << endl;
	}
private:
	int a;
};

class MyAutoPtr
{
public:
	MyAutoPtr(A* ptr)//A* ptr = new A(10);new A(10)��������A* ���вι����βε����������void* ��ƥ��
	{
		cout << " A()..." << endl;
		this->ptr = ptr;
	}
	~MyAutoPtr()//MyAutoPtr��Ķ������ǰ���Զ�����~MyAutoPtr()
	{
		if (this->ptr != NULL)
		{
			delete ptr;//��ʱdelete void* ptr���ᴥ��~A()�����Ǵ���~void()
			this->ptr = NULL;
		}
	}
	A* operator->()
	{
		return this->ptr;
	}
	A& operator*()
	{
		return *ptr;//���ض������ͣ�ֻ�ǵ��ÿ������죬����ԭ������
	}
private:
	A *ptr;//���ָ���������A* ���������ͷ���A�����Ķ��󣬶�����void*
};

void test1()
{
#if 0
	A* pa = new A(10);//���Ͽ��ٵĿռ䣬һ��Ҫ�ֶ��ͷ�
	pa->func();
	(*pa).func();

	delete pa;//�ֶ��ͷţ��ᴥ��~A()����������ͨ�������ͷŶ��Ͽ��ٵĿռ�

	//ע�⣺
	//delete���ͷŶ������ٵĿռ�
	//�����Ƕ������ǰ�Զ����ã������ͷŶ��󿪱��ڶ����ϵ����ԵĿռ�
#endif

	//��׼������һ������ָ���ļ���#include <memory>
	
	//int *p = new int;������ָ��ptrʹ�����£�
	//auto_ptr<int> ptr(new int);
	//����ָ�룬����Ҫdelete (new int)�����Զ��ͷſռ�
	
	//A* pa = new A(10);������ָ��ptrʹ�����£�
	auto_ptr<A> ptr(new A(10));
	ptr->func();
	(*ptr).func();
	//��ptr���������Զ�������~A()������������˲���Ҫdelete (new A(10))��������Java�е�new

	//ע�⣺���ptr��һ������������ָ�룬������ָ�������
	//��ͨ������->����*������������ʵ��ָ�������
}

void test2()
{
	//ʵ��һ���̶����͵�����ָ����

	MyAutoPtr my_ptr(new A(10));//����A����вι��죬��ջ�Ͽ���my_ptr�ֲ�����
	//���ഴ�������Զ����ö��������~MyAutoPtr()�͹��캯��
	//ͨ��my_ptr�е�ptr�й�new A(10)��ָ�룬���Զ�������~MyAutoPtr()����������ʵ�������ͷ�new A(10)����Ŀռ�
	my_ptr->func();//my_ptr->����ptrָ�룬ͨ��ptr->func();

	(*my_ptr).func();//*my_ptr����*ptr ��new A(10)������ͨ��(*ptr).func();
	//���ض������ͣ�ֻ�ǵ��ÿ������죬����ԭ������������ʱ����

	//ע�⣺
	//���A���п����ڶ��������ԣ�ͨ������ָ�봴���Ķ���new A(10)��
	//������ָ�����ǰ���Զ���������ָ��������������ͻᴥ������~A()���ͷŶѸö���Ķ������������ԵĿռ�
}
int main()
{
	//test1();
	test2();
	return 0;
}