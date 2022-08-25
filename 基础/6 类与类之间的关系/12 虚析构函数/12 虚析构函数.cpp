#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//ע�⣺�����ʲô���Ʒ���Ȩ�޶���д��Ĭ����private
class A
{
public: 
	A()
	{
		cout << "A()..." << endl;
		this->p = new char[64];
		memset(this->p, 0, 64);
		strcpy(this->p, "A string");
	}
	virtual void print()
	{
		cout << "A :" << this->p << endl;
	}
	virtual ~A()
	{
		cout << "~A()..." << endl;
		if (this->p != NULL)
		{
			delete[] this->p;
			this->p = NULL;
		}
	}
private:
	char* p;
};

class B :public A
{
public:
	B()//�˿��Ȼᴥ��A���޲ι��죬�ٵ���B���޲ι���
	{
		cout << "B()..." << endl;
		this->p = new char[64];
		memset(this->p, 0, 64);
		strcpy(this->p, "B string");
	}
	virtual void print()
	{
		cout << "B :" << this->p << endl;
	}
	virtual ~B()//��д���ຯ������������ͬ
	{
		cout << "~B()..." << endl;
		if (this->p != NULL)
		{
			delete[] this->p;
			this->p = NULL;
		}
	}
private:
	char* p;
};

#if 0
//(1)
void func(A* ap)
{
	ap->print();//�˴�������̬
}
#endif

//(2)����һ������������������̬
void func(A* ap)
{
	ap->print();//�˴�������̬
	delete ap;
}

void test1()//����A(),print(),~A()
{
	A a;
	func(&a);
}
void test2()
{
	A* ap = new A;
	func(ap);

	//�����(1)ֻ�ᴥ��A(),print()
	//�����(2)�ᴥ��A(),print(),~A()
}
void test3()//����A(),B(),print(),~B(),~A()
{
	B b;
	func(&b);
}
void test4()
{
	B* bp = new B;
	func(bp);

	//�����(1)ֻ�ᴥ��A(),B(),print()
	//�����(2)ֻ�ᴥ��A(),B(),print(),~A()��ֻ������~A()��
	//��Ϊ����ΪA* ap��delete ap;ֻ������A��������������~A()

	//��δ�������B�����ڴ�������B��Ĭ��һ���ᴥ������A������delete ap;������̬
	//�ø�����鹹������Ϊ����������������д�������������
	//ע�⣺��������������̬����д����������������������Ʋ�ͬ
}

#if 0//������������������������̬
void func(A* ap)
{
	ap->print();//�˴�������̬
}
void deleteFunc(A* ap)
{
	delete ap;//�˴�������̬
}
void test5()
{
	B* bp = new B;
	func(bp);
	deleteFun(bp);
}
#endif

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}