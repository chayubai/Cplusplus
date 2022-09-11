#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <fstream>//文件流

class Person
{
public:
	Person(){}
	Person(int age,int id):m_age(age),m_id(id){}
	void show()
	{
		cout << "Age:" << m_age << " Id:" << m_id << endl;
	}
public:
	int m_age;
	int m_id;
};

void test1()
{
	Person p1(20, 1), p2(22, 2);
	const char* fileName2 = "D:\\VS2019\\C++code\\C++code\\Cplusplus\\提升\\1 静态类型转换\\15 二进制文件读写操作\\target.txt";

	ofstream osm(fileName2, ios::out | ios::binary);
	if (!osm)
	{
		cout << "文件打开失败" << endl;
		return;
	}
	osm.write((char*)&p1, sizeof(Person));
	osm.write((char*)&p2, sizeof(Person));

	osm.close();
}

int main()
{
	test1();

	const char* fileName2 = "D:\\VS2019\\C++code\\C++code\\Cplusplus\\提升\\1 静态类型转换\\15 二进制文件读写操作\\target.txt";

	ifstream ism(fileName2, ios::in | ios::binary);
	Person p3,p4;
	ism.read((char*)&p3, sizeof(Person));
	ism.read((char*)&p4, sizeof(Person));

	p3.show();
	p4.show();

	return 0;
}
