#define _CRT_SECURE_NO_WARNINGS 1
//1�����أ�ͬһ�������ͬ������
//a.ͬһ��������
//b.��������������˳�򣬲������Ͳ�ͬ
//c.�ͺ�������ֵ��û�й�ϵ
//d.constҲ������Ϊ��������   //do(const Teacher& t){}  do(Teacher& t){}

//2���ض��壨���أ�
//a.�м̳�
//b.���ࣨ�����ࣩ���¶��常�ࣨ���ࣩ��ͬ����Ա����virtual������
//c.���ظ����������ذ汾�ĺ����������Ҫ���ø�����Щ��������Ҫ��������

//3����д�����ǡ���̬��
//a.�м̳�
//b.���ࣨ�����ࣩ��д���ࣨ���ࣩ��virtual����
//c.��������ֵ���������֣���������������ͻ�����麯��һ��

class A
{
public:
	//ͬһ�������£�func1��������
	void func1() {}
	void func1(int a) {}
	void func1(int a,int b) {}
	void func2() {}
	virtual void func3() {}

};
class B :public A
{
public:
	//�ض�������func2,�����˻����func2����
	void func2() {}
	//��д�����func3������Ҳ���Ը��ǻ���func3
	virtual void func3() {}
};