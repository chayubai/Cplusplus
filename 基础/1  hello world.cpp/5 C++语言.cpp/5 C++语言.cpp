#define _CRT_SECURE_NO_WARNINGS 1
#if 0
//1��ȫ�ֱ��������ǿ��C++�����ض���
#include <iostream>
using namespace std;
//C++����ȫ�ֱ������壬�������ظ����壬�ᱨ��
int g_val;
int g_val = 20;
int main()
{
	cout << g_val << endl;
	return 0;
}
#endif

#if 0
//2�����������ǿ���������ͼ�⣬����ֵ��⣬�β����ͼ�⣬�������ò��������
#include <iostream>
using namespace std;
func()
{
	return 10;
}
int gunc(int a)
{
	return 20;
}
int main()
{
	//C++���Եĺ���ʵ�֣������з���ֵ��һ����Ҫ�з������ͣ�����ᱨ��
	func();
	//C++���Եĺ���ʵ�֣����޲���ʱ�����������ʱ���벻ƥ��������Ĳ���ʱ��������뱨��
	gunc(10, 20, 30);

	return 0;
}
#endif

#if 0
//3������ת�������ǿ
#include <iostream>
using namespace std;
int main()
{
	//��������ת��
	char* p = (char*)malloc(64);

	return 0;
}
#endif

#if 0
//4��struct��ǿ:C++���Էź�����������������������Բ��ӹؼ���struct
#include <iostream>
using namespace std;
struct student
{
	int id;
	char name[20];
	void func()
	{

	}
};
int main()
{
	//C++���Խṹ������Ķ��壬���Լ���struct
	struct student s1;
	student s2;
	s2.func();
	return 0;
}
#endif

#if 0
//5��bool������չ��C������û��������ͣ�C++��bool����
#include <iostream>
using namespace std;
int main()
{
	//C++���Ե���1����0����0Ϊ�棬0Ϊ�١���������bool���ͣ������͵�ֵֻ��ȡ1��0
	bool flag = true;
	cout << "flag(true):" << flag << endl;

	flag = false;
	cout << "flag(false):" << flag << endl;

	flag = -20;
	cout << "flag(-20):" << flag << endl;

	//bool���͵Ĵ�СΪ1���ֽ�
	cout << "bool�Ĵ�С:" << sizeof(bool) << endl;

	return 0;
}
#endif

#if 0
//6����Ŀ�������ǿ
#include <iostream>
using namespace std;
int main()
{
	//C++���Ե���Ŀ�����
	int a = 10;
	int b = 20;
	int c = a < b ? a : b;
	cout << c << endl;

	//C++���Ե���Ŀ����������ʵ��Ǳ��������ã�����ֱ�ӵ���ֵ
	//���ص�������
	(a < b ? a : b) = 50;//C++�·��ص��Ǳ�����a = 50
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	a < b ? a : b = 50;//C++�·��ص��Ǳ�������a < b ? a : (b = 50)
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	return 0;
}
#endif

#if 0
//7��const��ǿ
#include <iostream>
using namespace std;
const int m_A = 100;//ȫ��const����C���Խ���һ��
int main()
{
	//C++���ԣ�const���εı���a��ֵ����ͨ��ָ�벻�ܱ��ı�
	const int a = 10;//�ֲ�const  a�������ĳ���
	//const����ڷ��ű��У���key��value��ֵ�Ե���ʽ��Ӧ����key��a��value��10

	int* p = (int*)&a;//����C++�ϸ�����ת��������&a��const int*���ͣ�ҪǿתΪint*
	*p = 50;//*p�ı������ʱ���ٵ�temp
	
	cout << "a = " << a << endl;
	//����a��ֵû�з����仯
	cout << "*p = " << *p << endl;
	//*p = 50�޸ĵ���ʲô��
	//int temp = a;int *p = &temp;
	//����const���εľֲ�����ȡ��ַ��ʱ�򣬱�������ջ�ϸ�����������ʱ�ڴ�ռ�temp
	//pָ��ָ�����temp

	//C++���ԣ�const���εı���a���ǳ��������Գ�ʼ������
	int array[a] = { 0 };
	return 0;
}
#endif

#if 0
//8��
#include <iostream>
using namespace std;
int main()
{
	int a = 10;
	cout << a << endl;

	int i = 0;
	//C++�����Ķ��壬�����涨��
	for (i = 0; i < 10; i++)
	{
		cout << i << " ";
	}
	return 0;
}
#endif



#if 0
//9��
#include <iostream>
enum season
{
	SPR = 0,
	SUM,
	AUT,
	WIN
};
int main()
{
	//C++����ö�����ͱ����������Ը�ֵΪ����ֵ������ᱨ��
	//enum season s = 0;
	enum season s = SPR;
	if (s == 3)
	{
		//...
	}
	return 0;
}
#endif