#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#if 0
class News
{
public:
	void header()
	{
		cout << "公共的头部" << endl;
	}
	void footer()
	{
		cout << "公共的底部" << endl;
	}
	void leftList()
	{
		cout << "公共的左侧列表" << endl;
	}
	void content()
	{
		cout << "新闻播报..." << endl;
	}
};

class Sport
{
public:
	void header()
	{
		cout << "公共的头部" << endl;
	}
	void footer()
	{
		cout << "公共的底部" << endl;
	}
	void leftList()
	{
		cout << "公共的左侧列表" << endl;
	}
	void content()
	{
		cout << "世界杯赛况..." << endl;
	}
};
#endif

//利用继承模拟网页
//继承的优点：减少重复代码，提供代码复用性
class BasePage
{
public:
	void header()
	{
		cout << "公共的头部" << endl;
	}
	void footer()
	{
		cout << "公共的底部" << endl;
	}
	void leftList()
	{
		cout << "公共的左侧列表" << endl;
	}
};

//继承的语法：class 子类 : 继承方式 父类
//News      子类   派生类
//BasePage  父类   基类
//（父类 - 公共特性，子类 - 突出特性）

class News :public BasePage
{
public:
	void content()
	{
		cout << "新闻播报..." << endl;
	}
};

class Sport :public BasePage
{
public:
	void content()
	{
		cout << "世界杯赛况..." << endl;
	}
};

int main()
{
	News ns;
	ns.header();
	ns.footer();
	ns.leftList();
	ns.content();

	Sport sp;
	sp.header();
	sp.footer();
	sp.leftList();
	sp.content();
}