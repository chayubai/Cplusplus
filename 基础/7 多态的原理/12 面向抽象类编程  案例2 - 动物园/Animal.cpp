#include "Animal.h"
Animal::Animal()
{
	cout << "Animal()..." << endl;
}

Animal::~Animal()
{
	cout << "~Animal() ..." << endl;
}

void AnimalVoice(Animal* ap)
{
	cout << "���￪ʼ�ҽ���" << endl;
	ap->voice();
	cout << "�����ҽ� ������" << endl;
}

#if 0
void AnimalVoice(Animal* ap)
{
	cout << "���￪ʼ�ҽ���" << endl;
	ap->voice();
	cout << "�����ҽ� ������" << endl;

	if (ap != NULL)
	{
		delete ap;
		ap = NULL;
	}
}

//main

//Dog dog;AnimalVoice(&dog);//���Բ���Ҫ�ͷŵĴ���

AnimalVoice(new Dog);//new Dog�������󣬶��Ͽ��ٵģ����û���ͷŵĴ��룬�ͻ��ڴ�й¶
AnimalVoice(new Cat);

//Animal * dog = new Dog;AnimalVoice(dog);delete dog;������ͷŵĴ��룬���ͷ����ε��³������

#endif