#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

//��׼���������cout������������࣬��������а�����һЩ��Ա����
//�磺flush(),put(),write()

//1��cout.flush()  ˢ�»�������Linux����Ч
void test()
{
	cout << "hello world";//Linux�²�������ʾ������ʾ
	cout.flush();//���ֶ�ˢ�»������󣬲Ż�����ʾ������ʾ
}

//2��cout.put()  �򻺳���д�ַ�
void test1()
{
	cout.put('h').put('e') << endl;
	//�򻺳���д���ַ�he��Ȼ�����Ļ����ʾ
}

//3��cout.write()  ��buf��дnum���ֽڵ���ǰ�������
void test2()
{
	char buf[] = "hello world";
	cout.write(buf, strlen(buf));
	//��һ���ռ���ַ�д�뻺������Ȼ�����Ļ����ʾ
}

//����1����ʽ��� - ʹ��������ĳ�Ա����
void test3()
{
	int number = 99;
	cout.width(20);//��� ǰ��18���ո�

	cout.fill('*');//��䣬Ĭ�Ͽո�
	cout.setf(ios::left);//��������ڱ����Χ���������
	cout.unsetf(ios::dec);//ȡ������ʮ����

	cout.setf(ios::hex);//����ʮ������
	cout.setf(ios::showbase);//��ʾ������ʮ�����ƻ���Ϊ0x��ͷ���˽��ƻ���Ϊ0��ͷ
	cout.unsetf(ios::hex);//ȡ������ʮ������
	cout.setf(ios::oct);//���ð˽���

	cout << number << endl;
}

#include <iomanip>//���Ʒ���ʽ�����ͷ�ļ�

//����2����ʽ����� - ʹ�ÿ��Ʒ�
void test4()
{
	int number = 99;
	cout << setw(20);

	cout << setfill('a');

	cout << setiosflags(ios::showbase);
	cout << setiosflags(ios::left)

	<< hex

	<< number << endl;
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}