#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0 
//static��Ա��������������ģ���������ĳ������ģ����Ŀռ䲻��ջ�ϣ����ھ�̬��
class C1
{
public:
	int i;//4
	int j;//4
	int k;//4
};
class C2
{
public:
	int i;
	int j;
	int k;
	static int m;//4
public:
	int getK()//4
	{
		return k;
	}
	void setK(int val)//4
	{
		k = val;
	}
};
struct S1
{
	int i;
	int j;
	int k;
};
struct S2
{
	int i;
	int j;
	int k;
	static int m;
};
int main()
{
	//ֻ�ж���ķǾ�̬�ĳ�Ա��������ջ��ռ�ÿռ䣬��̬��Ա�����Ŀռ��ھ�̬�������ٵĿռ�
	cout << "C1:" << sizeof(C1) << endl;
	cout << "C2:" << sizeof(C2) << endl;
	//��Ա�����Ŀռ䲻���ڶ���
	C2 c1, c2;
	c1.getK();//Ϊʲô��return c1.k
	c2.getK();//Ϊʲô��return c2.k

	cout << "---------------" << endl;

	//ֻ�зǾ�̬�ı�������ջ��ռ�ÿռ䣬��̬�����Ŀռ��ھ�̬�������ٵĿռ�
	cout << "S1:" << sizeof(S1) << endl;
	cout << "S2:" << sizeof(S2) << endl;
	return 0;
}
#endif

class Test
{
public:
	Test(int i)
	{
		mI = i;
	}
	int getI()
	{
		return mI;
		//this����ָ����øó�Ա���������Ķ���ĵ�ַ
		//return this->mI;
	}
#if 0
	int getI(Test *this)
	{
		return this->mI;
	}
#endif

private:
	int mI;
};
#if 0
//�Ὣ������෭��Ϊ��������ָ������
//Test t1(10);��Test(&t1,10);��t1.getI();��getI(&t1);
struct Test 
{
	int mI;
};
void Test(struct Test* pthis,int i)
{
	pthis->mI = i;
}
int getI(struct Test *pthis)
{
	return pthis->mI;
}
#endif
int main()
{
	Test t1(10);//��Test(&t1,10);
	t1.getI();//��getI(&t1);
	Test t2(20);//��Test(&t2,10);
	t2.getI();//��getI(&t2);
	return 0;
}