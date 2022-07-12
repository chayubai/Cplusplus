#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>//C语言的string.h/cstring
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
	string name;//库函数的string，会自动调用深拷贝
};

//创建一个新的学生类，增加score功能
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

//通过继承，创建一个新的学生类，增加score功能，减少了代码冗余和代码维护
//注意：子类和父类是两个独立的空间
class newStudent:public Student
{
public:
	//父类的成员，通过父类初始化
	newStudent(int id, string name, double score):Student(id,name)
	{
		this->score = score;
	}
	//打印，只需要调用父类的方法即可
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