#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//���� - ����������Ʒ
class AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brev() = 0;
	//���뱭��
	virtual void PourCup() = 0;
	//���븨��
	virtual void PutSomething() = 0;

	//�涨����
	void MakeDrink()
	{
		Boil();
		Brev();
		PourCup();
		PutSomething();
	}
};
//��������
class Coffee :public AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil()
	{
		cout << "��ũ��ɽȪ��" << endl;
	}
	//����
	virtual void Brev()
	{
		cout << "���ݿ��ȣ�" << endl;
	}
	//���뱭��
	virtual void PourCup()
	{
		cout << "�����ȵ��뱭�У�" << endl;
	}
	//���븨��
	virtual void PutSomething()
	{
		cout << "����ţ�̣�" << endl;
	}
};

//������ˮ
class Tea :public AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil()
	{
		cout << "������ˮ��" << endl;
	}
	//����
	virtual void Brev()
	{
		cout << "���ݲ�Ҷ" << endl;
	}
	//���뱭��
	virtual void PourCup()
	{
		cout << "����ˮ���뱭�У�" << endl;
	}
	//���븨��
	virtual void PutSomething()
	{
		cout << "����ʳ�Σ�" << endl;
	}
};

//ҵ����
void DoBussiness(AbstractDrinking* drink)
{
	drink->MakeDrink();
	delete drink;
}
void test()
{
	DoBussiness(new Coffee);
	
	cout << "----------" << endl;

	DoBussiness(new Tea);
}


int main()
{
	test();
	return 0;
}
