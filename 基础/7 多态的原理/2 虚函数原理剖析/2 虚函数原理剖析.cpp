#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
	/*virtual void eat()
	{
		cout << "�����ڳԷ�" << endl;
	}*/

	virtual void eat(int a)
	{
		cout << "�����ڳԷ�" << endl;
	}
};

class Cat :public Animal
{
public:
	virtual void speak()
	{
		cout << "Сè��˵��" << endl;
	}

	/*void eat()
	{
		cout << "�����ڳԷ�" << endl;
	}*/

	void eat(int a)
	{
		cout << "Сè�ڳԷ�" << endl;
	}
};

void doSpeak(Animal& animal)
{
	animal.speak();

}

void test1()
{
	Cat cat;
	doSpeak(cat);
}

void test2()
{
	cout << "size of Ainmal = " << sizeof(Animal) << endl;
	//��û����Ӹ���virtual�ؼ��֣���ʱ��һ�����࣬ռ1���ֽ�

	//�������virtual�ؼ��֣���ʱռ4���ֽ�

	//������Animal�����virtual�ؼ��ֺ�����ڲ������һ��ָ�룬vfptr��virtual function pointer �麯����ָ�룩
	//��ָ��ָ���麯����vftable���������ǳ�Ա�������麯������ڲ���¼���麯������ڵ�ַ&Animal::speak
	//��Cat������Ǽ̳�Animal�࣬��Cat���ڲ��ṹ���麯��ָ��ָ����麯���������Ҳ�ǣ�&Animal::speak
	//��Cat�෢�������麯����д����Cat���ڲ��ṹ���麯��ָ��ָ����麯��������ݱ�Ϊ��&Cat::speak

	//ע�⣺
	//��д��ָ����������д�����е��麯��
	//1����������ֵ��ͬ��2����������ͬ��3���β��б���ͬ

	//Animal* animal = new Cat;//����Cat�����ø������ý��գ�animal�����ϻ���Cat����
	//animal -> speak();//��ʱ�ͻ����Cat::speak()

	//ͨ��������Ա������ʾ���ߣ��鿴û��virtual�ؼ��ֵĸ��࣬��ʱ��Cat�಼�������Ϊ����
	//���������virtual�ؼ��֣�Cat��û��speak��������ʱ��Cat��Ĳ��������
	//�Ӹ���̳���vfptrָ�룬ָ��vftable����ڵ�ַ0��Ϊ&Animal::speak

	//���������virtual�ؼ��֣�Cat����speak��������ʱ��Cat��Ĳ��������
	//�Ӹ���̳���vfptrָ�룬ָ��vftable����ڵ�ַ0��Ϊ&Cat::speak
}

//������д���麯�������ڲ��ṹ�����ı䣬����һ��vfptr�麯��ָ�룬vfptrָ���麯����
//�麯�����ڲ���¼���麯����ڵ�ַ
//������ָ�������ָ��������󣬷�����̬�����õ�ʱ����麯�����Һ�����ڵ�ַ


void test3()
{
	Animal* animal = new Cat;
	//animal -> speak();
	
	//*(int *)animal �����õ��麯������
	//*(int *)*(int *)animal �����õ�����speak��ַ
	//(void (*) ()) ����ָ��

	//����Сè��˵��
	( (void (*) ())(*(int*)*(int*)animal) )();

	//����Сè�ڳԷ�
	( (void (*) ())(*( (int*)*(int*)animal + 1 )))();
}

void test4()
{
	Animal* animal = new Cat;
	//��������ຯ������int a�βΣ�����Ҳ��Ҫ��

	//����Сè�ڳԷ�
	//( (void (*) (int))(*((int*)*(int*)animal + 1 )))(10);//����ֱ�ӵ��û�ʧ��

	//C/C++Ĭ�ϵ��ù��� __cdecl
	//��������õ�ʱ����ʵ�ĵ��ù����� __stdcall
	typedef void(__stdcall *FUNCPOINT)(int);
	( FUNCPOINT (*((int*)*(int*)animal + 1 )))(10);
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}