#include "Technician.h"
Technician::Technician()
{
#if 0
	cout << "�����뼼����Ա������" << endl;
	cin >> this->name;
	perHourMoney = 100; //������ԱÿСʱ׬100
	workHour = 0;
#endif
}


Technician::~Technician()
{
	cout << "~Technician()" << endl;
}

void Technician::init()
{
	cout << "�����뼼����Ա������" << endl;
	cin >> this->name;
	perHourMoney = 100; //������ԱÿСʱ׬100
}

//�õ�Ա����нˮ�ķ���
void Technician::getPay()
{
	cout << "������Ա��һ���¹����˶���Сʱ" << endl;
	cin >> workHour;

	//���㹤��
	this->salary = perHourMoney * workHour;
}

//Ա������������
void Technician::uplevel(int addLevel)
{
	this->level += addLevel;

}