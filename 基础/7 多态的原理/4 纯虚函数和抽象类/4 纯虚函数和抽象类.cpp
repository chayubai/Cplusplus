#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 0
//���ö�̬ʵ�ּ�����

//����
class AbstractCalculator
{
public: 

	//���������麯����ʵ��û�����壬�����ô��麯������
	/*virtual int getResult()
	{
		return 0;
	}*/

	//���麯��
	//���һ�����а����˴��麯������ô�������޷�ʵ�������������ͨ����Ϊ ������
	//����������࣬Ҳ����Ҫ��д�����еĴ��麯��������Ҳ���ڳ�����
	virtual int getResult() = 0;

	int m_A;
	int m_B;
};
//�ӷ���������
class AddCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A + m_B;
	}
};
//������������
class SubCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A - m_B;
	}
};

class Test :public AbstractCalculator
{
	/*int getResult()
	{
		return 0;
	}*/
};
void test1()
{
	//���ö�̬���ò�ͬ�ļ�������Ĺ���
	AbstractCalculator* c = new AddCalculator;
	c->m_A = 10;
	c->m_B = 20;
	cout << c->getResult() << endl;

	delete c;

	c = new SubCalculator;
	c->m_A = 10;
	c->m_B = 20;
	cout << c->getResult() << endl;

	delete c;
	c = NULL;
	//�������������и�����麯���ò��������Ը�Ϊ���麯��
}

void test2()
{
	//AbstractCalculator abc;//���������಻��ʵ��������
	
	//Test t;//����̳г����࣬�������д�麯����Ҳ����ʵ�������󱨴�
	
	//��������������У��Ը����麯����д
}

#endif

//ͼ����
//���һ���࣬ӵ�д��麯�����ͳƸ���Ϊ������
//���ܸ�������û�г�Ա���ԣ�ֻ�и����д��麯�������ǳ����࣬��������ǲ���ʵ��������
//�����ʵ����������ø���ĳ�Ա��������û������ģ���Ϊ�ú���û��ʵ��
class Shape
{
public:
	//��ʾͼ��������һ������������һ�����麯����û�к�����ʵ��
	virtual double getArea() = 0;
	//int a;
	//int b;
};

//��������
//���һ����ͨ��̳�ӵ�д��麯�����࣬����Ҫ��д���麯��������Ҳ��һ��������
//���ʵ����������õĳ�Ա�����Ǽ̳и�������ģ�����Ҳû������
class Rect:public Shape
{
public:
	Rect(int a)
	{
		this->a = a;
	}
	virtual double getArea()
	{
		return a * a;
	}
	int a;
};

//Բ��
class Circle :public Shape
{
public:
	Circle(int r)
	{
		this->r = r;
	}
	virtual double getArea()
	{
		return r * r * 3.14;
	}
	int r;
};
//���������ļܹ�����
void printArea(Shape *sp)
{
	sp->getArea();
}

//ҵ��� �����������
int main()
{
	//main������ʹ�õı������ͣ����ǳ�����Shape������
	Shape* s = new Rect(10);
	s->getArea();//������̬

	delete s;

	s = new Circle(2);
	s->getArea();

	delete s;
	s = NULL;

	return 0;
}

//���麯���ĺô���
//1���������ṩ�ӿڣ�����̳г����ֻ࣬��Ҫ���ݳ�����Ľӿ�ʵ��ҵ���߼������������޹أ���main������ʹ���޹�
//2��ҵ��㣬main������ʹ�ã�ֻ��֪������������ݣ�����������и��룬�����֮�����϶ȵ�

//�磺main��������Rect* s1 = new Rect(10);Circle* s2 = new Circle(2);���룬������Ĺ����Ժ�ǿ

//���麯�� - ���ģʽ��ԭ��֮һ��������תԭ��

//main      - �߲�ҵ���߼���

//Shape: virtual double getArea() = 0;   - �����

//Rect: virtual double getArea(){}     Circle: virtual double getArea(){}   - ʵ�ֲ�

//ʹ�ø߲�ҵ���߼��������㿿£��ʵ�ֲ�Ҳ�����㿿£