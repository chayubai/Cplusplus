#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

template<class T>
class Person
{
public:
	static int a;//ע�⣺����a�������Ѿ�д����
};

//�����ʼ��
template<class T> int Person<T>::a = 0;

int main()
{
	Person<int> p1,p2;
	Person<char> p3,p4;

	p1.a = 10;
	p3.a = 100;

	cout << p1.a << " " << p2.a << endl;
	cout << p3.a << " " << p4.a << endl;

	return 0;
}
//��ģ�� ---> �������  --->   static��Ա���ھ������
//���õ�ʱ�����ɾ���ĺ����;������
//Person<int>���static int a;��Person<char>���static int a;����Ӱ��
