#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//C����û��Ĭ�ϲ�����ռλ�����ĸ���
#if 0
//Ĭ�ϲ���:�βα���ʼ����
int myfunc1(int a = 10,int b = 5)
{
	return a + b; 
}
void test1()
{
	cout << myfunc1() << endl;//��������Σ�Ĭ��ʹ��Ĭ�ϲ�����������Σ�ʹ�ô������
	cout << myfunc1(20) << endl;
	cout << myfunc1(20, 30) << endl;
}

//ע����������һ��λ����Ĭ�ϲ�������ô�����λ���𣬴����ұ�����Ĭ��ֵ
//int func(int a, int b = 10, int c)
//{
//	retrun a + b + c;
//}
//func(20,10);����

//������������ʵ�֣�ֻ����һ���ṩĬ�ϲ�����������ͬʱ��Ĭ�ϲ���
int myfunc2(int a, int b, int c);
int myfunc2(int a, int b = 5,int c = 10)
{
	return a + b + c;
}
void test2()
{
	cout << myfunc2(20) << endl;
}

//�����������
//ע�⣺Ĭ�ϲ��������Ǵ����������Ĭ��ֵ
int get_volume(int len,int width,int height = 10)
{
	cout << "len = " << len << endl;
	cout << "width = " << width << endl;
	cout << "height = " << width << endl;

	return len * width * height;
}

void test3()
{
	int len = 10;
	int w = 20;
	int h = 20;
	//������Ĭ�ϴ�ֵ�������Ҵ���
	//��1��������������ߵ�һ����������2��������������ߵ�һ���͵ڶ�������
	cout << "����� " << get_volume(len, w) << endl;
	cout << "����� " << get_volume(w, h) << endl;
}

//ռλ����:ֻдһ�����ͽ���ռλ�����õ�ʱ����봫��ռλֵ
//ռλ���������ã�++/--����������أ���������ǰ�û��Ǻ���
//ռλ����������Ĭ�ϲ���
void func2(int x, int)//������������Ϊvoid (int, int)
{
	cout << "x = " << x << endl;
}
void func2(int x, int=0)
{
	cout << "x = " << x << endl;
}
int main()
{
	//test1();
	//test2();
	//test3();

	func2(199, 10);
	func2(200);
	return 0;
}
#endif 

#include <string>
string chatTo(const string& toName, const string& content)
{
	string msg = "�����Ķԡ�" + toName + "��˵��" + content;
	return msg;
}
string chatFrom(const string& fromName = "ϵͳ", const string& content ="Ĭ��ϵͳ��Ϣ")
{
	string msg = "��" + fromName + "�����Ķ���˵��" + content;
	return msg;
}
int main()
{
	string toName, content, chatMsg, fromName;
	cout << "������Ҫ��˭������Ϣ��";

	getline(cin, toName);
	fromName = toName;

	cout << "������Ҫ���͵�������Ϣ��";
	getline(cin, content);

	chatMsg = chatTo(toName, content);
	cout << chatMsg << endl;

	cout << "���������ԶԷ���������Ϣ��";
	getline(cin, content);
	//chatMsg = chatFrom();
	chatMsg = chatFrom(fromName,content);

	cout << chatMsg << endl;

	return 0;
}