#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0
class Box
{
public:
	Box(int l, int w)
	{
		len = l;
		width = w;
	}
	int volume()
	{
		int v = len * width * hight;
		cout << "�߶��ǣ�" << hight << endl;
		cout << "����ǣ�" << v << endl;
		return v;
	}

	static int hight;

private:
	int len;
	int width;
	
};
int Box::hight = 100;
int main()
{
	Box b1(10, 20);
	Box b2(100, 200);
	b1.volume();
	b2.volume();

	Box::hight = 3000;
	b1.volume();
	b2.volume();
	return 0;
}
#endif

#if 0
class Box
{
public:
	Box(int l, int w)
	{
		len = l;
		width = w;
	}
	int volume()
	{
		int v = len * width * hight;
		cout << "�߶��ǣ�" << hight << endl;
		cout << "����ǣ�" << v << endl;
		return v;
	}
	static void changeHight(int h) 
	{
		hight = h;
	}
private:
	int len;
	int width;
	static int hight;
};
int Box::hight = 100;
int main()
{
	Box b1(10, 20);
	Box b2(100, 200);
	b1.volume();
	b2.volume();

	Box::changeHight(300);
	b1.volume();
	b2.volume();
	return 0;
}
#endif

//��ƽ��ֵ�ͷ����ܺ�
class Student
{
public:
	Student(int id, int score)
	{
		m_id = id;
		m_score = score;

		m_count++;
		sum_score += m_score;
	}
	static int getCount()
	{
		return m_count;
	}
	static double getAvg()
	{
		return sum_score / m_count;
	}
	~Student()
	{
		m_count--;
		sum_score -= m_score;
	}
private:
	int m_id;
	double m_score;
	//ͳ��ѧ�������ľ�̬��Ա����
	static int m_count;
	//ͳ��ѧ���ܷ����ľ�̬��Ա����
	static double sum_score;
};

int Student::m_count = 0;
double Student::sum_score = 0.0;

int main()
{
	Student s1(1, 80);
	Student s2(2, 90);
	Student s3(3, 100);

	cout << "ѧ������������" << Student::getCount() << endl;
	cout << "ѧ����ƽ���֣�" << Student::getAvg() << endl;

	return 0;
}