#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//������ļ�����ԭ�� 
class Animal
{
public:
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
void test1()
{
	Animal* animal = new Animal;
	Cat* cat = (Cat*)animal;

	//��������̳и��࣬�������Ŀռ�ȸ������

	//������������ָ��ǿתΪ �������ͣ���ʱ����ָ�뱾����ֻ�ܷ���Animal��С�Ŀռ䣬
	//�������ָ��ȥ���ʣ��Ϳ��ܷ���Cat��С�Ŀռ䣬����Խ��

	//Animal -> Cat  ��ת�ӣ���������ת��  -  ����ȫ
}
void test2()
{
	Cat* cat = new Cat;
	Animal* animal = (Animal*)cat;

	//������������ָ��ǿתΪ �������ͣ���ʱ����ָ�뱾���Ͽ��Է���Cat��С�Ŀռ䣬
	//�������ָ��ȥ���ʣ���ֻ�ܷ���Animal��С�Ŀռ䣬��˲������Խ��
	
	//Cat -> Animal  ��ת�ӣ���������ת��  -  ��ȫ
}

void test3()
{
	//���������̬��������ָ��ָ�����������ôת����Զ���ǰ�ȫ��
	Animal* animal = new Cat; //һ��ʼ������Cat��С�Ŀռ䣬��ʱ����ָ����Է���Animal��С�Ŀռ�
	Cat* cat = (Cat*)animal;//��ʱ�ٵ�������ָ��ǿתΪ�������ͣ�������ָ��Ҳ���Է���Cat��С�Ŀռ�
}

int main()
{
	test1();
	return 0;
}
