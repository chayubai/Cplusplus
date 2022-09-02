#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//����ͨ��һ��ͨ����������ʵ�ֶ�char��int���͵�������������˳��Ӵ�С���㷨��ѡ������
template<typename T>//typename �� class һ�� һ��typename���ں���ģ�壬class������ģ��
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//�㷨��ѡ������
template<typename T>//�ٴ�����ģ�壬���߱���������������ĺ����л����е�T��Ҫ����
void mySort1(T arr[], int sz)
{
	//���ѭ����n�����ֵ
	for (int i = 0; i < sz; i++)
	{
		int max = i;//�������ε�i���±��Ԫ��ֵ���
		//�ڲ�ѭ���������n - i��Ԫ�رȽϣ��ҳ����ֵ���±�
		for (int j = i + 1; j < sz; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		//�ж������max�Ϳ�ʼ�϶���i�Ƿ�һ�£������ͬ��������
		//��ÿ�����յ�����������ηŵ��±�Ϊi��λ��
		if (i != max)
		{
			mySwap(arr[i], arr[max]);//����
		}
	}
}

//����ͨ��һ��ͨ����������ʵ�ֶ�char��int���͵�������������˳���С����
//�㷨��ð������
template<typename T>
void mySort2(T arr[], int sz)//void mySort2(T* arr, int sz)
{
	bool flag = false;
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)//���Զ������������������д����Ż�
		{
			if (arr[j] > arr[j + 1])
			{
				flag = true;
				mySwap(arr[j], arr[j + 1]);
			}
		}
		if (flag == false)
			break;
	}
	//����
#if 0
	for (int i = 0; i < sz; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if (arr[j] > arr[i])//�Ӵ�С
			{
				mySwap(arr[j], arr[i]);
			}
		}
	}
#endif
}

template<typename T>
void printArray(T arr[],int len)//void printArray(T* arr,int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
}

void test1()
{
	int arr[] = { 1,9,30,3,2,0,17,5,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	mySort1(arr, sz);
	printArray(arr, sz);
	cout << endl;

	char ch1[] = "helloworld";
	//int sz = sizeof(ch1) / sizeof(ch1[0]) - 1;//�����'\0'
	int len = strlen(ch1);
	mySort1(ch1, len);
	printArray(ch1, len);
	cout << endl;

	char ch2[] = { 'b','d','n','a','e','z','c','y','w' };
	sz = sizeof(ch2) / sizeof(ch2[0]);
	mySort1(ch2, sz);
	printArray(ch2, sz);
}
void test2()
{
	int arr[] = { 1,9,30,3,2,0,17,5,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	mySort2(arr,sz);
	printArray(arr, sz);
	cout << endl;

	char ch1[] = "helloworld";
	//int sz = sizeof(ch1) / sizeof(ch1[0]) - 1;//�����'\0'
	int len = strlen(ch1);
	mySort2(ch1, len);
	printArray(ch1, len);
	cout << endl;

	char ch2[] = { 'b','d','n','a','e','z','c','y','w' };
	sz = sizeof(ch2) / sizeof(ch2[0]);
	mySort2(ch2, sz);
	printArray(ch2, sz);
}

int main()
{
	//test1();
	test2();
	return 0;
}