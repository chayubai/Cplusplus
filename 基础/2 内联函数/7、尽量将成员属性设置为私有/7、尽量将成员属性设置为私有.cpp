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

private://����Ա���Զ�����Ϊ˽�����Եĺô������Կ��ƶ�ȡȨ��
	string m_name;//�ɶ���д
	int m_id;//ֻ��
};
int main()
{
	student s;
	s.setName("zhangsan");//���Խ�char*����ʽ����ת��Ϊstring
	cout << "������" << s.getName() << "���䣺" << endl;
	return 0;
}