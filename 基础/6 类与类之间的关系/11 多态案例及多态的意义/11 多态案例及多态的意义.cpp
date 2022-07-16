#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//1999年写的
class Hero//英雄类
{
public:
	virtual int getAd()
	{
		return 10;
	}
};
//1999年写的
class AdvHero:public Hero
{
public:
	virtual int getAd()//子类可不写virtual
	{
		return 1001;
	}
};
//1999年写的
class Monster//怪兽类
{
public:
	int getAd()
	{
		return 1000;
	}
};
//2020年写的
class BugHero :public Hero
{
public:
	virtual int getAd()//子类可不写virtual
	{
		return 66666;
	}
};
//1999年写的 - 写的架构函数，未来可以调用
void playFight(Hero *hp,Monster *mp)
{
	if (hp->getAd() > mp->getAd())//hp->getAd()发生了多态
	{
		cout << "英雄胜利，怪兽被打死" << endl;
	}
	else
	{
		cout << "英雄挂了，怪兽赢了" << endl;
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