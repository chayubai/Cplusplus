#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//ע�⣺�����ʲô���Ʒ���Ȩ�޶���д��Ĭ����private
#if 0
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
	virtual ~B()
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
void test2()//����A(),print(),~A()
{
	A* ap = new A;
	func(ap);
}
void test3()//����A(),B(),print(),~B(),~A()
{
	B b;
	func(&b);
}
void test4()//����A(),B(),print(),~A()��ֻ������~A()�����ڲ���ΪA* ap��delete ap;ֻ����~A()
{//��δ�������B����������B��Ĭ��һ���ᴥ������A����delete ap;������̬
	B* bp = new B;
	func(bp);
}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}
#endif
#if 0
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
	virtual ~B()//������д��������������������ͬ
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
void func(A* ap)
{
	ap->print();//�˴�������̬
	delete ap;//�˴�ҲҪ������̬
}

void test4()//����A(),B(),print(),~A()��ֻ������~A()�����ڲ���ΪA* ap��delete ap;ֻ����~A()
{//��δ�������B����������B��Ĭ��һ���ᴥ������A����delete ap;������̬
	B* bp = new B;
	func(bp);
}
int main()
{
	test4();
	return 0;
}
#endif

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
	virtual ~B()//������д��������������������ͬ
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
void func(A* ap)
{
	ap->print();//�˴�������̬
}
void deleteFun(A* ap)
{
	delete ap;//�˴�ҲҪ������̬
}
void test4()//����A(),B(),print(),~A()��ֻ������~A()�����ڲ���ΪA* ap��delete ap;ֻ����~A()
{//��δ�������B����������B��Ĭ��һ���ᴥ������A����delete ap;������̬
	B* bp = new B;
	func(bp);
	deleteFun(bp);
}
int main()
{
	test4();
	return 0;
}