#define _CRT_SECURE_NO_WARNINGS 1

//1�����캯�������࣬������˵��

//2��
#if 0
class Test
{
public:
	Test(int a, int b)
	{
		m_a = a;
		m_b = b;
	}
	Test(Test& t)
	{
		cout << "�������캯����ִ��" << endl;
	}
	~Test()
	{
		cout << "����������ִ��" << endl;
	}
	int m_a;
	int m_b;
};
void main()
{
	Test t1, t2;
}
#endif
//˵��t1��t2����������ִ��˳��

//3��
#if 0
void test1()
{
	Test t1(1, 2);
	Test t2(t1);
}
#endif
//����test1()������t1��t2���캯�����������������龰
//4��
#if 0
void test2()
{
	Test t1(1, 2);
	Test t2 = t1;
}
#endif
//����test2()������t1��t2���캯�����������������龰

//5��
#if 0
void func(Test t)
{
	cout << "func begin..." << endl;

	cout << "func end..." << endl;
}
void test3()
{
	cout << "test3 begin..." << endl;
	Test t1(10, 20);
	//����func����
	func(t1);
	cout << "func end..." << endl;
}
#endif
//����test3()������func�����еģ����캯�����������������龰

//6��
#if 0
Test gg()
{
	cout << "gg() bgein..." << endl;
	Test temp(100, 200);//�ֲ�����
	cout << "gg() before return temp..." << endl;
	return temp;
}
void test4()
{
	cout << "test4 begin..." << endl;
	gg();
	cout << "test4 end..." << endl;
}
#endif
//����test4()������gg()�����й��캯�����������������龰

//7��
#if 0
Test gg()
{
	cout << "gg() bgein..." << endl;
	Test temp(100, 200);//�ֲ�����
	cout << "gg() before return temp..." << endl;
	return temp;
}
void test4()
{
	cout << "test5 begin..." << endl;
	Test t1 = gg();
	cout << "test5 end..." << endl;
}
#endif
//����test5()������gg()�����й��캯�����������������龰

//8��
#if 0
Test gg()
{
	cout << "gg() bgein..." << endl;
	Test temp(100, 200);//�ֲ�����
	cout << "gg() before return temp..." << endl;
	return temp;
}
void test6()
{
	cout << "test6 begin..." << endl;
	Test t1;
	t1 = gg();
	cout << "test6 end..." << endl;
}
#endif
//����test6()������gg()�����й��캯�����������������龰

//9���������Ĭ�Ͽ������캯�������ǳ����������

//10��new��delete��malloc��free������

//11��static���ε���ĳ�Ա�����ͳ�Ա�������ص㡣
//��γ�ʼ��һ��static���εĳ�Ա������
//���ʹ��һ��static���εĳ�Ա������

#if 0
#include <iostream>
using namespace std;

class A
{
public:
	int a = 10;
	static int b;
};
int A::b = 20;
int main()
{
	/*cout << a <<endl;
	cout << b << endl;*/
	//�������޷�����a��b�ģ���Ϊ����û�б������������಻���пռ�

	//cout << A::a << endl;
	cout << A::b << endl;
	//��̬��Ա���������������ڶ��󣬿���ͨ������::��Ա����/��Ա��������
	return 0;
}
#endif

#include <iostream>
using namespace std;

class A
{
public:
	A(const char* name)
	{
		int len = strlen(name);
		m_name = (char*)malloc(sizeof(len + 1));
		strcpy(m_name, name);
	}
	void printT()
	{
		cout << "printT():" << m_name << endl;//����������
	}
	~A()
	{
		cout << "~Test()" << endl;
		if (m_name != NULL)
		{
			free(m_name);
			m_name = NULL;
		}
	}
	char* m_name;
};
int main()
{
	A * p = new A("zs");
	p->printT();
	if (p != NULL)
	{
		delete p;
		p = NULL;
	}
	//cout << a.m_name << endl;//����������
	return 0;
}