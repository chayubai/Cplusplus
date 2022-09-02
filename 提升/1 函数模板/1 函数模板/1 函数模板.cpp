#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//1����ͨ����ʵ�ֲ�ͬ�������͵�����ֵ�Ľ���
void mySwapInt(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void mySwapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}
void test1()
{
	int a = 10;
	int b = 20;
	mySwapInt(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	double c = 3.14;
	double d = 5.16;
	mySwapDouble(c, d);
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
}

//2������ģ��ʵ��ͨ�ý�������
template<typename T> //template ģ��  typename ��������  ģ���������ȼ�template<class T> 
//T ����������(����ȡ������)������һ��ͨ�õ��������ͣ����߱����������������ŵĺ����������г���T��Ҫ����
//��������Ҫ�����������Ͷ��弸��T��template<typename T1,typename T2,...>
void mySwap(T& a, T& b)//����ģ��ʵ��
{
	T temp = a;
	a = b;
	b = temp;
}
//����template<typename T>���� ������ �Ǻ��������Ǻ���ģ�壬���������࣬������ģ��

template<typename T>//�����������ź������࣬����ֻ�Ե�һ��������Ч��
//���ֻע�͵�����һ�У�ֻ�Ǹ��������ģ��������mySwap2�����޷�ʹ��T�ģ���Ϊû�н�����
void mySwap2()//����ú�����void mySwap2(T a)�����ǲ�������ƥ��
{//��Ȼû�в���������������ܻ��õ�T
	//T a;//���ֻע�͵����У��ú����޷�ʹ�ã�����ģ�岻�ܵ���ʹ�ã�����ָ��T����ʹ��
}

void test2()
{
	int a = 10;
	int b = 20;

	//1���Զ������Ƶ��������Ƶ�����ģ��һ�µ�T�������ͣ��ſ���������ʹ��ģ��
	//ʹ���Զ������Ƶ���ģ�庯����T����ʹ����ֵ�ϸ�����ƥ��
	mySwap(a, b);//�����������㴫��ֵ�����������Զ��Ƶ���ȥ�滻T
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	double c = 3.14;
	double d = 5.16;
	mySwap(c, d);
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	char c = 'a';
	//mySwap(a, c);//�Ƶ�����һ�µ�T����֪��T������int���ͻ���char���͡�����޷�����
	//�Զ������Ƶ����ܷ�����ʽ����ת��������ģ�������Ƴ�template<typename T1,typename T2>void mySwap(T1& a, T2& b)

	//ͨ�����Կ�֪�����ǵ�����ͨ��������ģ�庯��
}

void test3()
{
	int a = 10;
	int b = 20;

	//2����ʽָ������
	mySwap<int>(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	char c = 'a';
	//mySwap<int>(a, c);//�������õ����ͱ���һ�£�����ȡ��������char c = 'a';int &a = c;���ֲ����Ǵ����
	
	//���������ĺ���ģ��Ĳ�����ΪmySwap(T a, T b)����ʱmySwap<int>(a, c)���Ե��ã���Ϊchar����ת��Ϊint����

}

void test4()
{
	//mySwap2();//�����޲κ���ģ���޷��Զ������Ƶ���ģ�岻�ܵ���ʹ�ã�����ȷ��T�����Ͳ���ʹ��
	//��1����������ŵĺ���û��ʹ��T��Ҫô���õ�ʱ����ʽָ��T������ 2��Ҫô������ʹ��T��ģ�岻�ܵ���ʹ��

	//�������Զ��Ƶ�������ʽָ�����ͣ������ڸ��߱�����T��ʲô�������ͣ�������������ʹ����ʽָ������
	mySwap2<int>();//���߱�����T������Ϊint
}
int main()
{
	//test1();
	//test2();
	test3();

	return 0;
}

//�ܽ᣺����ģ�壺
//1�����ͱ�� - ģ�弼�� �ص㣺���Ͳ�����