#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0
//���õı�����C++�ڲ�ʵ����һ��ָ�볣��
void A(int &ra)
{
	ra = 100;//ref�����ã���������ת��Ϊ*ref = 100
}
int main()
{
	int a = 10;
	int& rNum = a;//�Զ�ת��Ϊint* const rNum = &a����Ҳ��˵������Ϊʲô�����ʼ��
	rNum = 20;//�ڲ�����rNum�����ã��Զ�ת��Ϊ*rNum = 20;
	A(a);//��a���뺯�������������ã�ת��Ϊint* const ra = &a;�����ô��ݣ�ʵ���ǻ��ǵ�ַ����
	return 0;
}
#endif

struct typeA
{
	int& a;
};
struct typeB
{
	int* a;
};
void motify1(int* const a)//int *const a = &a
{
	*a = 300;
}
void motify2(int& a)//�����ǽ�������Ϊ�����������ݵ�ʱ�򣬱������������ǽ�ʵ��ȡ��ַ������
{					//int &a = &a
	a = 300;//��һ�����ò�����ֵ��ʱ�򣬱���������������*����
}

//���������ȥ�о����õ�ʱ������Խ����õ���һ����ָ��ȥ�о�
//������ʹ�����ñ�̵�ʱ����Ͱ��������Ϊ�����ı����Ϳ����ˡ�

int main()
{
	cout << "sizeof(struct typeA)" << sizeof(struct typeA) << endl;
	cout << "sizeof(struct typeB)" << sizeof(struct typeB) << endl;
	//������ռ�õĴ�С����ָ������ȵġ�
	int a = 10;
	int& re = a;
	//const���εı�����Ҫ�����ʼ��������Ҳ�����ʼ��
	int* const p = &a;
	//�������㣬���ÿ�����һ����ָ�롣

	motify1(&a);
	motify2(a);
	return 0;
}
//int arr[10]; arr�ڳ�������arrָ��ջ��10�����͵Ŀռ�
//int& r = a;  r�ڳ�������rָ��ջ��a�����Ŀռ�