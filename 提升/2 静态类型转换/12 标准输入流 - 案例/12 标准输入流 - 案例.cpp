#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

//����1���ж��û����������  ���ַ���  ��������
void test1()
{
	cout << "������һ���ַ����������֣�";
	char c = cin.peek();//cin.peek()���������ĵ�һ���ַ������ڻ�����û�����ݣ���ȴ����롣

	if (c >= '0' && c <= '9')
	{
		int num;
		cin >> num;//��ʱ���ڻ����������ݣ�����ֱ�ӽ����ݷŵ�num�У�����Ҫ�ȴ�����
		cout << "�������������Ϊ��" << num << endl;
	}
	else
	{
		char buf[1024] = { 0 };
		cin >> buf;
		cout << "����������ַ���Ϊ��" << buf << endl;
	}
}
void test12()
{
	cout << "������һ���ַ����������֣�";
	char c = cin.get();//�൱��char c;cin.get(c);

	if (c >= '0' && c <= '9')
	{
		cin.putback(c);
		int num;
		cin >> num;//��ʱ���ڻ����������ݣ�����ֱ�ӽ����ݷŵ�num�У�����Ҫ�ȴ�����
		cout << "�������������Ϊ��" << num << endl;
	}
	else
	{
		cin.putback(c);
		char buf[1024] = { 0 };
		cin >> buf;
		cout << "����������ַ���Ϊ��" << buf << endl;
	}
}

//����2���û�����0~10֮������֣��������������������
void test2()
{
	cout << "������0~10֮������֣�";
	
	int num;

	while (true)
	{
		cin >> num;
		if (num >= 0 && num <= 10)
		{
			cout << "������ȷ�������ֵΪ��" << num << endl;
			break;
		}
		cout << "�����������������룺";

		//������һ���ַ�ʱ��������ѭ����

		//cout << cin.fail() << endl;//��־λ��0��ʾ������������1��ʾ�������쳣

		//����Ҫ������int���͵����ݣ���������������int���ͣ����־λΪ0������Ϊ�������ͣ����־λΪ1

		//��Ϊ���������ַ���ʱ�򣬻����������ݾ�һֱ���ڣ��ͻ����޵�ȥȡ��

		//���ñ�־λ
		cin.clear();
		cin.sync();//��ջ����� 
		cin.ignore();//���������ֻ�����ղ��ˣ�����ignore
	}
}

int main()
{
	//test1();
	test2();
	return 0;
}