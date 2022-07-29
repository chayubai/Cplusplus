#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//CPU基类
class CPU
{
public:
	virtual void calculate() = 0;
};
//显卡基类
class VideoCard
{
public:
	virtual void display() = 0;
};
//内存基类
class Memory
{
public:
	virtual void shortage() = 0;
};
//电脑类
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		cout << "电脑构造函数调用" << endl;
		this->m_cpu = cpu;
		this->m_vc = vc;
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

	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;
};
//Intel厂商
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

//Lenovo厂商
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

void test1()
{
	//父类指针指向子类对象
	CPU* Cpu1 = new IntelCPU;
	VideoCard* Vc1 = new LenovoVideoCard;
	Memory* Mem1 = new LenovoMemory;
	cout << "第一台电脑组成：" << endl;
	Computer c1(Cpu1, Vc1, Mem1);
	c1.doWork();

	CPU* Cpu2 = new LenovoCPU;
	VideoCard* Vc2 = new IntelVideoCard;
	Memory* Mem2 = new IntelMemory;
	cout << "第二台电脑组成：" << endl;
	Computer c2(Cpu2, Vc2, Mem2);
	c2.doWork();
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
}
int main()
{
	test1();
	//test2();
	return 0;
}