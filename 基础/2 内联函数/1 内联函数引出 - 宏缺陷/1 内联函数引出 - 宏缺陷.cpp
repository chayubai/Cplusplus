#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//��ȱ��1������Ҫ�����ű�֤��������
//#define ADD(x,y) x+y
#define ADD(x,y) ((x)+(y))
void test1()
{
	int a = 10;
	int b = 20;
	int ret = ADD(a, b) * 20;
	cout << ret << endl;
}

//��ȱ��2����ʹ�������ţ���Щ������Ȼ��Ԥ�ڲ���
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

//��ȱ��3��û��������

void test2()
{
	int a = 10;
	int b = 20;
	int ret = MAX(++a, b);//Ԥ��ret = 11�����Ϊ12
	//(((++a) > (b)) ? (++a) : (b))
	//((11) > (20) ? (12) : 20)

	cout << "ret = " << ret << endl;
}
//��ͨ�������������Ԥ�ڲ���������
void Max(int a, int b)
{
	int ret = a < b ? a : b;

	cout << "ret = " << ret << endl;
}
void test3()
{
	int a = 10;
	int b = 20;
	Max(++a,b);
}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}