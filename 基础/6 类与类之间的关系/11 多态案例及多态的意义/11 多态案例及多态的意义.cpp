#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//1999��д��
class Hero//Ӣ����
{
public:
	virtual int getAd()
	{
		return 10;
	}
};
//1999��д��
class AdvHero:public Hero
{
public:
	virtual int getAd()//����ɲ�дvirtual
	{
		return 1001;
	}
};
//1999��д��
class Monster//������
{
public:
	int getAd()
	{
		return 1000;
	}
};
//2020��д��
class BugHero :public Hero
{
public:
	virtual int getAd()//����ɲ�дvirtual
	{
		return 66666;
	}
};
//1999��д�� - д�ļܹ�������δ�����Ե���
void playFight(Hero *hp,Monster *mp)
{
	if (hp->getAd() > mp->getAd())//hp->getAd()�����˶�̬
	{
		cout << "Ӣ��ʤ�������ޱ�����" << endl;
	}
	else
	{
		cout << "Ӣ�۹��ˣ�����Ӯ��" << endl;
	}
}
int main()
{
	Hero h;
	Monster m;
	playFight(&h, &m);
	AdvHero advH;
	playFight(&advH, &m);

	BugHero bH;
	playFight(&bH, &m);
	return 0;
}