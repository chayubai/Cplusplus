#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

//����һ������
int func(int a, int b) {
	cout << "func 111 " << endl;

	return 0;
}
int func2(int a, int b) {
	cout << "func 222 " << endl;

	return 0;
}
int func3(int a, int b) {
	cout << "func 333 " << endl;

	return 0;
}


//����һ������ָ��
// C������ ����һ���������� - ����ֵ �����б�

//����һ
typedef int(FUNC)(int, int); //����һ����������
//������
typedef int(*FUNC_POINTER)(int, int); //����һ������ָ������


//��ν�һ������ָ�뵱��һ�����������أ�
void my_function(FUNC* fp,int a,int b)
{
	fp(a, b);
}

void my_function2(FUNC_POINTER fp, int a, int b)
{
	fp(a, b);
}

//����һ���ܹ������� 
void my_function3(int(*fp)(int, int), int a, int b)
{
	cout << "1999 ��д�ļܹ�" << endl;
	cout << "�̶�ҵ��1" << endl;
	fp(a, b);
	cout << "�̶�ҵ��2" << endl;
}


//2025 ʵ��һ���Ӻ���
int my_new_function(int a, int b)
{
	cout << a << " " << b << endl;
	cout << "2025��ʵ�ֵ���ҵ��" << endl;

	return 0;
}

int main(void)
{
	FUNC* p = func;
	FUNC_POINTER p2 = func;
	int(*fp)(int, int) = func;

	p(10, 20);
	(*p)(10, 20); //��������д���ȼ�

	p2(10, 20);
	(*p2)(20, 20);

	fp(10, 20);

	cout << " --------  " << endl;

	my_function3(func,10, 20);//�������̬
	my_function3(func2,00, 200);
	my_function3(func3,1000, 2000);

	//2025   ʵ��һ���Ӻ������ٵ���1999�ļܹ�
	my_function3(my_new_function,10,20);

	return 0;
}