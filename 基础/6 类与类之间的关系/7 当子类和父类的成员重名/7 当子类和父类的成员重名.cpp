#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Parent
{
public:

	Parent(int a)
	{
		cout << "Parent(int a)..." << endl;
		this->a = a;
	}
//	int getA()
//	{
//		return this->a;
//	}
//private:
	int a;
};
class Child :public Parent
{
public:

	Child(int p_a, int c_a):Parent(p_a)
	{
		this->a = c_a;
	}
	void printC()
	{
		//�������Ϊ˽�еģ�ֻ��ͨ��get��������
		//cout << "Parent's a = " << this->getA() << endl;
		
		//�������͸��඼����ͬ��public�ĳ�Ա�������������ͨ����������
		cout << "Parent's a = " << Parent::a << endl;
		cout << "Child's a = " << this->a << endl;//���ȷ��ʱ���ͬ������

		//ע�⣺
		//������aΪ˽�еģ���������Ҳ�޷����ʣ���Ϊ���๫�м̳и����˽�����Ժ�
		//�����Բ��ɼ������ɷ���
	}
	int a;
};
int main()
{
	Child c(10, 200);
	c.printC();
	return 0;
}