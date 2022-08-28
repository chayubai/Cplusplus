#include "Monster.h"

Monster::Monster()
{
	this->m_Hp = 300;

	this->m_Atk = 70;

	this->m_Def = 40;

	this->m_Hold = false;

	this->m_Name = "ɱ¾��ħ";
}

void Monster::Attack(Hero* hero)
{
	if (this->m_Hold)
	{
		cout << "���" << this->m_Name << "���������ˣ����غ��޷�����" << endl;
		return;//���غ�ֹͣ����
	}

	//���㹥���˺�
	int damage = (this->m_Atk - hero->m_Def) > 0 ? this->m_Atk - hero->m_Def : 1;

	//Ӣ�ۼ�Ѫ
	hero->m_Hp -= damage;

	cout << "���" << this->m_Name << "�������˵��ˡ�" << hero->m_Name << "��������˺�" << damage << endl;

}
