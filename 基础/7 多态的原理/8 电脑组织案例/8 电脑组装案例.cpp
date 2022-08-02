#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//			�����
//
//����CPU����
class CPU
{
public:
	//CPU();//�����������������ʧ�ܣ���Ϊ���Ǻ���������û��ʵ��
	virtual void calculate() = 0;
};
//�����Կ�����
class VideoCard
{
public:
	virtual void display() = 0;
};
//�����ڴ����
class Memory
{
public:
	virtual void shortage() = 0;
};

//			ʵ�ֲ�
//ע�⣺
//1����ò�Ҫ�õ�����̳����������࣬���򲻽���Ҫ��д�������麯��
//2������ÿ̨���Զ���Ҫһ���������ʱ�����ŵ����������࣬�����൱�Ӵ�
//������ - �ܹ���
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)//������̬
	{
		cout << "���Թ��캯������" << endl;
		this->m_cpu = cpu;//ע�⣺����Ϊʲô����ֱ�Ӹ�ֵ��
		this->m_vc = vc;//��char* name = nameȴ���ܣ�
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
	//�����Ķ���
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;
};
//�����Intel��Ʒ
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

//�����Lenovo��Ʒ
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

//			ҵ���
void test1()
{
#if 0
	//����ָ��ָ���������
	CPU* Cpu1 = new IntelCPU;
	VideoCard* Vc1 = new LenovoVideoCard;
	Memory* Mem1 = new LenovoMemory;
	cout << "��һ̨������ɣ�" << endl;
	Computer c1(Cpu1, Vc1, Mem1);//c1��ջ�Ͽ��ٵġ�����c1�����������������ͷ�Cpu1, Vc1, Mem1
	c1.doWork();

	CPU* Cpu2 = new LenovoCPU;
	VideoCard* Vc2 = new IntelVideoCard;
	Memory* Mem2 = new IntelMemory;
	cout << "�ڶ�̨������ɣ�" << endl;
	Computer c2(Cpu2, Vc2, Mem2);
	c2.doWork();

	//Computer* com1 = new Computer(Cpu1, Vc1, Mem1);��ʱ������delete Cpu1, Vc1, Mem1�������ͷ�����
#endif

	Computer* com1 = new Computer(new IntelCPU, new LenovoVideoCard, new LenovoMemory);
	//com1�Ƕ��Ͽ��ٵģ��ֶ������ֶ��ͷ�
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

	cout << "��һ̨������ɣ�" << endl;
	Computer c1(Cpu1, Vc2, Mem1);
	c1.doWork();

	cout << "�ڶ�̨������ɣ�" << endl;
	Computer c2(Cpu2, Vc1, Mem1);
	c2.doWork();

	//��������Ϊʲô�������
	//���������ʱ��c2�ȵ����������ͷ�Cpu2, Vc1, Mem1
	//c1���������ͷ�Cpu1, Vc2, Mem1�������Ѿ�ΪNULL��Mem1�ٴ����������´���
	//��������Ҳ�ܷ��֣�c1��Mem1��c2��Mem1ָ��ͬһ��ռ�

}
int main()
{
	//test1();
	//test2();
	return 0;
}

//ע�⣺����������֮��Ĺ�ϵ���������CPU�ࡢVideoCard�ࡢMemory��Ĺ�ϵ����Ϲ�ϵ�����Ǽ̳й�ϵ