#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()
{ 
	int a = 10;
	int b = 20;
	cout << "a = " << a << endl;

	if (a > 10)//�ٰ�
	{
		cout << "a = " << a << endl;
	}
	else
	{
		cout << "b = " << b << endl;
	}

	//��̬���࣬���磺���������������ִ�У����ܳ�����Σ�cout << "a = " << a << endl;һ����ִ��
	//��̬���࣬���磺�ж���䣬����ݲ�ͬ�����ѡ��ִ����һ����䡣���磺��̬��ʵ��
	return 0;
}