#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

//����м������ƶ�����ȫ��ͬ�Ķ���,
//��ʱ����Ҫ���������Ƿ���ͬһ����Ϣʱ�����ǵķ�Ӧ������ͬ,�ֱ�ִ�в�ͬ�Ĳ�����
//����������Ƕ�̬����

//����,���ұ�3���඼�Ǹ߶��꼶,�����л�����ͬ�����Ժ���Ϊ,
//��ͬʱ�����Ͽ�������ʱ��,���ǻ�ֱ�����3����ͬ�Ľ���,����������ͬһ�����ҡ�
#if 0
class Yuebuqun//����Ⱥ
{
public:
	Yuebuqun(string kongfu)
	{
		this->kongfu = kongfu;
	}
	void fight()
	{
		cout << "����Ⱥʹ����" << kongfu << "����" << endl;
	}
	string kongfu;
};
class Linpingzhi:public Yuebuqun//��ƽ֮
{
public:
	Linpingzhi(string kongfu):Yuebuqun(kongfu)
	{
		this->kongfu = kongfu;
	}
	void fight()
	{
		cout << "��ƽ֮ʹ����" << kongfu << "����" << endl;
	}
};

//��ȫ���ṩһ���򶷵ķ���
void fightPeople(Yuebuqun* hero)//��ļ����Ը�ֵԭ�򣺸���ָ��ָ���������
{
	cout << "���ô��˵ķ���" << endl;
	hero->fight();//������͸���ķ�������ͬ��Ĭ�ϵ��ñ���ķ�����
	//��Ϊ����Yuebuqun�࣬���ǵ���Yuebuqun���fight
}
int main()
{
	//ջ�Ͽ���
	//Yuebuqun xiaoyy("��������");
	//xiaoyy.fight();

	//���Ͽ���
	Yuebuqun* xiaoyy = new Yuebuqun("��������");
	//xiaoyy->fight();

	Linpingzhi *xiaopp = new Linpingzhi("��а����");
	//xiaopp->fight();

	fightPeople(xiaoyy);
	fightPeople(xiaopp);
	//������Ĭ������һ����ȫ�Ĵ�����������Ϊ���ܴ���ʱ��������Ǹ������
	//�����ͳһִ�и���ķ�������ô��һ�����Ա�ִ�еġ����ǵ��ø����еķ���
	delete xiaoyy;
	delete xiaopp;

	return 0;
}
#endif

class Yuebuqun//����Ⱥ
{
public:
	Yuebuqun(string kongfu)
	{
		this->kongfu = kongfu;
	}
	virtual void fight()//virtual��ʶ����һ����Ա������һ���麯��
	{
		cout << "����Ⱥʹ����" << kongfu << "����" << endl;
	}
	string kongfu;
};
class Linpingzhi :public Yuebuqun//��ƽ֮
{
public:
	Linpingzhi(string kongfu) :Yuebuqun(kongfu)
	{
		this->kongfu = kongfu;
	}
	//�����������һ���麯����������д����麯��������ͬ���������Բ��ӣ�Ҳ���Լ�
	void fight()
	{
		cout << "��ƽ֮ʹ����" << kongfu << "����" << endl;
	}
};
class Linghuchong :public Yuebuqun//�����
{
public:
	Linghuchong(string kongfu) :Yuebuqun(kongfu)
	{
		this->kongfu = kongfu;
	}
	//�����������һ���麯����������д����麯��������ͬ���������Բ��ӣ�Ҳ���Լ�
	void fight()
	{
		cout << "�����ʹ����" << kongfu << "����" << endl;
	}
};
void fightPeople(Yuebuqun* hero)//��ļ����Ը�ֵԭ��
{
	cout << "���ô��˵ķ���" << endl;
	hero->fight();//��fightʵ�ֶ�̬
	//���෽�����͸��෽������ͬ
	//���ϣ�����ݽ����������ࡣ���������fight
	//���ϣ�����ݽ������Ǹ��ࡣ���ø����fight
	//������Ϊ��Ϊ��̬
}
//��̬������������Ҫ����
//1���̳�
//2���麯����д����д����ͬ�������Ĺ���
//3������ָ�������ָ���������

int main()
{
	Yuebuqun* xiaoyy = new Yuebuqun("��������");

	Linpingzhi* xiaopp = new Linpingzhi("��а����");

	Linghuchong* xiaoll = new Linghuchong("���¾Ž�");
	fightPeople(xiaoyy);
	fightPeople(xiaopp);
	fightPeople(xiaoll);
	delete xiaoyy;
	delete xiaopp;
	delete xiaoll;

	//virtual�ؼ����ڼ̳�������̳У��ڳ�Ա���������麯��
	return 0;
}