#include "SaleMan.h"
SaleMan::SaleMan()
{
#if 0
	cout << "������ ������Ա������" << endl;
	cin >> name;

	this->salePersent = 0.04; //��4%  ���
	this->saleAmount = 0;
#endif
}


SaleMan::~SaleMan()
{
	cout << "~SaleMan()" << endl;
}

void SaleMan::init()
{
	cout << "������ ������Ա������" << endl;
	cin >> name;

	this->salePersent = 0.04; //��4%  ���
}

//�õ�Ա����нˮ�ķ���
void SaleMan::getPay()
{
	cout << "�������Ա�����µ����۶�" << endl;
	cin >> saleAmount;

	//����нˮ
	this->salary = this->saleAmount * this->salePersent;
}

//Ա������������
void SaleMan::uplevel(int addLevel)
{
	this->level += addLevel;
	if (level == 1)
		this->salePersent = 0.04;
	else if (level == 2)
		this->salePersent = 0.08;
}