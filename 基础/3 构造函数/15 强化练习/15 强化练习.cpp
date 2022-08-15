#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
 
//ĳ�̵꾭��һ�ֻ�����ﹺ��������ʱ����Ϊ��λ�������������һ������ˣ��̵���Ҫ��¼Ŀǰ������������
//������C++ģ���̵���ﹺ������׵������

class Goods
{
public:
	Goods()
	{
		weight = 0;
		next = NULL;
		cout << "������һ������Ϊ��" << weight << "�Ļ���" << endl;
	}
	Goods(int w)
	{
		//��Ҫ����һ��w�Ļ�����Ҳֿ�����������
		weight = w;
		next = NULL;
		total_weight += w;
		cout << "������һ������Ϊ��" << weight << "�Ļ���" << endl;
	}
	~Goods()
	{
		//�ֿ����������������
		cout << "ɾ����һ�������ǣ�" << weight << "�Ļ���" << endl;
		total_weight -= weight;
	}
	static int get_total_weight()
	{
		return total_weight;
	}
	Goods *next;//������洢����
private:
	int weight;//��������
	static int total_weight;//�ֿ�������
};
int Goods::total_weight = 0;
void buy(Goods* &head,int w)
{
	//����һ�����������w
	Goods* new_goods = new Goods(w);
	if (head == NULL)
	{
		head = new_goods;
	}
	else
	{//ͷ��
		new_goods->next = head;
		head = new_goods;
	}
}
void sale(Goods* &head)
{
	if (head == NULL)
	{
		cout << "�ֿ����Ѿ�û�л�����..." << endl;
		return;
	}
	else
	{//ͷɾ
		Goods* temp = head;
		head = head->next;
		delete temp;//����~Goods()
		cout << "saled..." << endl;

	}
}
int main()
{
	int choice;
	Goods* head = NULL;
	int w;
	do
	{
		cout << "1 ���� " << "2 ����  " << "0 �˳�" << endl;
		cout << "��ѡ�������";
		cin >> choice;
		switch (choice)
		{
			case 1:
				//����
				cout << "������ҪҪ�����Ļ���������";
				cin >> w;
				buy(head, w);
				break;
			case 2:
				//����
				sale(head);
				break;
			case 0:
				//�˳�
				return 0;
			default:
				cout << "ѡ���������ѡ��" << endl;
				break;
		}
		cout << "��ǰ�ֿ���������ǣ�" << Goods::get_total_weight() << endl;
	} while (1);
	return 0;
}