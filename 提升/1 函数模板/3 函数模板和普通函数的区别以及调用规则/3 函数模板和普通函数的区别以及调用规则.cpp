#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//1������ģ�����ͨ����������
template<typename T>
T myAdd1(T a, T b)
{
	return a + b;
}
int myAdd2(int a, int b)
{
	return a + b;
}

void test1()
{
	int a = 10;
	int b = 20;
	myAdd1(a, b);
	myAdd2(a, b);

	char c = 'a';
	//myAdd1(a, c);//�������Ͳ�һ�¡����ʹ���Զ������Ƶ����ǲ����Է�����ʽ����ת����

	myAdd1<int>(a, c);//��ʽָ�����ͣ�ע������ĺ���ģ�岻���������ͣ�char����תΪint

	myAdd2(a, c);//��ͨ�������Է�����ʽ����ת��
}

//2������ģ�����ͨ�����ĵ��ù���
template<class T>
void myPrint(T a, T b)
{
	cout << "����ģ��myPrint(T a,T b)����" << endl;
}

template<class T>
void myPrint(T a, T b, T c)
{
	cout << "����ģ��myPrint(T a, T b, T c)����" << endl;
}

void myPrint(int a,int b)
{
	cout << "��ͨ��������" << endl;
}
//��������������Ϊ���غ���
void test2()
{
	int a = 10;
	int b = 20;
	myPrint(a, b);

	//1���������ģ�����ͨ���������Ե��ã����ȵ�����ͨ��������Ϊ������ͨ������Ч�ʸ���

	//��ע�͵���ͨ������ֻ����ͨ������ʵ�֣���ʱ����ģ�����ͨ���������Ե��ã����������ȵ�����ͨ��������ʱ�ᱨ��

	//2�������ǿ�Ƶ��ú���ģ�壬����ʹ�ÿ�ģ������б�

	//ͨ�����Կ�֪�����ǵ�����ͨ��������ģ�庯��

}

void test3()
{
	int a = 10;
	int b = 20;

	//2�������ǿ�Ƶ��ú���ģ�壬����ʹ�ÿ�ģ������б�
	myPrint<>(a, b);//ע����ͨ������ʵ�ֲ��֣��������гɹ�

	//��ȡ��ע����ͨ������ʵ�ֲ��֣�����ʹ�ÿ�ģ������б���˻���ǿ�Ƶ��ú���ģ��
}

void test4()
{
	int a = 10;
	int b = 20;
	
	//3������ģ��Ҳ���Է�������
	myPrint(a, b, 10);
}

void test5()
{
	char a = 'a';
	char b = 'b';
	myPrint(a, b);

	//4���������ģ���ܲ������õ�ƥ�䣬����ʹ�ú���ģ��
	//���� myPrint(int a,int b)������Ҫ��ʽת����������ͨ������Ч�ʵͣ���˵��ú���ģ�����
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();

	return 0;
}