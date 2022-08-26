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
	virtual void eat()
	{
		cout << "�����ڳԷ�" << endl;
	}
	/*virtual void eat(int a)
	{
		cout << "�����ڳԷ�" << endl;
	}*/
};

class Cat :public Animal
{
public:
	virtual void speak()
	{
		cout << "Сè��˵��" << endl;
	}

	void eat()
	{
		cout << "Сè�ڳԷ�" << endl;
	}

	/*void eat(int a)
	{
		cout << "Сè�ڳԷ�" << endl;
	}*/
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

	//�������virtual�ؼ��֣���ʱ����ռ4���ֽ�

	//������Animal�����virtual�ؼ��ֺ�����ڲ������һ��ָ�룬��vfptr��virtual function pointer �麯����ָ�룩
	//��ָ��ָ���麯����vftable���������ǳ�Ա�������麯������ڲ���¼���麯������ڵ�ַ&Animal::speak
	//��Cat������Ǽ̳�Animal�࣬��Cat���ڲ��ṹ���麯��ָ��ָ��Cat����麯���������Ҳ�ǣ�&Animal::speak
	//��Cat�෢�������麯����д����Cat���ڲ��ṹ���麯��ָ��ָ��Cat����麯��������ݱ�Ϊ��&Cat::speak

	//ע�⣺
	//��д��ָ����������д�����е��麯��
	//1����������ֵ��ͬ��2����������ͬ��3���β��б���ͬ Ϊǰ��

	//Animal* animal = new Cat;//����Cat�����ø������ý��գ�animal�����ϻ���Cat����
	//animal -> speak();//��ʱ�ͻ����Cat::speak()

	//��֤��
	//ͨ��������Ա������ʾ���ߣ��鿴
	//1��������û��virtual�ؼ��ֵĸ��࣬��ʱ��Cat�಼�������Ϊ���� - �̳е��ǿ�
	//2�����������virtual�ؼ��֣���Cat��û����дspeak������û�иú���ʱ������ʱ��Cat��Ĳ���������̳��˸����һ���麯��ָ��
	//�Ӹ���̳���vfptrָ�룬ָ���Լ���vftable����ڵ�ַ0��Ϊ&Animal::speak

	//3�����������virtual�ؼ��֣���Cat����дspeak��������ʱ��Cat��Ĳ��������Ҳ�Ǽ̳��˸����һ���麯��ָ��
	//�Ӹ���̳���vfptrָ�룬ָ���Լ���vftable����ڵ�ַ0��Ϊ&Cat::speak
}

//������д���麯�������ڲ��ṹ�����ı䣬����һ��vfptr�麯��ָ�룬vfptrָ���麯����
//�麯�����ڲ���¼���麯����ڵ�ַ
//������ָ�������ָ��������󣬷�����̬�����õ�ʱ����麯�����Һ�����ڵ�ַ
//ע�⣺����͸��࣬��Ȼ����ͬ���麯��ָ�룬��ָ����麯�����Ǹ��Ե�
//�����������д�����滻�麯������ԭ�е�speak

//�麯������������ͨ��ָ��ƫ��
void test3()
{
	Animal* animal = new Cat;
	
	//*(int *)animal ǿת���ҵ�Animal��Ĳ����������õ��麯������
	//*(int *)*(int *)animal ǿת���ҵ�Cat��Ĳ����������õ�����speak��ַ
	//����void speak(),�ú���ָ����void (*ptr)() = &speak
	//(void (*) ()) �ú���ָ�������
	//(void (*) ())(*(int*)*(int*)animal ǿת��תΪ(void (*) ())ָ������
	//���ú�����ptr()

	//����Сè��˵��
	( (void (*) ())(*(int*)*(int*)animal) )();

	//����Сè�ڳԷ�
	( (void (*) ())(*( (int*)*(int*)animal + 1 )))();//���麯�����ϵ��ֱ�Ӳ���+1����
}

void test4()
{
	Animal* animal = new Cat;
	//��������ຯ������int a�βΣ�������д��

	//����Сè�ڳԷ�
	//( (void (*) (int))(*((int*)*(int*)animal + 1 )))(10);//����ֱ�ӵ��û�ʧ��

	//ԭ��
	//��������õ�ʱ����ʵ�ĵ��ù����� __stdcall
	//��C/C++Ĭ�ϵ��ù����� __cdecl
	
	//���¶��庯��ָ����ù���Ϊ��__stdcall
	typedef void(__stdcall *FUNCPOINT)(int);

	( FUNCPOINT (*((int*)*(int*)animal + 1 )))(10);
}

int main()
{
	//test1();
	//test2();
	test3();
	//test4();
	return 0;
}