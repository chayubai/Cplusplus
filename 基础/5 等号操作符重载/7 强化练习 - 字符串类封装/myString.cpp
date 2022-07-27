#include "myString.h"

//�вι���
myString::myString(const char* str)
{
	//cout << "myString�вι��캯������" << endl;//���Ժ����Ƿ�����
	this->pString = new char[strlen(str) + 1];
	strcpy(this->pString, str);
	this->m_Size = strlen(str);
}

//��������
myString::myString(const myString& str)
{
	//���
	//cout << "�������캯������" << endl;//���Ժ����Ƿ�����
	//ͬ��*this��str
	this->pString = new char[strlen(str.pString)+1];//strlen��������\0���������д+1
	strcpy(this->pString, str.pString);
	this->m_Size = str.m_Size;
}

//����
myString::~myString()
{
	if (this->pString != NULL)
	{
		//cout << "������������" << endl;//���Ժ����Ƿ�����
		delete[] this->pString;
		this->pString = NULL;
	}
}

//��������<<������
ostream& operator<<(ostream& cout, myString& str)
{
	cout << str.pString;//������������ڲ�ά�����ַ���str.pString������str
	return cout;
}

//��������>>������
istream& operator>>(istream& cin, myString& str)
{
	//�ж�ԭ������str�Ƿ������ݣ�������գ�����ֱ�Ӳ�ִ����һ�������ڴ�й¶
	if (str.pString)
	{
		delete[] str.pString;
		str.pString = NULL;
	}

	//������ʱ����buf����¼�û�����str������
	char buf[1024];
	//���û������str�����ݵ�buf��
	cin >> buf; //�ȴ��û�����

	//�����ݷ���str.pString�У����û��ṩ��������ά��
	str.pString = new char[strlen(buf) + 1];
	strcpy(str.pString, buf);
	str.m_Size = strlen(buf);

	//ע�⣺Ϊʲô����ֱ��cin >> str.pString;
	//cin >> str.pString;
	//str.pString = new char[strlen(str.pString) + 1];
	//strcpy(str.pString, str.pString);
	//str.m_Size = strlen(str.pString);

	return cin;
}

//���� = �����
myString& myString::operator=(const char* str)
{
	//�ж�ԭ������str2�Ƿ������ݣ��������
	if (this->pString!=NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}
	//���
	this->pString = new char[strlen(str) + 1];
	strcpy(this->pString, str);
	this->m_Size = strlen(str);
	return *this;
}
myString& myString::operator=(const myString& str)
{
	//�ж�ԭ������str2�Ƿ������ݣ��������
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}
	//���
	this->pString = new char[strlen(str.pString) + 1];
	strcpy(this->pString, str.pString);
	this->m_Size = strlen(str.pString);
	return *this;
}

//���� [] �����
char& myString::operator[](int index)
{
	return this->pString[index];
}

//���� + ����������ص����µ��ַ���������ʵ����+
myString myString::operator+(const char* str)
{
	//����abc������def
	//���ٿռ�
	int newSize = this->m_Size + strlen(str) + 1;
	char* temp = new char[newSize];//ע�����������char*
	//���
	memset(temp, 0, newSize);
	//ƴ��
	strcat(temp, this->pString);
	strcat(temp, str);

	myString newString = temp;//���ÿ������캯��

	delete[] temp;

	return newString;//����temp�����ڷ��ص���char* ���յ���myString���ܷ�ǿת��
}
myString myString::operator+(const myString& str)
{
	int newSize = this->m_Size + strlen(str.pString) + 1;
	char* temp = new char[newSize];
	//���
	memset(temp, 0, newSize);
	strcat(temp, this->pString);
	strcat(temp, str.pString);

	myString newString = temp;

	delete[] temp;

	return newString;
}

//���� == �����
bool myString::operator==(const char* str)
{
	if (strcmp(this->pString, str)==0)//strcmp��ȷ���0
	{//strcmp(this->pString, str)==0 && this->m_Size == strlen(str)
		return true;
	}
	else
	{
		return false;
	}
}
bool myString::operator==(const myString& str)
{
	if (strcmp(this->pString, str.pString)==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}