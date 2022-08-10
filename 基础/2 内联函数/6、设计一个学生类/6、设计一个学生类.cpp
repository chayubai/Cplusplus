#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

class student
{
public:
	void setName(string name)
	{
		m_name = name;
	}
	void setId(int  id)
	{
		m_id = id;
	}

	void show()
	{
		cout << "姓名：" << m_name << "年龄：" << m_id << endl;
	}

	string m_name;
	int m_id;
};
int main()
{
	student s;//通过类创建对象的过程，称为实例化
	s.setName("zhangsan");
	s.setId(10);

	cout << "姓名：" << s.m_name << "年龄：" << s.m_id << endl;

	s.show();
	return 0;
}