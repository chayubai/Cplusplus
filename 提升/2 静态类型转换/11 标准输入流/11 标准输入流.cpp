#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

//���� �� ios - input output stream
//���ࣺistream��ostream
//�����ࣨͬʱ�̳��������ࣩ��iostream

//��׼����������cin�������������࣬���������а�����һЩ��Ա����
//�磺get(),getline(),ignore(),peek(),putback()

//ע�⣺��������������ݻ��ȷ��ڻ��������档

//1��cin.get(��);
void test1()
{
	
	char c = cin.get();
	//cin.get(),�ȴӻ����������ݣ�һ��ֻ�ܶ�ȡһ���ַ�
	//��������û������ʱ����ȴ����룬��������as���ٻس�

	cout << "c = " << c << endl;//a

	c = cin.get();
	cout << "c = " << c << endl;//s

	c = cin.get();
	cout << "c = " << c << endl;//���з�

	c = cin.get();//��������û������ʱ��������ȴ�����
	cout << "c = " << c << endl;
}
//get(����1)		��ȡһ���ַ�
void test12()
{
	char ch;
	while ((ch = cin.get()) != EOF)
	{
		cout << ch << endl;
	}
	//Ctrl+ Z����ѭ��

	char ch2;
	cin.get(ch2);
}
//2��get(����1������2)		��ȡ�ַ���
void test2()
{
	char buf[1024] = { 0 };
	cin.get(buf, 1024);
	//cin.get(buf, 1024),�ȴӻ�����������,���ڻ�����û�����ݣ���ȴ����롣
	//�ٽ���������ݣ��ӻ������н��ַ�������buf��

	cout << buf << endl;

	char c = cin.get();//���������û�л��з�����ȴ�����
	if (c == '\n')
	{
		cout << "���з������ڻ�����" << endl;
	}
	else
	{
		cout << "���з����ڻ�����" << endl;
	}
	//ע�⣺����cin.get()��ȡ�ַ�����ʱ�򣬻��з��������ڻ�������
}

//3��cin.getline()	��ȡһ��
void test3()
{
	char buf[1024] = { 0 };
	cin.getline(buf, 1024);

	cout << buf << endl;//���з�û�б�buf���ߣ�����������������

	char c = cin.get();//���������û�л��з�����ȴ�����
	if (c == '\n')
	{
		cout << "���з������ڻ�����" << endl;
	}
	else
	{
		cout << "���з����ڻ�����" << endl;
	}
	//ע�⣺����cin.getline()��ȡ�ַ�����ʱ�򣬻��з��Ȳ���buf�У�Ҳ���ڻ������У�����ֱ���ӵ�
}

//4��cin.ignore()���ԣ��ӻ�����ȡ���ַ�
//ignore(��)        ����������Ĭ�Ϻ���ǰһ���ַ�
//ignore(int value) ����ǰvalue���ַ�
void test4()
{
	cin.ignore();
	char c = cin.get();
	//cin.ignore(X)���Ի�������ǰX���ַ������ڻ�����û�����ݣ���ȴ����룬����get()�Ӻ��Եĺ�һ���ַ���ʼȡ
	cout << "c = " << c << endl;

	//cin.ignore(10,'\n');//�����ǰ�ҵ�\n����û��10���ַ����Ὣ\n֮ǰ���ַ����Ե�
}

//5��cin.peek()͵������ȡ���ַ�
void test5()
{
	char c = cin.peek();//cin.peek()���������ĵ�һ���ַ������ڻ�����û�����ݣ���ȴ����룬����get()��ʼȡ
	cout << "c = " << c << endl;

	c = cin.get();
	cout << "c = " << c << endl;
}

//6��cin.putback()�Ż�
void test6()
{
	char c = cin.get();
	cin.putback('m');//��get()��ȡ��һ���ַ����ٽ��ַ�'m'�Ż�ԭλ��

	char buf[1024] = { 0 };
	cin.getline(buf, 1024);
	cout << buf << endl;
}


int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	//test6();
	return 0;
}