#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
using namespace std;//����������һ�д��룬cout��endl�ᱨ��δ�����ı�ʶ����
//iostream �ṩ�������ռ���������Ļ��ƣ�����û��ֱ�Ӷ���cout��endl...
//���ǽ���Щ�����������ռ�std��
//����Ҫʹ��cout����Ҫ�ֶ����������ռ�std��Ҫָ�����Ǹ������ռ��cout
//���ڷ������������Ҫʹ�������ռ�std�µı��������Ǹ��߱�����ʹ�������ռ�std
int main()
{
	cout << "hello world" << endl;

	return 0;
}
//ע�⣺iostream���涨���������ռ䣬�����ռ䶨�����ࡢ����������������
//��׼�����ռ�std������cout������ࡢendl������������
#endif 

#if 0
#include <iostream>
int main()
{
	//����һ
	std::cout << "hello world" << std::endl;
	//std::cout iostream���µı�׼�����ռ�std��cout,��::��ʾ������ϵ��
	//Ϊ�˷�ֹ��ͬ�������µ�ͬ�����ԣ���ʹ�ù����в�����ͻ���綨����һ��ȫ�ֱ���Ϊcout����ʱ��������ʹ��cout�ͻ��ͻ
	//�ʣ�ʹ��ǰ��Ҫָ�������ռ�
	std::cout << "nihao shijie" << std::endl;
	//���ַ���������
	return 0;
}
# endif

#if 0
#include <iostream>
//��������ȫ������������ʹ�õ�cout��endl��������std�����ռ�
using std::cout;//using �ؼ��֣��������������ռ��һ������
using std::endl;

int main()
{
	cout << "nihao shijie" << endl;
	return 0;
}
#endif

#if 0
//C���������
#include <stdio.h>
int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("a = %d\n", a);

	return 0;
}
#endif

#if 0
//C++���������
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
//����ÿ��ʹ��һ���������������Ҫ����һ����Ӧ�������ռ�ı�����������
int main()
{
	int a = 0;
	cin >> a;//cin >> ����ʱ���Ϊ���Ӽ�������������ݣ��������a�У���ͬ��cin.get()����getchar()
	cout << "a =" << a << endl;

	return 0;
}
#endif

#include <iostream>
//�������������������ռ䣬��Ϊȫ������
using namespace std;
int main()
{
	int a = 0;
	cin >> a;
	cout << "a = " << a << endl;
	return 0;
}
