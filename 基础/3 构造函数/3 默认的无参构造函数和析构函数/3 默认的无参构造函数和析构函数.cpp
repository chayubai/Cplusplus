#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Test
{
public:
	//��������Ĭ���ṩһ������޲ι��캯������Ĭ�ϵ������������
	//������Լ��ṩ��һ���вεĹ��캯�����򲻻�����޲εĹ��캯��
	//ע�⣺�����������ܷ�������
#if 0
	Test()
	{
		//Do Nothing
	}
	~Test()
	{
		//Do Nothing
	}
#endif
	//�Լ�������вεĹ��캯��
	Test()
	{
		//Do Nothing
	}
	Test(int x,int y)
	{
		//...
	}
	void printT()
	{
		cout << "x = " << m_x << " y = " << m_y << endl;
	}
private:
	int m_x;
	int m_y;
};
int main()
{
	//��ʱ������вεĹ��캯�����޲εĹ��캯���ᱻ���ǣ�Ĭ�ϵ����޲εĹ��캯���ᱨ��
	//��ˣ��ṩ�вεĹ��캯��������Լ�����һ���޲εĹ��캯���������캯��������
	Test t;//Ĭ�ϵ����޲εĹ��췽��

	return 0;
}