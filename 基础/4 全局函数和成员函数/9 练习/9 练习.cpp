#define _CRT_SECURE_NO_WARNINGS 1

//1��thisָ��ı�����ʲô������ں�������const����thisָ��
//˭���ã���ָ��˭����ĳ�ָ�롣�ڳ�Ա���������const��

//2����Ԫ�����Ƿ��д����Ժͽ����ԣ�����˵����

//3��ʵ��һ���������+=��-=����ǰ��++������++��ǰ��--������--��<<��>>�Ȳ���������

//4���������������صĹ���

//5���γ����Զ������飬ʵ��<<��������ʵ��ȡֵ������[]
//array[i] = 10;   //����[]
//cout << array << endl;  //����<<
//cin >> array;  //����>>
//cout << array[i] << endl;

//array1 == array2;  //����==
//array1 != array2;  //����!=

#if 0
#include <iostream>
using namespace std;

struct A
{
	int age;
};
int main()
{
	A a1 = { 10 };
	A a2 = { 20 };

	A a3 = a1 + a2;//Ҳ��Ҫ����+������
	return 0;
}
#endif
