#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

template<class T>
class Base
{
public:
	T m_A;
};

//��������̳и����ʱ��Ҳ�̳���T m_A;
//�����������͵Ķ���ʱ�����ڲ�֪��T�����������Ƕ�󣬵��¸���������������޷������ڴ棬���±���
//class Son :public Base{};//����
//����Ҫָ���������е�T���������ͣ����ܸ���������ڴ棬���ڼ̳еĸ��������ʽ����T������
class Son :public Base<int>//��������д���ˣ��޷�ʵ��ͨ�û�
{

};//��ģ��������ͨ��

template<class T>
class Base2
{
public:
	T m_A;
};

template<class T1,class T2>
class Son2 :public Base2<T2>
{
public:
	Son2()
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
	T1 m_B;
};//��ģ��������ģ��

int main()
{
	Son s1;//Son�಻��ģ����
	Son2<int, double> s;//��m_B��������int,m_A��������double	Son2����ģ����
	return 0;
}