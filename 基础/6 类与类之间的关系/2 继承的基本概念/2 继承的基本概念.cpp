#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>//C���Ե�string.h/cstring
using namespace std;

class Student
{
public:
	Student(int id, string name)
	{
		this->id = id;
		this->name = name;
	}
	void printS()
	{
		cout << "id =" << this->id << ",name = " << this->name << endl;
	}
private:
	int id;
	string name;//�⺯����string�����Զ��������
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
//ע�⣺����͸��������������Ŀռ�
class newStudent:public Student
{
public:
	//����ĳ�Ա��ͨ�������ʼ��
	newStudent(int id, string name, double score):Student(id,name)
	{
		this->score = score;
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