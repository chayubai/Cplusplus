#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Person
{
public:
	int m_a;//ֻ�зǾ�̬��Ա�������������

	void func1(){}//��Ա����������������Ķ���

	static int m_b;//��̬��Ա������Ҳ�����������

	static void func2() {}//��̬��Ա������Ҳ�����������

	double m_c;
};

int Person::m_b = 0;

//ֻ�зǾ�̬��Ա�������������
void test1()
{
	Person p;
	//����Ĵ�С��1�ֽڣ�
	//ԭ��ÿ������Ӧ�����ڴ����ж�һ�޶��ĵ�ַ����˸��������һ���ֽڵĿռ�

	cout << "sizeof = " << sizeof(p) << endl;

	//��Ա�����ͳ�Ա�����Ƿֿ��洢��

	//��Ĵ�С��Ҳ��struct��С������ͬ��������Ĭ�϶�����Ϊ8
}
int main()
{
	test1();
	return 0;
}