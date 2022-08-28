#include "Hero.h"

Hero::Hero()
{
	this->m_Hp = 500;

	this->m_Atk = 50;

	this->m_Def = 50;

	this->m_Name = "����ս��";

	this->weapon = NULL;
}

void Hero::EquipWeapon(Weapon* weapon)
{
	this->weapon = weapon;

	cout << "Ӣ�ۡ�" << this->m_Name << "��װ����������" << this->weapon->m_WeaponName << "��" << endl;
}

void Hero::Attack(Monster* monster)
{
	int damage = 0;
	int addHp = 0;
	bool isHold = false;
	bool isCrit = false;
	if (this->weapon == NULL)//����Ϊ�գ�û���κμӳ�
	{
		damage = this->m_Atk;
	}
	else
	{
		//�����˺�
		damage = this->m_Atk + this->weapon->getBaseDamage();
		//������Ѫ
		addHp = this->weapon->getSuckBlood();
		//�ж϶���
		isHold = this->weapon->getHold();
		//�жϱ���
		isCrit = this->weapon->getCrit();
	}
	if (isCrit)//���������˺��ӳ�
	{
		damage = damage * 2;
		cout << "Ӣ�۵����������˱���Ч���������ܵ���˫���˺����˺�ֵ��" << damage << endl;
	}
	if (isHold)//���������ֹͣ����һ�غ�
	{
		cout << "Ӣ�۵����������˶���Ч��������ֹͣ����һ�غ�" << endl;
	}
	if (addHp > 0)//��Ѫ
	{
		cout << "Ӣ�۵�������������ѪЧ����Ӣ�����ӵ�Ѫ��ֵ��" << addHp << endl;
	}

	//���ﶨ��
	monster->m_Hold = isHold;
	//������ʵ�˺�
	int trueDamage = (damage - monster->m_Def) > 0 ? damage - monster->m_Def : 1;
	//�����Ѫ
	monster->m_Hp -= trueDamage;
	//Ӣ�ۼ�Ѫ
	this->m_Hp += addHp;

	cout << "Ӣ�ۡ�" << this->m_Name << "�������˵��ˡ�" << monster->m_Name << "��������˺�" << trueDamage << endl;
}
