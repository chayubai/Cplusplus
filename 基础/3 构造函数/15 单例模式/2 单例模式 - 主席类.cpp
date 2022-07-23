#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//主席类
class ChairMan
{
public:
	//2、为了能够外界访问主席指针，提供get函数，返回主席指针
	static ChairMan* getInstance()//Instance实例 - 普通函数不能访问静态成员变量
	{
		return singleMan;
	}
private:
	//1、将构造函数私有化，不可以创建多个对象，此时将无法创建对象
	ChairMan() {}

	//3、防止调用拷贝构造函数
	ChairMan(const ChairMan &c) {}
//public:
private:
	//2、对主席指针私有化，防止通过类名访问修改，对外提供只读的接口
	
	//2、保证可以访问共享的主席指针，且不能通过对象访问，只能通过类名访问，故用static修饰
	static ChairMan *singleMan;//类内声明，类外初始化 - 静态成员变量只有一份
};

ChairMan* ChairMan::singleMan = new ChairMan;

#if 0
int main()
{
	//1、应该防止可以创建多个主席类，默认无参构造私有化将不能创建对象，防止调用默认构造
	//提供公共的访问接口 - 静态成员变量只有一份
	/*ChairMan c1;
	ChairMan c2;
	ChairMan *c3 = new ChairMan;*/

	//无法创建对象，因此无法通过创建对象访问singleMan
	//只能通过类名访问，用指针接收
	/*ChairMan* c1 = ChairMan::singleMan;
	ChairMan* c2 = ChairMan::singleMan;*/

	//全局共享同一个指针singleMan
	/*if (c1 == c2)
	{
		cout << "c1 == c2" << endl;
	}
	else
	{
		cout << "c1 != c2" << endl;
	}*/

	//2、应该防止改变主席指针，将主席指针(成员变量)私有化，访问时提供共有接口
	//对主席指针私有化，防止通过类名访问修改
	//ChairMan::singleMan = NULL;//防止可写ChairMan::singleMan，将其私有化
	
	//此时可以使用public的get方法访问主席指针
	ChairMan::getInstance();
	ChairMan* c1 = ChairMan::getInstance();
	ChairMan* c2 = ChairMan::getInstance();

	if (c1 == c2)
	{
		cout << "c1 == c2" << endl;
	}
	else
	{
		cout << "c1 != c2" << endl;
	}

	//3、应该防止克隆主席指针，将拷贝构造函数私有化 - 无法调用拷贝构造函数
	//ChairMan* c3 = new ChairMan(*c1);//通过拷贝构造函数，在堆区上创建c3

	/*if (c1 == c3)
	{
		cout << "c1 == c3" << endl;
	}
	else
	{
		cout << "c1 != c3" << endl;
	}*/

	//将拷贝构造函数，设置为私有访问权限

	//注意：单例模式的对象可以不用释放，因为是共享的对象
	return 0;
}
#endif

//单例模式的步骤：
//1、通过一个类 只能实例化唯一的一个对象
//2、私有化
// 默认构造函数
// 拷贝构造函数
// 唯一实例的(静态成员变量)指针 - 类外初始化，并指向堆区创建的对象
//3、对外提供共有getInstance(静态成员函数)接口，将指针返回 - 访问静态成员变量
