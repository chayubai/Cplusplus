#include "Knife.h"

Knife::Knife()//创建子类对象，会先触发父类的默认构造，初始化子类对象有两种方式1、初始化列表2、父类公有属性直接赋值
{
    this->m_BaseDamage = 10;

    this->m_WeaponName = "小刀";
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
