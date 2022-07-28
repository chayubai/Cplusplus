#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>//C语言的string.h/cstring
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
		this->name = name;//对类string已经实现了=操作符函数的深拷贝
	}
	void printS()
	{
		cout << "id =" << this->id << ",name = " << this->name << endl;
	}
//private:
public:
	int id;
	string name;//库函数的string
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
//也提高了代码的可重用性
//注意：子类对象和父类对象是两个独立的空间，只是构造子类对象时，会先把父类需要的东西构造一份，再构造子类剩余的东西
class newStudent:public Student
{
public:
	//父类的成员，通过父类初始化
	newStudent(int id, string name, double score)//:Student(id,name)
	{
		//子类特有属性，可以直接用子类的有参构造初始化
		this->score = score;

		//子类继承下来的父类的属性，可以使用如下方法初始化
		//1、可以通过初始化列表，调用父类的有参构造初始化
		//2、由于构造子类对象，先会构造父类，默认调用父类默认构造函数,初始化变量
		//由于父类实现了有参构造，编译器不会提供默认构造
		//因此，需要显式提供无参构造，同时父类属性是公有权限

		this->id = id;
		this->name = name;
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