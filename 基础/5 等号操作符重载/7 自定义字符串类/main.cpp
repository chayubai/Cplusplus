#define _CRT_SECURE_NO_WARNINGS 1

#include "MyString.h"

int main()
{
#if 0
	MyString s1("abc");//�вι���
	MyString s2(s1);//��������
	MyString s3 = "123";

	cout << s1 << endl;
	cout << s2 << endl;

	s1[1] = 'X';//����[]
	cout << s1 << endl;

	s1 = s3;//����=
	cout << s1 << endl;

	cin >> s1;
	cout << s1 << endl;
#endif

#if 0
	MyString s4("abc");
	cin >> s4;
	cout << s4 << endl;
#endif

	MyString s1("123");
	MyString s2("456");
	MyString s = s1 + s2 + s1;//s1 + s2 ���ÿ������췵����ʱ���󣬷�����������
	
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s << endl;

	//cout << (s1 + s2 + s1) << endl;//����Ϊʲô��
	return 0;
}