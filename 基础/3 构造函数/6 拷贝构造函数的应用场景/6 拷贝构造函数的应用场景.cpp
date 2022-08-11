#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Test
{ 
public:
	//�޲ι��캯��
	Test()
	{
		cout << "Test()..." << endl;
		m_x = 0;
		m_y = 0;
	}
	//�вι��캯��
	Test(int x, int y)
	{
		cout << "Test(int x, int y)..." << endl;
		m_x = x;
		m_y = y;
	}
	void printT()
	{
		cout << "x = " << m_x << " y = " << m_y << endl;
	}
	//ע�⣺�������캯���Ĳ���Ϊ��������
	Test(const Test& another)
	{
		cout << "Test(const Test &another)..." << endl;
		m_x = another.m_x;
		m_y = another.m_y;
	}
	//=��ֵ����������
	void operator=(const Test& another)
	{
		cout << "operator=(const Test& another)..." << endl;
		m_x = another.m_x;
		m_y = another.m_y;
	}
	//��������
	~Test()
	{
		cout << "~Test()..." << endl;
	}
private:
	int m_x;
	int m_y;
};

//����1
void test1()
{
	Test t1(10, 20);
	//�����������õ�˳�򣬸������෴��˭�ȹ���ģ�˭������
	Test t2(t1);//Test t2 = t1;
	//������ջ��t1�Ƚ�ջ��t2���ջ��������t2��������t1������
}

//����2
void test2()
{
	Test t1(10, 20);//�����вι���
	
	Test t2;//�����޲ι���
	t2 = t1;//����=��������
}

//����3
void func(Test t)//Test t = t1;t�Ŀ������캯��
{
	cout << "func begin..." << endl;
	t.printT();
	cout << "func end..." << endl;
}
void test3()
{
	cout << "Test begin..." << endl;
	Test t1(10, 20);
	func(t1);
	cout << "Test end..." << endl;
}

//����4
Test func2()
{
	cout << "func2 begin..." << endl;
	Test t(10, 20);
	t.printT();

	cout << "func2 end..." << endl;
	return t;//������ʱ����/��������������t����������������Ŀ������캯��Test temp = t
	//�������� = temp ������������.��������(temp)   Test temp = t = func2();
}
void test4()
{
	cout << "test4 begin..." << endl;
	func2();//����һ����������
	//��һ����������һ�����������ʱ�򣬺����ⲿû���κα���ȥ��������
	//����������󽫲����ٱ�ʹ�ã����Ҳ�������
	//��������ֱ�ӽ��������������յ��������ǵȴ���������ִ������ٻ���

	cout << "test4 end..." << endl;
}

//����5
void test5()
{
	cout << "test5 begin..." << endl;
	Test t1 = func2();//�᲻�ᴥ��t1�Ŀ�����������t1.�������캯��(����)��
	//�����ᴥ��t1�������죬���ǽ���������ת��t1��
	//��������������������־ͽ�t1

	//Test t1 = temp = func2();
	cout << "test5 end..." << endl;
}

//����6
void test6()
{
	cout << "test6 begin..." << endl;
	Test t1;//t1�Ѿ�����ʼ���ˡ�
	t1 = func2();//����func2���ص��������󲻻��ٴ�ת��������Ȼ����������
	//����t1�����=������������t1.operator=(��������)��Ȼ������������̻��յ���������
	t1.printT();
	cout << "test6 end..." << endl;
}
int main()
{
	//test1();//�ȵ���t1�вι��캯�����ٵ���t2�������캯�����ٵ�t2�������������ٵ���t1����������
	
	//test2();//�ȵ���t1�вι��캯�����ٵ���t2�޲ι��캯�����ٵ���ֵ�����������ٵ�t2�������������ٵ���t1����������

	//test3();//�ȵ���t1���вι��캯�����ٵ�t�Ŀ������캯�����ٵ���t�������������ٵ�t1����������
	
	//test4();

	//test5();
	
	test6();//ֻҪ���еĶ���͵��õĹ��캯������ʹ�����ᱻ�Զ�������������
	return 0;
}