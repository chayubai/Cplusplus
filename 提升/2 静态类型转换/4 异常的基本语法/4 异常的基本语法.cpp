#define _CRT_SECURE_NO_WARNINGS 1

//�쳣������Ǵ�������еĴ�����ν������ָ�ڳ������еĹ����з�����һЩ�쳣�¼�
//(�磺��0����������±�Խ�磬��Ҫ��ȡ���ļ������ڣ���ָ�룬�ڴ治��ȵȡ�)

#if 0
#include <stdio.h>
//C�����е��쳣����ȱ�ݣ�����ֵ��ͳһ������ֵֻ��һ�����޷������ǽ�������쳣��
int myDivision(int a, int b)
{
	if (b == 0)
	{
		return -1;//����10 -10���ͻ��������
	}
	return a / b;
}
void test1()
{
	int a = 10;
	int b = 0;
	int ret = myDivision(a, b);
	if (ret == -1)
	{
		printf("�쳣");
	}
}
void test2()
{
	int a = 10;
	int b = -10;
	int ret = myDivision(a, b);
	if (ret == -1)
	{
		printf("�쳣");
	}
}//����쳣������������㺯�����ã����ճ���ͻ��쳣

int main()
{
	test1();
	test2();
	return 0;
}
#endif

#include <iostream>
using namespace std;

class MyException
{
public:
	void printError()
	{
		cout << "���Լ����쳣"<< endl;
	}
};

int myDivision(int a, int b)
{
	if (b == 0)
	{
		//�׳����쳣�������ͣ������ϸ�ƥ��
		//throw -1;//-1����int���ͣ�Ҳ����������int���ݡ���ʾ�׳�int���͵��쳣
		//throw 'a';//�׳�char���͵��쳣
		//throw 3.14;//�׳�double���͵��쳣
		//...
		/*string str = "abc";
		throw str;*///�׳�string���͵��쳣

		throw MyException();//�׳�MyException����������
	}
	return a / b;
}
void test()
{
	int a = 10;
	int b = 0;
	try//����ִ�����´������Ƿ��쳣������쳣����д������û���쳣catch�δ����ǲ���ִ��
	{
		myDivision(a, b);
	}
	//�쳣�Ĳ���󣬽��д���
	catch (int)//�쳣ʱ�������׳���ֵ�����ͽ���ƥ�䡣
	{
		cout << "int�����쳣����" << endl;
	}
	//��������⵽�쳣�����׳����쳣��û����֮��Ӧ���쳣����ʹ����ͻᱨ����ֹ
	//ע�⣺���û����ȥ�����׳����쳣������ͻ���ֹ
	catch (char)
	{
		cout << "char�����쳣����" << endl;
	}
	catch (MyException e)//�Զ������͵��쳣����
	{
		e.printError();
	}
	/*catch (double)
	{
		throw;//�������쳣�����ǲ��봦�����������׳�����쳣
		cout << "double�����쳣����" << endl;//��һ�в���ִ��
	}
	catch (...)//...������������
	{
		cout << "���������쳣����" << endl;
	}*/

}
int main()
{
	try
	{
		test();
	}
	catch(double)
	{
		cout << "main������ double�����쳣����" << endl;
	}
	catch (...)
	{
		cout << "main������ ���������쳣����" << endl;
	}
	//�ȳ���ִ��main�����е�test()������Ƿ��쳣��
	//��ִ�е�����myDivision(a, b)ʱ���ٳ���ִ��myDivision(a, b)������Ƿ��쳣��
	//�����ʱ�����쳣�˾ͻ��׳���Ӧ���쳣��Ϣ������һ��test�����쳣 (��ʱtest���ȴ����쳣������������һ��main����) ��
	//���test�����һ�㣬û�д����쳣Ҳ���׳��쳣������ͻ���ֹ�����test�������һ�㣬��û�ж��쳣���д���������һ�������д����ˣ�����򲻻���ֹ��
	
	//�����ʱ��һ�㲻�봦����쳣����ʹ�ùؼ���throw�����׳��쳣����test����һ�㼴main������
	//���main��û��ȥ�����׳����쳣������ͻ���ֹ

	//��������쳣����Ҫ���д���������һ��ȥ�����������ͻ��Զ�����terminate�������ó�����ֹ
	
	return 0;
}