#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//��ϯ��
class ChairMan
{
public:
	//2��Ϊ���ܹ���������ϯָ�룬�ṩget������������ϯָ��
	static ChairMan* getInstance()//Instanceʵ�� - ��ͨ�������ܷ��ʾ�̬��Ա����
	{
		return singleMan;
	}
private:
	//1�������캯��˽�л��������Դ���������󣬴�ʱ���޷���������
	ChairMan() {}

	//3����ֹ���ÿ������캯��
	ChairMan(const ChairMan &c) {}
//public:
private:
	//2������ϯָ��˽�л�����ֹͨ�����������޸ģ������ṩֻ���Ľӿ�
	
	//2����֤���Է��ʹ������ϯָ�룬�Ҳ���ͨ��������ʣ�ֻ��ͨ���������ʣ�����static����
	static ChairMan *singleMan;//���������������ʼ�� - ��̬��Ա����ֻ��һ��
};

ChairMan* ChairMan::singleMan = new ChairMan;

#if 0
int main()
{
	//1��Ӧ�÷�ֹ���Դ��������ϯ�࣬Ĭ���޲ι���˽�л������ܴ������󣬷�ֹ����Ĭ�Ϲ���
	//�ṩ�����ķ��ʽӿ� - ��̬��Ա����ֻ��һ��
	/*ChairMan c1;
	ChairMan c2;
	ChairMan *c3 = new ChairMan;*/

	//�޷�������������޷�ͨ�������������singleMan
	//ֻ��ͨ���������ʣ���ָ�����
	/*ChairMan* c1 = ChairMan::singleMan;
	ChairMan* c2 = ChairMan::singleMan;*/

	//ȫ�ֹ���ͬһ��ָ��singleMan
	/*if (c1 == c2)
	{
		cout << "c1 == c2" << endl;
	}
	else
	{
		cout << "c1 != c2" << endl;
	}*/

	//2��Ӧ�÷�ֹ�ı���ϯָ�룬����ϯָ��(��Ա����)˽�л�������ʱ�ṩ���нӿ�
	//����ϯָ��˽�л�����ֹͨ�����������޸�
	//ChairMan::singleMan = NULL;//��ֹ��дChairMan::singleMan������˽�л�
	
	//��ʱ����ʹ��public��get����������ϯָ��
	ChairMan::getInstance();
	ChairMan* c1 = ChairMan::getInstance();
	ChairMan* c2 = ChairMan::getInstance();

	if (c1 == c2)
	{
		cout << "c1 == c2" << endl;
	}
	else
	{
		cout << "c1 != c2" << endl;
	}

	//3��Ӧ�÷�ֹ��¡��ϯָ�룬���������캯��˽�л� - �޷����ÿ������캯��
	//ChairMan* c3 = new ChairMan(*c1);//ͨ���������캯�����ڶ����ϴ���c3

	/*if (c1 == c3)
	{
		cout << "c1 == c3" << endl;
	}
	else
	{
		cout << "c1 != c3" << endl;
	}*/

	//���������캯��������Ϊ˽�з���Ȩ��

	//ע�⣺����ģʽ�Ķ�����Բ����ͷţ���Ϊ�ǹ���Ķ���
	return 0;
}
#endif

//����ģʽ�Ĳ��裺
//1��ͨ��һ���� ֻ��ʵ����Ψһ��һ������
//2��˽�л�
// Ĭ�Ϲ��캯��
// �������캯��
// Ψһʵ����(��̬��Ա����)ָ�� - �����ʼ������ָ����������Ķ���
//3�������ṩ����getInstance(��̬��Ա����)�ӿڣ���ָ�뷵�� - ���ʾ�̬��Ա����
