#define _CRT_SECURE_NO_WARNINGS 1

//1������C++�������ռ�����á�

//2���������������ռ�A��B�ֱ���A�к�B�ж������value����main�����н������ռ��value��ӡ������

//3��C���Ե���Ŀ��������������Ե���ֵô��C++���Ƿ���ԣ�

//4��C++�У�������������Ǵ���ģ�Ϊʲô��
//(1 < 2 ? a : b) = 100;
//(1 < 2 ? 10 : 20) = 100;

//5��const int a;��C++���������Ƿ���Ҫ��ʼ����Ϊʲô��
//const int a = 10;
//int *p = (int*)&a;
//*p = 20;
//��C++���������ܹ��޸�a��ֵ��*pʵ�������޸�˭��ֵ��

//6���������õ��ص㣿

//7������д���Ƿ���ȷ
//int &a;

//8��
//void swap1(int &a,int &b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}

//void swap2(int a, int b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}

//void swap3(int *a, int *b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//swap1,swap2,swap3����������Щ����ȷ�ġ�Ϊʲô��

//9����������ֵ������������ͣ�Ϊʲô���Խ���������ֵ��ʲô�����������ֵ���ܵ���ֵ��

//10�����´���
//int a = 20;
//const int& re_a = a;
//re_a = 30;
//�Ƿ���ȷ��Ϊʲô��

//11������д���Ƿ���ȷ��int &a = 40���������ȷ������޸ģ�

#include <iostream>
using namespace std;
int main()
{
	int a = 10;
	int& rNum = a;
	int& ra = rNum;
	cout << "ref = " << ra << endl;
	return 0;
}
