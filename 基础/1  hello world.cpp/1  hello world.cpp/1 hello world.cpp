#define _CRT_SECURE_NO_WARNINGS 1

#if 0  //#if 0 ... #endif �����������룬0 ��Ϊ��������ע�ͷ�

//C�Ļ������
//C�ļ���cpp�п��Լ���
#include <stdio.h>
int main()
{
	printf("hello world\n");
	return 0;
}
#endif 

//VS   --  Windows�µı��������ɻ���
//C    --  Linux�µı�����Ϊgcc
//C++  --  Linux�µı�����Ϊg++

#if 0
//C++�Ļ������
#include <iostream>
//iostream ��C++������������ı�׼��input & output stream���൱��stdio.h

//C++����е�ͷ�ļ���������׺
#include <cstdio>
#include <stdio.h>
//C�е�ͷ�ļ���������ת��ΪC++ͷ�ļ���ȡ����׺����Cͷ�ļ����ϣ�cǰ׺

using namespace std; //��һ�����Ҫ
//����һ��ͷ�ļ������˺ܶ���࣬�������кܶ����ͬ���Ƶı���
//Ϊ�����ֲ�ͬ���µ���ͬ�������������������ռ�����������ʹ���ʹ�øÿռ�ı���
//���ڷ������������Ҫʹ�������ռ�std�µı��������Ǹ��߱�����ʹ�������ռ�std
int main()
{
	//cout ��׼��������󣬾��Ǻ���Ļ���� c out
	cout << "hello world" << endl;//��ͬ��cout << "hello world\n"
	printf("hello world\n");
	//cout << "..." ����ʱ���Ϊ���ַ���������Ļ��
	//<< ����Ϊ���Ʋ���������C++�¾����µĺ��壬������cout��ƴ�����������
	//���Ƶ��磺*�����ǳ˷���������Ҳ�����ǽ����ò�����
	//endl end line ˢ�»��������һ��У���������ƽ̨��windows�Ļس�ʹ��\r\n��Linux����\n��
	
	return 0;
}
#endif

#if 0
#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
	//����cout����ʽ����
	//1��fixedǿ����С���ķ�ʽ��ʽ

	//2��setprecision(2)������ʽ�ľ��ȣ�����С�������λ
	cout << fixed << setprecision(2);

	cout << 123456789.123456789 << endl;
	//3��setw������ʽ��ȣ���λ���ֽڣ�Ĭ���Ҷ��룬����������cout << left;
	//setfill(),���
	cout << setprecision(2) << setw(12) << 3.140 << endl;

	return 0;
}
#endif
//ע�⣺C++����char16_t/char32_t���ͣ���16/32λ��char����,unsigned char�޷����ַ�����,string�ַ�������

#if 0
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	//�����Ⱥ�˫���ȸ������ľ�������
	float numFloat = 10 / 3.0;
	double numDouble = 10 / 3.0;
	cout << fixed;
	cout << "numFloat = " << numFloat << endl;
	cout << "numDouble = " << numDouble << endl;

	cout << "numFloat = " << numFloat * 10000 << endl;//ʧȥ����
	cout << "numDouble = " << numDouble * 10000 << endl;

	return 0;
}
#endif

#include <iostream>
using namespace std;
int main()
{
#if 0
	int num;
	char ch1;
	cin >> num;
	cin >> ch1;

	cout << num << endl; 
	cout << ch1 << endl;
#endif

	int num;
	char ch1,ch2,ch3;
	cin >> num;
	cin >> ch1 >> ch2 >> ch3;

	cout << num << endl;
	cout << ch1 << endl;
	cout << ch2 << endl;
	cout << ch3 << endl;

	return 0;
}