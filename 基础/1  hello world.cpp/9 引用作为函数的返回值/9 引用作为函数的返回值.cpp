#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 0
int getA()
{
	int a = 10;
	return a;//int tmp = a;
}
char* getC(int n)
{
	char* p = NULL;
	p = (char*)malloc(n);

	return p;//char* tmp = p;
}
int& getA1()
{
	int a = 10;
	return a;//int &tmp = a;
}
int& getA2()
{
	static int a = 10;//�����ڶ����ϴ�������
	return a;//int &tmp = a;
}
int main()
{
	int main_a = 0;
	main_a = getA1();//main_a = tmp;//��ֵ��������ֵ����
	cout << "main_a = " << main_a << endl;
#if 0
	//������Ϊ�������ͣ���Ҫ���ؾֲ����������ã�
	int& main_a_re = getA1();//int& main_a_re = tmp;getA1()�൱�ڷ���a
	cout << "main_a_re = " << main_a_re << endl;
	cout << "main_a_re = " << main_a_re << endl;
#endif

	int& main_a_re = getA2();
	cout << "main_a_re = " << main_a_re << endl;
	cout << "main_a_re = " << main_a_re << endl;

	//��������������������͵Ļ����������Ե���ֵ
	getA2() = 1000;//�������ص��Ǳ���������

	return 0;
}
#endif

#if 0
//1��������Ҫ���ؾֲ�����������
int& sum()
{
	int num = 10;
	int& rNum = num;
	//ע�⣺rNum��sum()�����ж���ľֲ���������������ֻ�ں�������Ч
	return rNum;

	//�����еľֲ������ᱻ�ڴ���գ�������ʹ��
	//�����ǰ��ڴ汣���������գ������ڴ�����ĳ���������ڴ治��������
}
void test()
{
	int a = 1;
}
int main()
{
	int& result = sum();//result������һ���ֲ������ķ���ֵ����ʱ��rNum�Ǳ��˵�����
	test();//�����ΪrNum��test()��a�Ŀռ���պ�ĵ�����
	cout << "result = " << result << endl;
	
	return 0;
}
#endif

int& sum(int &rnum)
{
	rnum++;
	return rnum;
}
void test()
{
	int a = 1;
}
int main()
{
	int num = 10;
	int& result = sum(num);//int& result = rnum,rnum = sum(num) 
	sum(num) = 55;//�����Ҫ�ú�����������ֵ���ں�����������ǰ���const
	cout << "result = " << result << endl;

	return 0;
}