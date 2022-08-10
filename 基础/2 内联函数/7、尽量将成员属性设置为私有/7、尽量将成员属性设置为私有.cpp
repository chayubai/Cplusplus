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
	string getName()
	{
		return m_name;
	}

private://将成员属性都设置为私有属性的好处，可以控制读取权限
	string m_name;//可读可写
	int m_id;//只读
};
int main()
{
	student s;
	s.setName("zhangsan");//可以将char*，隐式类型转换为string
	cout << "姓名：" << s.getName() << "年龄：" << endl;
	return 0;
}