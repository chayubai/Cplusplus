#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
 
void func(int a, int b)
{
	cout << "func1" << endl;
}
//1���ض���һ�ֺ�������
typedef void (MY_FUNC)(int, int);

//2���ض���һ��ָ�����ĺ���ָ��
typedef void (*MY_FUNC_P)(int, int);

void func(int a, int b, int c)
{
	cout << "func2" << endl;
}
int main()
{
	MY_FUNC* pf1 = NULL;
	pf1 = func;
	pf1(10,20);//����(*pf)(10,20);

	MY_FUNC_P pf2 = NULL;
	pf2 = func;
	pf2(10, 20);
	//3��
	void (*pf3)(int, int) = NULL;
	pf3 = func;
	pf3(10, 20);
	cout << "------------" << endl;

	//��������
	func(10, 20);
	func(10, 20, 30);

	pf3 = func;//pf3ָ�����void func(int, int)
	pf3(10, 30);//���õ���void func(int, int)
	//pf3(10, 20, 30);//����
	
	//ʵ���ϣ��ڸ�����ָ�븳ֵ��ʱ���ǻᷢ����������ƥ���
	//�ڵ��ú���ָ���ʱ�������õĺ������Ѿ��̶��ˡ�
	int (*pf4)(int, int, int, int) = NULL;
	//pf4 = func();

	return 0;
}
