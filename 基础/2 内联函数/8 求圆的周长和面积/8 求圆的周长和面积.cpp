#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
const double PI = 3.14;
//1���������:
//Բ���ܳ�
double getCircleGirth(double r)
{
	return 2 * PI * r;
}
//Բ�����
double getCircleArea(double r)
{
	return PI * r * r;
}
void test1()
{
	double r = 10;
	double g = 0;
	double a = 0;
	g = getCircleGirth(r);
	a = getCircleArea(r);
	cout << "Բ�İ뾶�ǣ�" << r << endl;
	cout << "Բ���ܳ��ǣ�" << g << endl << "Բ������ǣ�" << a << endl;
}
//2���������
class Circle
{
public:
	void setR(double r)
	{
		m_r = r;
	}
	double getR()
	{
		return m_r;
	}
	//Բ���ܳ�
	double getGirth()
	{
		return 2 * PI * m_r;
	}
	//Բ�����
	double getArea()
	{
		return PI * m_r * m_r;
	}
private:
	double m_r;
};

void test2()
{
	Circle c;
	c.setR(10);
	cout << "Բ�İ뾶�ǣ�" << c.getR() << endl;
	cout << "Բ���ܳ��ǣ�" << c.getGirth() << endl << "Բ������ǣ�" << c.getArea() << endl;
}

//3����Ա������ò�Ҫ�ñ��ʽ��ʼ��
class Circle2
{
public:
	void setR(double r)
	{
		m_r = r;//��ʱ������ı���m_r��ֵ��
		//����m_girth��m_area�Ľ���ڸ�ֵ֮ǰ���Ѿ���������ģ�������ı�m_girth��m_area��ֵ
	}
	double getR()
	{
		return m_r;
	}
	//Բ���ܳ�
	double getGirth()
	{
		return m_girth;
	}
	//Բ�����
	double getArea()
	{
		return m_area;
	}
private:
	double m_r;//m_rһ��ʼΪ���ֵ
	double m_girth = m_r * 3.14 * 2;//�Ѿ�ͨ�����ֵ�õ�m_girth�Ľ��Ҳ�����ֵ
	double m_area = m_r * m_r * 3.14;//�Ѿ�ͨ�����ֵ�õ�m_area�Ľ��Ҳ�����ֵ
};
void test3()
{
	Circle c2;
	c2.setR(10);
	cout << "Բ�İ뾶�ǣ�" << c2.getR() << endl;//10
	cout << "Բ���ܳ��ǣ�" << c2.getGirth() << endl << "Բ������ǣ�" << c2.getArea() << endl;//���ֵ ���ֵ
}

//4�������3�ַ������޸�
#if 0
class Circle2
{
public:
	void setR(double r)
	{
		m_r = r;
	}
	double getR()
	{
		return m_r;
	}
	//Բ���ܳ�
	double getGirth()
	{
		m_girth = m_r * 3.14 * 2;
		return m_girth;
	}
	//Բ�����
	double getArea()
	{
		m_area = m_r * m_r * 3.14;
		return m_area;
	}
private:
	double m_r;
	double m_girth;
	double m_area;
};
#endif

int main()
{
	test1();

	cout << "--------------------------------" << endl;

	test2();

	cout << "--------------------------------" << endl;
	
	test3();

	return 0;
}