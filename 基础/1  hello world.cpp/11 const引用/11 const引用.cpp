#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0
//const �������ã�һ���const����ָ�����;��һ���ġ�������Ϊ��������
//��֤�ò�����ֻ���ģ��ں����ڲ��ı䲻���ⲿ��ֵ
void Print(const int& re)
{
	cout << "re = " << re << endl;
}
int main()
{
	const int a = 10;
	//int &re = a;//����
	//1��������һ�������������ã�������һ��const����
	const int& re1 = a;

	int b = 20;
	//2���෴���һ����ͨ��������һ��const���ý����ǿ��Եġ�
	const int& re2 = b;
	cout << "b = " << b << endl;
	cout << "re2 = " << b << endl;
	b = 300;//re2 = 300;//�����Ǵ����
	cout << "b = " << b << endl;
	cout << "re2 = " << b << endl;

	return 0;
}
#endif

#if 0
void Show(const int& num)//����������ڲ�����ʹ��const
{
	//ֻϣ�������������ʾ���ݵĹ��ܣ�������ֹ�޸�����ֵ
	cout << num << endl;

	//����������ڲ�����ʹ��const
	//num1 = 200;//��ʱ�޸�num��ֵ�ͻᷢ������
} 
int main()
{
	int num = 10;
	Show(num);

	return 0;
}
#endif

#include <string>
string chatTo(const string &toName, const string &content)
{
	string msg = "�����Ķԡ�" + toName + "��˵��" + content;
	return msg;
}
int main()
{
	cout << "������Ҫ��˭������Ϣ��";
	string toName, content;
	getline(cin, toName);
	cout << "������Ҫ���͵���Ϣ��";
	getline(cin, content);
	string chatMsg = chatTo(toName, content);
	cout << chatMsg << endl;
	return 0;
}