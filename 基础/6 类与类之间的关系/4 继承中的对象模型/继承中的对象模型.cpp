#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//ע�⣺�����˽�����ԣ��Ǳ��̳еģ�ֻ��������ʲ������ɱ�������������
//�������ÿ�����Ա���߲鿴����ģ��
//���ߵ�·����Develper Command Prompt for VS2019
//��ת�̷����ҵ������ļ�·����:cd ./VS2019/C++code/C++code/����/1 ������֮��Ĺ�ϵ/4 �̳��еĶ���ģ��
//�������dir �鿴��·���µ��ļ����ļ���
//�������cl �����Ļ
//����������cl(��ĸl) /d1(����1) reportSingleClassLayout���� �ļ���.cpp��
//���Կ���ָ����ĳ�Ա����������������˽�г�ԱҲ�̳������ˡ�

class Base
{
public:
	int m_A;
private:
	int m_B;
protected:
	int m_C;
};

class Son :public Base
{
public:
	int m_D;
};

int main()
{
	cout << "size of Son =" << sizeof(Son) << endl;
	//ע�⣺����Ĵ�СΪ1�ֽڣ��սṹ���СΪ1�ֽ�

	return 0;
}