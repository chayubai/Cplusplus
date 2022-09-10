#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class MyException
{
public:
	MyException()
	{
		cout << "MyException��Ĭ�Ϲ��캯������" << endl;
	}
	MyException(const MyException &e)
	{
		cout << "MyException�Ŀ������캯������" << endl;
	}
	void print()
	{
		this->m_A = 100;
		cout << "error:" << m_A << endl;
	}

	~MyException()
	{
		cout << "MyException��������������" << endl;
	}

	int m_A;
};

void doWork()
{
	throw MyException();//�������� - ����Ĭ�Ϲ��캯��
	//throw &(MyException());//&MyException()��������д
	//throw new MyException();//����ָ����ն��󣬿��Զ����Ͽ��ٿռ䣬Ȼ���ֶ��ͷ�
}

void test()
{
	try
	{
		doWork();
	}
	catch (MyException e)//ֵ���� - ���ÿ������캯��
	{//catch (MyException& e)
		//catch (MyException* e)
		cout << "�Զ��������쳣����" << endl;
		//e.print();//������ڶ�����ǰ�ͷ��ˣ�eΪҰָ�룬���·Ƿ�����
		
		//delete e;
	}
	catch (...)
	{
		cout << "���������쳣����" << endl;
	}

	//��ʱ�Ľ�����쳣�������������
	//1����MyException()�쳣�������Ĭ�Ϲ��캯�����ٴ���e�У����ÿ������캯����ִ�д�ӡ��䣬�����������
	//�쳣������catch������֮�������

	//�����MyException e��Ϊ���ô���MyException &e�������
	//2����MyException()�쳣�������Ĭ�Ϲ��캯�����ٴ���e�У�ִ�д�ӡ��䣬���һ������
	//�����ÿ������캯�����쳣������catch�����������

	//�����MyException e��Ϊ���ô���MyException *e�������
	//3����MyException()�쳣�������Ĭ�Ϲ��캯�����ٵ����������������ִ�д�ӡ���
	//���ʹ�����ַ�ʽ�������쳣������catch������֮����ǰ�ͷš��������쳣���޷�ͨ��������������ݡ�Ӧ���ӳ��쳣�������������

	//�׳�����throw MyException();catch(MyException e)���ÿ������캯�� Ч�ʵͣ���Ϊ�࿪��һ�ݿռ�
	//Ϊʲôû�������ͷŶ�����ΪMyException e = MyException()���ý��ն���

	//�׳�����throw MyException();catch(MyException &e)ֻ����Ĭ�Ϲ��캯�� Ч�ʸ�(�Ƽ�)
	//Ϊʲôû�������ͷŶ�����ΪMyException &e = MyException()���ý��ն���

	//�׳�����throw &(MyException());catch(MyException *e)��ʱ�ȵ���Ĭ�Ϲ��죬����������������󲶻��쳣
	//����������쳣���������Ҫ�õ��Ķ���������������ͻᵼ�·Ƿ����ʣ�

	//��������ʹ��ָ����գ�����ͨ��throw new MyException();catch(MyException *e);֮����Ҫdelete e;�������������Ƶģ�
	//ע�⣺Ҳ�ǻ����Ĭ�Ϲ��죬����Ҫ�ֶ����������ͷ�

	//�Ƽ�ʹ�� ���õķ�ʽ �����Զ������͵��쳣
}
int main()
{
	test();
	return 0;
}
//ע�⣺����������������ǰִ����������ͷ�
//���ǵ�����һ������������������յĻ����൱�ڸ����������������ȡ�����֣�ʹ���������ӳ��ˡ�
//����ָ�벻�Ǹ�����ȡ������˻������������ǰ�ͷ�