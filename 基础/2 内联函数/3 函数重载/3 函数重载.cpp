#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//C�����У�������ͬ��ָ��������ͬ��������ͬ���ᱨ�ض������
//C++�����У�������ͬ��ָ�����ķ���ֵ�������β��б������������������ͣ�����˳�򣩣�������ͬ���ᱨ�ض������
//����������ָ��������ͬ�������б�ͬ
//ע�⣺��������ֵ�����ǹ��ɺ������ص���������ֻҪ�����β��б������������������ͣ�����˳����ͬ���ͻᱨ�ض������

//�������ص�������
//1����ͬһ����������
//2������������ͬ
//3�������������������͡�����˳��ͬ
class Person
{
	int myfunc()//��Ա������������ȫ�ֺ���
	{

	}
};
int myfunc(int a)
{
	cout << "myfunc(int a)" << endl;
	return 0;
}
int myfunc(int a, int b)
{
	cout << "myfunc(int a, int b)" << endl;
	return 0;
}
//����ֵ��������Ϊ�������ص�����
//void myfunc(int a)
//{
//	cout << "myfunc(int a)" << endl;
//}
//��Ϊ������myfunc(1)����ʱ�����������պ����Ľ���ǿ��Եģ����ᵼ�¶�����

//����������صĻ�����ҪдĬ�ϲ�������ֹ��������
int func(int a)
{
	cout << "func1" << endl;
	return 0;
}
int func(int a,int b = 30)
{
	cout << "func2" << endl;
	return 0;
}

//����������صĻ�����Ҫ��ʼ��ռλ��������ֹ��������
int func(int a, int b, int = 0)
{
	cout << "func3" << endl;
	return 0;
}
void test1()
{
	//���ַ�ʽ�������壬
	//��֪���ǵ���func(int a)��func(int a,int b = 30)
	//func(10);
}
void test2()
{
	///���ַ�ʽ��������
	//��֪���ǵ���func(int a,int b = 30)��func(int a, int b, int=0)
	//func(10, 20);
}

//ע��������������У�const�����ÿ�����Ϊ����������ע�������
void Func(int a)
{
	cout << "Func(int a)" << endl;
}
void Func(int &a)//int &a = 10
{
	cout << "Func(int &a)" << endl;
}
void Func(const int &a)//int temp = 10;int &a = temp
{
	cout << "Func(const int &a)" << endl;
}
void test3()
{
	int a = 10;
	//Func(a);//���������ԣ�����Func(int a)��Func(int &a)
	//Func(10);//���������ԣ�����Func(int a)��Func(const int &a)
}

int printA(double a)
{
	cout << "a = " << a << endl;
	return 0;
}
int printA(int a)
{
	cout << "a = " << a <<  endl;
	return 0;
}
int printA(char ch)
{
	cout << "ch = " << ch << endl;
	return 0;
}
void test4()
{
	printA(3.14f);
	printA(19.00);
	printA(19);
	//ע�⣺
	//1������ܹ�ƥ��ĺ������������ȫƥ��ĺ���
	//2�����û����ȫƥ��ĺ������������ʽת���ĺ���
	//3����ƥ�䲻��������ʧ�ܡ�
	printA('a');
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();

	return 0;
}

//ע�⣺string &rfood = food,void eating(string food)��void eating(string &rfood)
//������foodʱ������������ԣ����������������úͶ�����Ϊͬһ������