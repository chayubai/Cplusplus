#define _CRT_SECURE_NO_WARNINGS 1
//д�ļ� - ���ļ��������

//д�ļ��������£�
//
//1. ����ͷ�ļ�
//
//#include <fstream>
//
//2. ����������
//
//ofstream ofs;
//
//3. ���ļ�
//
//ofs.open("�ļ�·��", �򿪷�ʽ);
//
//4. д����
//
//ofs << "д�������";
//
//5. �ر��ļ�
//
//ofs.close();

//�ļ��򿪷�ʽ��
//
//�򿪷�ʽ    | ����
//ios::in     | Ϊ���ļ������ļ�        
//ios::out    | Ϊд�ļ������ļ�
//ios::ate    | ��ʼλ�ã��ļ�β
//ios::app    | ׷�ӷ�ʽд�ļ�               
//ios::trunc  | ����ļ�������ɾ�����ٴ���   
//ios::binary | �����Ʒ�ʽ 
//
//ע�⣺ �ļ��򿪷�ʽ�������ʹ�ã����� | ������
//
//���磺 �ö����Ʒ�ʽд�ļ� ios::binary | ios::out

#include <ostream>
using namespace std;
#include <fstream>

void test01()
{
    ofstream ofs;
    ofs.open("test.txt", ios::out);//test.txt��������Ŀ���ڵ�ͬ��Ŀ¼��

    ofs << "����������" << endl;
    ofs << "�Ա���" << endl;
    ofs << "���䣺18" << endl;

    ofs.close();
}

int main() {

    test01();

    system("pause");

    return 0;
}

//�ܽ᣺
//* �ļ������������ͷ�ļ� fstream
//* ���ļ��������� ofstream  ������fstream��
//* ���ļ�ʱ����Ҫָ�������ļ���·�����Լ��򿪷�ʽ
//* ���� << �������ļ���д����
//* ������ϣ�Ҫ�ر��ļ�