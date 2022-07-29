#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//CPU����
class CPU
{
public:
	virtual void calculate() = 0;
};
//�Կ�����
class VideoCard
{
public:
	virtual void display() = 0;
};
//�ڴ����
class Memory
{
public:
	virtual void shortage() = 0;
};
//������
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		cout << "���Թ��캯������" << endl;
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
		cout << "����������������" << endl;
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
//Intel����
class IntelCPU :public CPU
{
public:
	void calculate()
	{
		cout << "IntelCPU��ʼ������" << endl;
	}
};
class IntelVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "IntelVideoCard��ʼ��ʾ��" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	void shortage()
	{
		cout << "IntelMemory��ʼ�洢��" << endl;
	}
};

//Lenovo����
class LenovoCPU :public CPU
{
public:
	void calculate()
	{
		cout << "LenovoCPU��ʼ������" << endl;
	}
};
class LenovoVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "LenovoVideoCard��ʼ��ʾ��" << endl;
	}
};
class LenovoMemory :public Memory
{
public:
	void shortage()
	{
		cout << "LenovoMemory��ʼ�洢��" << endl;
	}
};

void test1()
{
	//����ָ��ָ���������
	CPU* Cpu1 = new IntelCPU;
	VideoCard* Vc1 = new LenovoVideoCard;
	Memory* Mem1 = new LenovoMemory;
	cout << "��һ̨������ɣ�" << endl;
	Computer c1(Cpu1, Vc1, Mem1);
	c1.doWork();

	CPU* Cpu2 = new LenovoCPU;
	VideoCard* Vc2 = new IntelVideoCard;
	Memory* Mem2 = new IntelMemory;
	cout << "�ڶ�̨������ɣ�" << endl;
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

	cout << "��һ̨������ɣ�" << endl;
	Computer c1(Cpu1, Vc2, Mem1);
	c1.doWork();

	cout << "�ڶ�̨������ɣ�" << endl;
	Computer c2(Cpu2, Vc1, Mem1);
	c2.doWork();

	//��������Ϊʲô�������
}
int main()
{
	test1();
	//test2();
	return 0;
}