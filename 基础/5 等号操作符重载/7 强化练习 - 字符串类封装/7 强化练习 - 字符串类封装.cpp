#define _CRT_SECURE_NO_WARNINGS 1

#include "myString.h"

void test1()
{ 
	myString str("def");
	myString str2 = "abcb";//�вι���myString str2 = str;��������

	//���� << �����
	cout << str << endl;
	cout << str2 << endl;
}

void test2()
{
	myString str("");//ԭ�������������
	cout << "�������ַ���str��";

	//���� >> ����� - �ȴ��û����룬ʵ���������뵽������������޷�ʵ�ֵȴ�����Ĺ���
	//1�������ԭ���������
	//2���ٽ��û���������ݷ��뻺������
	//3�������ݷ����û�ά����������
	cin >> str;
	cout << "�ַ���str��ֵΪ��" << str << endl;

	myString str3 = "###";
	cout << "�������µ��ַ���str3��";
	cin >> str3;

	myString str4 = str3;

	cout << "�ַ���str4��ֵΪ��" << str << endl;
}

void test3()
{
	myString str = "abcd";
	myString str2 = "aaa";//ԭ�������������
	str2 = str;//����Ĭ�ϸ�ֵ�����������ִ��ǳ�����������Ӷ���������ʱ�����ͷ�ͬһ��ռ�����
	//��˶�=��������
	cout << "str2 = " << str2 << endl;	
}

void test4()
{
	myString str = "abcd";
	cout << "str = " << str << endl;

	//���� [] �����
	str[0] = 'z';

	cout << "str[0] = " << str[0] << endl;

	cout << "str = " << str << endl;
}

void test5()
{
	myString str1 = "abc";
	myString str2 = "def";
	myString str3 = str1 + "def" + "def";
	myString str4 = str1 + str2;//�����µ��ַ���
	//���� + �������ʵ���ַ���ƴ��

	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;

	//���� == �����
	if (str3 == str4)
	{
		cout << "str3 == str4" << endl;
	}
	else
	{
		cout << "str3 != str4" << endl;
	}

	if (str3 == "abcdefdef")
	{
		cout << "str3 == abcdefdef" << endl;
	}
	else
	{
		cout << "str3 != abcdefdef" << endl;
	}

	myString sa("12");
	myString sb("12");
	//cout << sa + sb << endl;//����Ϊʲô��
}

int main()
{
	test1();
	//test2();
	//test3();
	//test4();
	//test5();
	return 0;
}