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
		cout << "������" << m_name << "���䣺" << m_id << endl;
	}

	string m_name;
	int m_id;
};
int main()
{
	student s;//ͨ���ഴ������Ĺ��̣���Ϊʵ����
	s.setName("zhangsan");
	s.setId(10);

	cout << "������" << s.m_name << "���䣺" << s.m_id << endl;

	s.show();
	return 0;
}