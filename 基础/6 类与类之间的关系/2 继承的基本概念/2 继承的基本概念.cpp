#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>//C���Ե�string.h/cstring
using namespace std;

class Student
{
public:
	Student()
	{

	}
	Student(int id, string name)
	{
		this->id = id;
		this->name = name;//����string�Ѿ�ʵ����=���������������
	}
	void printS()
	{
		cout << "id =" << this->id << ",name = " << this->name << endl;
	}
//private:
public:
	int id;
	string name;//�⺯����string
};

//����һ���µ�ѧ���࣬����score����
class Student2
{
public:
	Student2(int id, string name, int score)
	{
		this->id = id;
		this->name = name;
		this->score = score;
	}
	void printS()
	{
		cout << "id =" << this->id << ",name = " << this->name << endl;
		cout << "score = " << this->score << endl;
	}
private:
	int id;
	string name;
	int score;
};

//ͨ���̳У�����һ���µ�ѧ���࣬����score���ܣ������˴�������ʹ���ά��
//Ҳ����˴���Ŀ�������
//ע�⣺�������͸�����������������Ŀռ䣬ֻ�ǹ����������ʱ�����ȰѸ�����Ҫ�Ķ�������һ�ݣ��ٹ�������ʣ��Ķ���
class newStudent:public Student
{
public:
	//����ĳ�Ա��ͨ�������ʼ��
	newStudent(int id, string name, double score)//:Student(id,name)
	{
		//�����������ԣ�����ֱ����������вι����ʼ��
		this->score = score;

		//����̳������ĸ�������ԣ�����ʹ�����·�����ʼ��
		//1������ͨ����ʼ���б����ø�����вι����ʼ��
		//2�����ڹ�����������Ȼṹ�츸�࣬Ĭ�ϵ��ø���Ĭ�Ϲ��캯��,��ʼ������
		//���ڸ���ʵ�����вι��죬�����������ṩĬ�Ϲ���
		//��ˣ���Ҫ��ʽ�ṩ�޲ι��죬ͬʱ���������ǹ���Ȩ��

		this->id = id;
		this->name = name;
	}
	//��ӡ��ֻ��Ҫ���ø���ķ�������
	void printS()
	{
		Student::printS();
		cout << "score = " << this->score << endl;
	}
private:
	
	double score;
};

int main()
{
	newStudent ns(1, "zhangsan", 80.0);
	ns.printS();
	return 0;
}