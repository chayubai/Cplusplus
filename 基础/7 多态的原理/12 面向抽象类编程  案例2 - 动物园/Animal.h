#pragma once
#include <iostream>
using namespace std;

class Animal
{
public:
	Animal();
	//������������ֹ�������δ�ͷ�
	virtual ~Animal();
	//���麯��
	virtual void voice() = 0;
};

//�˺����Ǹ��� �����������з�װ�ġ� ���ֺ��� �ͽмܹ�������
void AnimalVoice(Animal* ap);
