#include "SalesManager.h"


SalesManager::SalesManager()
{
#if 0 //���������ҵ����ڹ��캯������������Ķ���ʱ���������SaleMan()��Manager()�Ĺ���ֱ���г�ʼ��
	cout << "���������۾��������" << endl;
	cin >> name;
	fixSalary = 5000;
	salePersent = 0.05;
#endif
}


SalesManager::~SalesManager()
{
	cout << "~SalesManager()" << endl;
}

void SalesManager::init()
{
	cout << "���������۾��������" << endl;
	cin >> name;

	fixSalary = 5000;
	salePersent = 0.05;
}

//�õ�Ա����нˮ�ķ���
void SalesManager::getPay()
{
	cout << "���������۾���ǰ�µ����۶�" << endl;
	cin >> this->saleAmount;

	//����нˮ
	this->salary = this->fixSalary + this->saleAmount * this->salePersent;
}

//Ա������������
void SalesManager::uplevel(int addLevel)
{
	this->level += addLevel;
	if (level == 1)
		this->salePersent = 0.05;
	else if (level == 2)
		this->salePersent = 0.08;
}