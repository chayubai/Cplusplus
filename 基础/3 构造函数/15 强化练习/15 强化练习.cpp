#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
 
//某商店经销一种货物。货物购进和卖出时以箱为单位，各箱的重量不一样，因此，商店需要记录目前库存的总重量。
//现在用C++模拟商店货物购进和买醋的情况》

class Goods
{
public:
	Goods()
	{
		weight = 0;
		next = NULL;
		cout << "创建了一个重量为：" << weight << "的货物" << endl;
	}
	Goods(int w)
	{
		//需要创建一个w的货物，并且仓库加上这个重量
		weight = w;
		next = NULL;
		total_weight += w;
		cout << "创建了一个重量为：" << weight << "的货物" << endl;
	}
	~Goods()
	{
		//仓库减少这个货物的重量
		cout << "删除了一箱重量是：" << weight << "的货物" << endl;
		total_weight -= weight;
	}
	static int get_total_weight()
	{
		return total_weight;
	}
	Goods *next;//用链表存储货物
private:
	int weight;//货物重量
	static int total_weight;//仓库总重量
};
int Goods::total_weight = 0;
void buy(Goods* &head,int w)
{
	//创建一个货物，重量是w
	Goods* new_goods = new Goods(w);
	if (head == NULL)
	{
		head = new_goods;
	}
	else
	{//头插
		new_goods->next = head;
		head = new_goods;
	}
}
void sale(Goods* &head)
{
	if (head == NULL)
	{
		cout << "仓库中已经没有货物了..." << endl;
		return;
	}
	else
	{//头删
		Goods* temp = head;
		head = head->next;
		delete temp;//触发~Goods()
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
		cout << "1 进货 " << "2 出货  " << "0 退出" << endl;
		cout << "请选择操作：";
		cin >> choice;
		switch (choice)
		{
			case 1:
				//进货
				cout << "请输入要要创建的货物重量：";
				cin >> w;
				buy(head, w);
				break;
			case 2:
				//出货
				sale(head);
				break;
			case 0:
				//退出
				return 0;
			default:
				cout << "选择错误，重现选择！" << endl;
				break;
		}
		cout << "当前仓库的总重量是：" << Goods::get_total_weight() << endl;
	} while (1);
	return 0;
}