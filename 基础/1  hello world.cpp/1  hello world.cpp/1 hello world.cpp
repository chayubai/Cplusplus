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

//VS   --  Windows�µı��������ɻ��� Ctrl + F7���� Ctrl+F5����
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

using namespace std; //��һ�����Ҫ��ʹ�������ռ�std�������Ϊ��һ��std���䣬�����������һЩ������Ҫ�������õ�
//����һ��ͷ�ļ������˺ܶ���࣬�������кܶ����ͬ���Ƶı���
//Ϊ�����ֲ�ͬ���µ���ͬ�������������������ռ�����������ʹ���ʹ�øÿռ�ı���
//���ڷ������������Ҫʹ�������ռ�std�µı��������Ǹ��߱�����ʹ�������ռ�std
int main()
{
	//cout ��׼��������󣬾��Ǻ���Ļ���� c out
	cout << "hello world" << endl;//��ͬ��cout << "hello world\n"
	//cout ��endl���������ռ�std�� <<���Ʋ���������C++����ʵ���˹��ܵĸ��� - ����������
	printf("hello world\n");
	//cout << "..." ����ʱ���Ϊ���ַ���������Ļ���������
	//<< ����Ϊ���Ʋ���������C++�¾����µĺ��壬������cout��ƴ�����������
	//���Ƶ��磺*�����ǳ˷���������Ҳ�����ǽ����ò�����
	//endl  - end line ˢ�»��������һ��У���������ƽ̨��windows�Ļس�ʹ��\r\n��Linux����\n��
	
	system("pause");//�밴���������
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
	cin >> num;// c in ��׼���� ������� 
	cin >> ch1;
	//>> ���Ʋ���������C++����ʵ���˹��ܵĸ��� - ����������
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

//������󷽷���
//1 ��ĳ��� ��Ա�����ͳ�Ա����
//2 ʵ����   ��Ķ���
//3 ������̼ӹ�����һ�����ĺ���
//	�������ӹ�����һ��������

//˼��1����ĵ��� ִ�й��̵ķ���  -> ����һ��һ����ִ��
//˼��2������һ���������� ����һ���࣬��һ������ĸ�������������ڴ�
//���������Ͷ����������ʵ���������ʱ��Ż�����ڴ�
//˼��3��C++����δ�������ֶ���������ͬһ����ĳ�Ա����

#if 0
#include <iostream>
using namespace std;
class circle
{
public:
	double r;//���ֵ
	double pi = 3.1415926;
	double area = pi * r * r;//��仰area = pi * r * r�ڴ��������ʱ���Ѿ�ִ���ˣ���ʱareaΪ���ֵ
};
int main()
{
	circle c1;//���еĳ�Ա�����Ѿ�ִ����
	cout << "������뾶r��";
	cin >> c1.r;//�������������ֵ����ֵ��c1�ĳ�Ա����r

	cout << c1.area << endl;//��ִ����仰ʱ��ֻ�Ǵӱ������ڵ��ڴ�����ֵ����û��ִ��pi * r * r
	//�����Ҫ�����Ա����
	return 0;
}
#endif