#include "Knife.h"

Knife::Knife()//����������󣬻��ȴ��������Ĭ�Ϲ��죬��ʼ��������������ַ�ʽ1����ʼ���б�2�����๫������ֱ�Ӹ�ֵ
{
    this->m_BaseDamage = 10;

    this->m_WeaponName = "С��";
}

int Knife::getBaseDamage()
{
    return this->m_BaseDamage;
}

int Knife::getSuckBlood()
{
    return 0;
}

bool Knife::getHold()
{
    return false;
}

bool Knife::getCrit()
{
    return false;
}
