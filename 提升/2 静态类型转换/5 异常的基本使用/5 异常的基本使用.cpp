#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int myDivision(int a, int b)
{
	if (b == 0)
	{
		throw b;//�׳�����쳣��ֵ
	}
	return a / b;
}
void CallDivide(int x, int y)
{
	myDivision(x, y);
	//CallDivide���������û�д����쳣
}
void test()
{
	int a = 10;
	int b = 0;
	//���Լ���쳣
	try//����ִ�����´������Ƿ��쳣������쳣����д������û���쳣catch�δ����ǲ���ִ��
	{
		CallDivide(a, b);
	}
	//�쳣����󣬽��д���
	catch (int e)//�쳣ʱ�������׳���ֵ�����ͽ���ƥ�䡣���Խ����׳�����ֵ
	{
		cout << "����Ϊ" << e << endl;
	}

	//test��������������쳣
}
int main()
{
	test();
	//ע�⣺����쳣�׵����㣬��û���˴������ʱ���������terminate()��ֹ����
	//����C++���쳣���ƣ��纯�������쳣���봦��
	return 0;
}