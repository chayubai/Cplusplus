#define _CRT_SECURE_NO_WARNINGS 1

//1��Linux��,index.cpp�б�д����
#include <iostream>
using namespace std;

#define MAX 1024

int main()
{
	cout << MAX << endl;

	return 0;
}
//2��Ԥ����(��)
//	g++ -E index.cpp -o index.i//-o����ļ�
//	�鿴vim index.i�Ĵ������
//	Ԥ��������е�MAX���滻��1024

//3������(��)
//	g++ -S index.i -o index.s
//	�鿴vim index.s�Ĵ���

//4�����(��)
//	g++ -c index.s -o index.o
//	�鿴vim index.o�Ĵ���

//5������(��)
//	g++ index.s -o index
//	file index	��֪Ϊexecutale
//	./index	ִ��