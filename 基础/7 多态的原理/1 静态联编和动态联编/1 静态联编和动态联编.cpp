#define _CRT_SECURE_NO_WARNINGS 1
//��̬��Ϊ��̬��̬�Ͷ�̬��̬
//1����̬��̬���������أ����������
//2����̬��̬
//���𣺺�����ַ����󶨣���̬���ࣩ������󶨣���̬���ࣩ
//������������ã��ڱ���׶ξͿ���ȷ�������ĵ��õ�ַ��������������Ǿ�̬���ࣨ����ʱ��̬��������˵��ַ����󶨵ġ�
//��������ĵ��õ�ַ���ܱ��벻���ڱ����ڼ�ȷ��������Ҫ������ʱ���ܾ��������������󶨣���̬��̬������ʱ��̬��

#include <iostream>
using namespace std;

class Animal
{
public:
	/*void speak()
	{
		cout << "������˵��" << endl;
	}*/

	//������̬��������Ҫ���virtual
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};

class Cat :public Animal
{
public:
	virtual void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};

//�����и��ӹ�ϵ�������� ָ����������ǿ���ֱ��ת����
void doSpeak(Animal & animal)//Animal & animal = cat;��������ý�������Ķ���
{
	animal.speak();//�����ַ��Ͱ󶨺��ˣ���ַ��󶨣����ھ�̬����

	//�����Ҫ����Сè˵�������ʱ�����ĵ�ַ�Ͳ�����Ͱ󶨺ã����������н׶���ȥ�󶨺�����ַ

	//���ڵ�ַ��󶨣�Ҳ�ж�̬���࣬���ڻ����ͬ����������virtual�ؼ���
}

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "С����˵��" << endl;
	}
};

void test1()
{
	//����ͬ����������virtual�ؼ���
	Cat cat;
	doSpeak(cat);
}

void test2()
{
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

//��̬��̬������������
//1�����м̳й�ϵ
//2�����������麯����������д�����е��麯��
//3�������ָ��������ã�ָ������Ķ���
//ע�⣺������д������麯�������Բ���virtual�ؼ���

int main()
{
	//test1();
	test2();
	return 0;
}