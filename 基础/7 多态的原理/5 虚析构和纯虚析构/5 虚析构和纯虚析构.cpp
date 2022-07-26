#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "����Animal���캯��" << endl;
	}

	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
	/*~Animal()
	{
		cout << "����Animal���캯��" << endl;
	}*/

	//�����෢����̬ʱ�������������ָ����������ԣ���ôҪ��������������delete�ͷŵ�ʱ�򣬵����������������
	/*virtual ~Animal()
	{
		cout << "����Animal���캯��" << endl;
	}*/
	
	virtual ~Animal() = 0;//���ֱ������д���ǻᱨ���
	//ע�⣺�������� ��Ҫ��������Ҳ��Ҫ��ʵ�֣�ʵ�ֵ�Ŀ���������Ը����ڵĶ��ϵĿռ䣬�����ͷ�
	//������������������ʵ��

	//ע�⣺���麯������ֻҪ���������������� ��Ҫ��������Ҳ��Ҫ��ʵ��

	//���һ�����У����˴����������������������Ҳ���ڳ����࣬�޷�ʵ��������
	//�麯�����̳к�������Ҫ��д�麯�������������޷�ʵ�����������������������޷��̳У���˲���Ҫ��д
};

//��������������������������
Animal::~Animal()
{
	cout << "����Animal������������" << endl;
}

class Cat :public Animal
{
public:
	Cat(const char* name)
	{
		//this->m_name = name;//Ϊʲô������ֵ�����ԣ�
		cout << "����Cat���캯��" << endl;
		this->m_name = new char[strlen(name) + 1];//��������new char[]
		strcpy(this->m_name, name);
	}
	virtual void speak()
	{
		cout << "Сè��˵��" << endl;
	}
	~Cat()
	{
		if (this->m_name)
		{
			cout << "����Cat���캯��" << endl;
			delete[] this->m_name;
			this->m_name = NULL;
		}
	}
	char* m_name;
};
void test1()
{
	Animal* animal = new Cat("Tom");

	//ʵ����������󣬻��ȵ��ø���Ĺ��죬�ٵ����������Ȼ�����������࣬����������
	animal->speak();

	//ע�⣺�����û���ͷ�animalָ��Ŀռ䣬�򲻻������������

	delete animal;

	//��ʱ���֣�ֻ�����˸��������������û�е����������������
	//��ν����-����������
	//������virtual�ؼ���������������
}

void test2()
{
	//Animal a;//��Animal�����˴���������Ҳ�ǳ����࣬�޷�ʵ����
}
int main()
{
	test1();
	return 0;
}