#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0 
//C�����У��ڶ��Ͽ��ٿռ�,��Ҫ�ֶ��ͷſռ�
void test1()
{
	//���ٱ����ռ�
	int* p = (int*)malloc(sizeof(int));
	//�жϿ����Ƿ�ɹ�
	*p = 10;
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	//��������ռ�
	int* array_p = (int*)malloc(sizeof(int)*10);
	//�жϿ����Ƿ�ɹ�
	for (int i = 0; i < 10; i++)
	{
		array_p[i] = i + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", array_p[i]);
	}
	printf("\n");
	if (array_p != NULL)
	{
		free(array_p);
		array_p = NULL;
	}
}

//C�����£���̬���ٿռ�����⣺
//1���������ȷ������ĳ��ȣ�������ȴ��󣬵��³��������
//2��malloc����һ��void*ָ��c++������void*��ֵ�������κ�ָ��,����ǿת��
//3��malloc���������ڴ�ʧ�ܣ����Ա����жϷ���ֵ��ȷ���ڴ����ɹ���
//4���û���ʹ�ö���֮ǰ�����ס������ʼ�������캯��������ʾ���ó�ʼ��(���캯
//�����ɱ���������)�û��п������ǵ��ó�ʼ��������

//C++�����У��ڶ��Ͽ��ٿռ�,Ҳ��Ҫ�ֶ��ͷſռ�,C++Ҳ����ʹ��malloc��free
void test2()
{
	//���ٱ����ռ�
	int* p = new int;//����һ��int�ռ䣬����Ĭ���޲ι��캯��
	*p = 10;
	if (p != NULL)
	{
		delete p;
		p = NULL;
	}

	//int a(10);//int ����Ҳ��һ���࣬�����вι��캯����ֵΪ10���ȼ���int a = 10;

	//�������ݿռ�
	int* array_p = new int[10];//����int10��Ԫ�ص�����ռ䣬����10��Ĭ���޲ι��캯��

	//int* array_p = new int(10);//����һ��int�ռ䣬�����вι��캯����ֵΪ10

	for (int i = 0; i < 10; i++)
	{
		array_p[i] = i + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << array_p[i] << " ";
	}
	cout << endl;
	if (array_p != NULL)
	{
		delete[] array_p;
		array_p = NULL;
	}

}
//ע�⣺malloc���Ժ�delete��new���Ժ�free�໥ʹ��
int main()
{
	test1();
	test2();
	return 0;
}
#endif

class Person
{
public:
	Person()//����ṩ�޲ι���
	{
		cout << "����Person()����" << endl;
	}
	Person(int a)
	{
		cout << "����Person(int a)����" << endl;
	}
	~Person()
	{
		cout << "����~Person()��������" << endl;
	}
};
//ע�⣺�����������ͷţ���ĳ�Ա�����ͳ�Ա����������Ϊ���͵ı������������������úͶ��ϵĿռ�
void test()
{
	/*Person a;//ջ������
	Person* p = &a;
	Person* &b = p;
	cout << p << endl;
	cout << b << endl;*/

	Person* p2 = new Person;//��������
	//����new�����Ķ��󣬶��᷵�ظ����͵�ָ��
	//malloc����void* ��Ҫǿת

	//����һ�д����൱�ڣ�
	/*Person* person = (Person*)malloc(sizeof(Person));
	if (person == 0)
	{
		return 0;
	}
	person->Init();//���캯��*/

	//delete p2;//delete�ᴥ�����������ĵ���
}

//malloc �� new ����
//1��malloc ��free ���ڿ⺯����new��delete���������
//2��malloc������ù��캯����free�����������������new����ù��캯����delete�������������
//3��malloc����void* C++����Ҫǿת��new���ش����Ķ������͵�ָ��
//4��malloc���ٵĿռ䣬Ĭ��û�г�ʼ������Ҫ��ʽ�ṩinit�����Կռ���г�ʼ��
//5��new���ٿռ䣬�����Ĭ�Ϲ��캯�����г�ʼ��

//ע�������Ҫ��void* ȥ����new�����Ķ�������void* �޷�������������
//��Ϊ��֪�����ͣ���֪��Ҫ�ͷŶ��Ŀռ�
void test2()
{
	void* p = new Person;//�������󣬲������޲ι���
	delete p;//���ᴥ����������

	//ע�⣺C++new�ؼ���������Java���Ե�new�ؼ���
}

//����new��������
void test3()
{
	//int* pInt = new int[10];
	//double* pD = new double[10];

	//***�����������飬һ������ñ�����Ĭ�Ϲ��캯��***��
	//������Ҫ��Ĭ�Ϲ��캯��������ᱨ��
	//���������Ĭ�Ϲ��죬Ĭ�Ϲ���ͻ�û���ˣ��޷�����Ĭ�Ϲ��캯�����ᵼ�±���
	//�����Ҫ��ʾ�ṩ�޲ι���
	Person* p = new Person[10];//һ�������Ĭ�Ϲ��캯��

	//�ͷ������ʱ����Ҫ��[]
	delete[] p;//��������дdelete p;��ʱֻ���ͷ�һ�����󣬻ᱨ��
	//delete[] p;����һ����������ļ�¼����������ͷ������е����ж���
	
	//�����޲ι��캯��ע����
	//����Զ������вι��캯����û����ʽ�����޲ι��캯������������������ʱ�ᱨ��
	//��˶����вι����ʱ�򣬽�����޲ι���һ��д��

	//Person* p2 = new Person(2)[10];//���������Ǵ����

	//ջ�Ͽ������飬����û��Ĭ�Ϲ���
	Person parr[10] = { Person(10),Person(20) };

	//Person* p2 = new Person[10]{ Person(10),Person(20) };
	//�˷��������飬��Ϊ�ܶ�������޷�ִ��
}

void test4()
{
	//ջ�Ͽ������飬����û��Ĭ�Ϲ��캯��
	Person arr[10] = { Person(10),Person(20) };
	//�۲��ӡ����
}
int main()
{
	//test();
	//test2();
	//test3();
	test4();
	return 0;
}
