#include "Monster.h"

Monster::Monster()
{
	this->m_Hp = 300;

	this->m_Atk = 70;

	this->m_Def = 40;

	this->m_Hold = false;

	this->m_Name = "杀戮恶魔";
}

void Monster::Attack(Hero* hero)
{
	if (this->m_Hold)
	{
		cout << "怪物【" << this->m_Name << "】被定身了，本回合无法攻击" << endl;
		return;//本回合停止攻击
	}

	//计算攻击伤害
	int damage = (this->m_Atk - hero->m_Def) > 0 ? this->m_Atk - hero->m_Def : 1;

	//英雄减血
	hero->m_Hp -= damage;

	cout << "怪物【" << this->m_Name << "】攻击了敌人【" << hero->m_Name << "】造成了伤害" << damage << endl;

}
