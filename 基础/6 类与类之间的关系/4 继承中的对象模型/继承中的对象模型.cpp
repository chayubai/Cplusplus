#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//ע�⣺�����˽�����ԣ��Ǳ��̳еģ�ֻ��������ʲ������ɱ�������������
//�������ÿ�����Ա���߲鿴����ģ��
//1�����ߵ�·����Develper Command Prompt for VS2019 �����
//2����ת�̷����ҵ������ļ�·����:cd ./VS2019/C++code/C++code/����/1 ������֮��Ĺ�ϵ/4 �̳��еĶ���ģ��
//���ߵ��VS���Ҽ�����ļ������������ڵ��ļ��С�������·�����Ҽ�ճ��
//3���������dir       �鿴��·���µ��ļ����ļ���
//�������cl �����Ļ
//4������������cl(��ĸl) /d1(����1) reportSingleClassLayout���� �ļ���.cpp��
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