#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//			抽象层
//
//抽象CPU基类
class CPU
{
public:
	//CPU();//这样整个程序会运行失败，因为这是函数声明，没有实现
	virtual void calculate() = 0;
};
//抽象显卡基类
class VideoCard
{
public:
	virtual void display() = 0;
};
//抽象内存基类
class Memory
{
public:
	virtual void shortage() = 0;
};

//			实现层
//注意：
//1、最好不要让电脑类继承三个抽象类，否则不仅需要重写三个纯虚函数
//2、对于每台电脑都需要一个具体的类时，随着电脑数量增多，代码相当庞大
//电脑类 - 架构类
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)//发生多态
	{
		cout << "电脑构造函数调用" << endl;
		this->m_cpu = cpu;//注意：这里为什么可以直接赋值？
		this->m_vc = vc;//而char* name = name却不能？
		this->m_mem = mem;
	}
	void doWork()
	{
		this->m_cpu->calculate();
		this->m_vc->display();
		this->m_mem->shortage();
	}
	~Computer()
	{
		cout << "电脑析构函数调用" << endl;
		if (this->m_cpu)
		{
			delete this->m_cpu;
			m_cpu = NULL;
		}
		if (this->m_vc)
		{
			delete this->m_vc;
			m_vc = NULL;
		}
		if (this->m_mem)
		{
			delete this->m_mem;
			m_mem = NULL;
		}
	}
	//抽象层的东西
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;
};
//具体的Intel产品
class IntelCPU :public CPU
{
public:
	void calculate()
	{
		cout << "IntelCPU开始计算了" << endl;
	}
};
class IntelVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "IntelVideoCard开始显示了" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	void shortage()
	{
		cout << "IntelMemory开始存储了" << endl;
	}
};

//具体的Lenovo产品
class LenovoCPU :public CPU
{
public:
	void calculate()
	{
		cout << "LenovoCPU开始计算了" << endl;
	}
};
class LenovoVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "LenovoVideoCard开始显示了" << endl;
	}
};
class LenovoMemory :public Memory
{
public:
	void shortage()
	{
		cout << "LenovoMemory开始存储了" << endl;
	}
};

//			业务层
void test1()
{
#if 0
	//父类指针指向子类对象
	CPU* Cpu1 = new IntelCPU;
	VideoCard* Vc1 = new LenovoVideoCard;
	Memory* Mem1 = new LenovoMemory;
	cout << "第一台电脑组成：" << endl;
	Computer c1(Cpu1, Vc1, Mem1);//c1是栈上开辟的。随着c1结束，触发析构，释放Cpu1, Vc1, Mem1
	c1.doWork();

	CPU* Cpu2 = new LenovoCPU;
	VideoCard* Vc2 = new IntelVideoCard;
	Memory* Mem2 = new IntelMemory;
	cout << "第二台电脑组成：" << endl;
	Computer c2(Cpu2, Vc2, Mem2);
	c2.doWork();

	//Computer* com1 = new Computer(Cpu1, Vc1, Mem1);此时不能在delete Cpu1, Vc1, Mem1，否则释放两次
#endif

	Computer* com1 = new Computer(new IntelCPU, new LenovoVideoCard, new LenovoMemory);
	//com1是堆上开辟的，手动开辟手动释放
	com1->doWork();
	delete com1;
}
void test2()
{
	CPU* Cpu1 = new IntelCPU;
	VideoCard* Vc1 = new IntelVideoCard;
	Memory* Mem1 = new IntelMemory;

	CPU* Cpu2 = new LenovoCPU;
	VideoCard* Vc2 = new LenovoVideoCard;
	Memory* Mem2 = new LenovoMemory;

	cout << "第一台电脑组成：" << endl;
	Computer c1(Cpu1, Vc2, Mem1);
	c1.doWork();

	cout << "第二台电脑组成：" << endl;
	Computer c2(Cpu2, Vc1, Mem1);
	c2.doWork();

	//分析程序为什么会崩掉？
	//当程序结束时，c2先调用析构，释放Cpu2, Vc1, Mem1
	//c1再析构，释放Cpu1, Vc2, Mem1，导致已经为NULL的Mem1再次析构，导致错误
	//经过调试也能发现，c1的Mem1和c2的Mem1指向同一块空间

}
int main()
{
	//test1();
	//test2();
	return 0;
}

//注意：区分类与类之间的关系。电脑类和CPU类、VideoCard类、Memory类的关系是组合关系，不是继承关系