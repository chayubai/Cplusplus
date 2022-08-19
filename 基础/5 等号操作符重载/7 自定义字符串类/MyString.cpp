#include "MyString.h"
//�޲ι���
MyString::MyString()//MyString mystring;��������޲ι��죬�ַ�����ַΪ��
{
	this->len = 0;
	this->str = NULL;//��\0��== NULL 0�ַ����ָ��  ""  == "\0" ���ַ���
}
//�вι��� 
MyString::MyString(const char* str)
{
	if (str == NULL)//char* c = NULL;MyString s(c);����NULL,����һ�����ַ���
	{
		this->len = 0;
		this->str = new char[0 + 1];
		strcpy(this->str, "");
	}
	else
	{
		int len = strlen(str);
		this->len = len;
		this->str = new char[len + 1];
		strcpy(this->str, str);
	}
}
//��������
MyString::~MyString()
{
	if (this->str != NULL)
	{
		//cout << this->str << "ִ������������" << endl;
		delete[] this->str;//������Ҫdelete����
		this->str = NULL;
		this->len = 0;
	}
}
//��ʼ����ʱ����õ� û������ - ��������
MyString::MyString(const MyString& another)
{
	this->len = another.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, another.str);
}

//����<<
ostream& operator<<(ostream& os, MyString& s)//ע�⣺�������Ҫ������
{
	os << s.str;
	return os;
}
//����[]
char& MyString::operator[](int index)
{
	return this->str[index];
}
//����=
MyString& MyString::operator=(const MyString& another)
{
	//�ж�����Ƚ�
	if (this == &another)
	{
		return *this;
	}
	if (this->str != NULL)
	{
		delete[] this->str;
		this->str = NULL;
		this->len = 0;
	}
	//���
	this->len = another.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, another.str);

	return *this;
}
//����>>
istream& operator>>(istream& is, MyString& s)//�������Ҫ������
{
	//1����s֮ǰ���ַ����ͷŵ�
	if (s.str != NULL)
	{
		delete[] s.str;
		s.str = NULL;
		s.len = 0;
	}
	//2��ͨ��cin����µ��ַ���

	//is >> s.str;//char *str = NULL;cin >> str;����ָ������д���ݣ���������
	//��ʱ����һ����s.str���ÿ���
	char temp_str[4096] = { 0 };
	
	cin >> temp_str;

	int len = strlen(temp_str);
	s.str = new char[len + 1];
	strcpy(s.str, temp_str);
	s.len = len;
	return is;
}

//���ز�����+
MyString MyString::operator+(MyString& another)//�����MyString& ���ܷ��ؾֲ�����������
{
	MyString temp;
	int len = this->len + another.len;
	temp.len = len;
	temp.str = new char[len + 1];

	memset(temp.str, 0, len + 1);//��գ���������������׷��
	strcat(temp.str, this->str);
	//����ֱ��ʹ��strcpy(temp.str, this->str)����Բ���Ҫ��һ�д���

	strcat(temp.str, another.str);

	return temp;
}