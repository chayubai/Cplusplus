#define _CRT_SECURE_NO_WARNINGS 1

/*
* //1��
#include <stdio.h>
//C����ȫ�ֱ������壬�����ظ�����
int g_val;//����ʼ����Ĭ��Ϊ0
int g_val = 20;
int main()
{
	printf("%d\n", g_val);
	return 0;
}
*/

/*
* //2��//����ֵ,��������û�м�⡣�β�����û�м�⣬�������ò�������û�м�⡣
#include <stdio.h>
func()
{
	return 10;
}
int gunc(int a)
{
	return 20;
}
int main()
{
	//C���Եĺ���ʵ�֣������з���ֵ����û�з������ͣ�Ĭ��int��������
	func();
	//C���Եĺ���ʵ�֣����޲���ʱ�����������ʱ���벻ƥ��������Ĳ���ʱ���������ͨ������
	gunc(10, 20, 30);
	return 0;
}
*/
/*
* //2��
#include <stdio.h>
//����ֵ,��������û�м�⡣�β�����û�м�⣬�������ò�������û�м�⡣
getRectS(w, h)
{
	//return w * h;
}
void test1()
{
	printf("%d\n", getRectS(10, 10, 10));
}
int main()
{
	test1();
	return 0;
}
*/

/*
* //3��//����ת�����ϸ�
#include <stdio.h>
int main()
{
	//���Բ�����ת��
	char *p = malloc(64);

	return 0;
}
*/

/*
* //4��
#if 0
#include <stdio.h>
struct student
{
	int id;
	char name[20];
	//void func();C�����£��ṹ�岻�����к�����������
};
int main()
{
	//C���Խṹ������Ķ��壬Ҫ���Ϲؼ���struct
	//student s;
	struct student s;
	return 0;
}
*/

/*
* //5��
#include <stdio.h>
int main()
{
	//C���Ե���1����0����0Ϊ�棬0Ϊ�١�
	printf("%d\n", 1 < 2);
	return 0;
}
*/

/*
* //6��
#include <stdio.h>
int main()
{
	//C���Ե���Ŀ�����
	int a = 10;
	int b = 20;
	//����Ϊ=��ߵı��ʽ������ֵ ����Ϊ=�ұߵı��ʽ������ֵ
	int c = a < b ? a : b;
	printf("%d\n", c);
	//C���Ե���Ŀ����������ص��Ǳ�������ֵ�������Ҫ����ֵ��������ʵ�ַ
	//a > b ? a : b = 50;//C�����£����ص���ֵ��20 = 50�Ǵ����
	//(a < b ? a : b) = 50;//C�����£����ص���ֵ��10 = 50�Ǵ����
	*(a < b ? &a : &b) = 50;
	printf("a = %d\n", a);
	return 0;
}
*/

//const�����ã�
//const���εı��������������ֵ�޸�
//#include <stdio.h>
//int main()
//{
//	const int num = 10;
//	int* p = &num;
//	*p = 20;
//	printf("%d\n", num);
//
//	return 0;
//}
//��ʱ�����޸ģ�˵��*p = 20�Ƿ�������

//��μ���p��ȡ��num�ĵ�ַ���ֲ���*p�޸�num��ֵ��
//#include <stdio.h>
//int main()
//{
//	const int num = 10;
//	const int* p = &num;
//	*p = 20;//��ʱ���뱨��
//  int n = 100;
/// p = &n;//����ͨ��
//	printf("%d\n", num);
//
//	return 0;
//}
//�ܽ᣺
//1��const int* p = &num;const����ָ�������*���ʱ�����ε���*p��������ͨ��*p�ı�num��ֵ
//2��p = &n��p���Ըı�
//#include <stdio.h>
//int main()
//{
//	int num = 10;
//	int* const p = &num;
//	*p = 20;////�������ͨ��
//	int n = 100;
//	p = &n;//��ʱ���뱨��
//	printf("%d\n", num);
//
//	return 0;
//}
//�ܽ᣺
//1��int* const p = &num;const����ָ�������*�ұ�ʱ�����ε���ָ�����p���������޸�p�е�ַ
//2��*p = 20;*p���Ըı�
//3��const int* const p = &num;������*p��������p
//����߱�ʾָ�������const�ģ�p��߱�ʾָ����������õ�ֵ��const
//���ۣ�
//const����ָ�������ʱ��
//1. const������� * ����ߣ����ε���ָ��ָ������ݣ���ָ֤��ָ������ݲ���ͨ��ָ������
//�䡣����ָ�������������ݿɱ䡣
//2. const������� * ���ұߣ����ε���ָ�����������֤��ָ����������ݲ����޸ģ�����ָ
//��ָ������ݣ�����ͨ��ָ��ı䡣

/*
* //7��
#include <stdio.h>
const int m_A = 100;//ȫ�ֱ�����cosnt�������ܵ������������������޸ı���
void test1()
{
	//m_A = 200;//ֱ���޸�ʧ��
	//int *p = &m_A;
	//*p = 200;//����޸ģ�����ʧ��
}
void test2()
{
	const int m_B = 100;//�ֲ�������const���������䵽ջ�ϣ�����ɹ�
	//m_B = 200;//ֱ���޸�ʧ��
	int *p = &m_A;
	*p = 200;//����޸ĳɹ�
	printf("%d\n",m_B);

	//int a[m_B];//��C�����£�const��α�����������Գ�ʼ������
}
int main()
{
	//��һ���͵ڶ�����˼һ��������һ�������������������ֵ�������޸�
	const int a = 10;//const int ���ε���int
	int const b = 20;//const b ���ε���b

	const int* c;//const����int ��*c�����ݲ����޸�
	//������ c��һ��ָ����������ָ�루��ָ����ڴ����ݲ��ܱ��޸ģ����Ǳ�������޸ģ�
	int* const d;//const����d��d�Ǵ��ַ�ģ�����ָ��ĵ�ַ�����޸�
	//���ĸ� d��һ����ָ�루ָ��������ܱ��޸ģ���������ָ����ڴ�ռ���Ա��޸ģ�
	const int* const e;
	//����� e��һ��ָ�����εĳ�ָ�루ָ�������ָ����ڴ�ռ䣬�����ܱ��޸ģ�

	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	//C���ԣ�const���εı���a��ֵ����ͨ��ָ��ı�
	const int a = 10;
	//C���ԣ�const���εı���a���Ǽٳ���
	int array[a] = { 0 };

	int* p = &a;
	*p = 50;
	printf("a = %d\n", a);
	return 0;
}
*/

/*
* //8��
#include <stdio.h>
int main()
{
	int a = 10;
	int i = 0;
	//C���Ա������壬д�ڶ�������������涨�壬һЩ�ɵı������ᱨ��
	printf("%d\n", a);

	for (i = 0; i < 10; i++)
	{
		printf("%d ", i);
	}
	return 0;
}
*/

/*
* //9��
#include <stdio.h>
enum season
{
	SPR = 0,
	SUM,
	AUT,
	WIN	//ÿʮ����һ���ָ�
};
int main()
{
	//C����ö�����ͱ��������Ը�ֵΪ����ֵ
	enum season s = 0;
	if (s == 3)
	{
		//...
	}
	return 0;
}
*/

