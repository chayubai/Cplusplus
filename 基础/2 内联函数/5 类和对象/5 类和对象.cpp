#define _CRT_SECURE_NO_WARNINGS 1

//���ǶԶ���ĳ���
//�����Ƕ����ʵ��
#if 0
#include <iostream>
using namespace std;

struct Hero
{
	char name[20];
	int sex;
	void printHero()
	{

	}
};
void printHero(struct Hero &h)
{
	cout << "hero" << endl;
	cout << "name" << h.name << endl;
	cout << "sex" << h.sex << endl;
}

class AdvHero
{
public://���ʿ���Ȩ��
	char name[20];
	int sex;
	void printHero()
	{
		cout << "advHero" << endl;
		cout << "name" << name << endl;
		cout << "sex" << sex << endl;
	}
};
int main()
{	
	Hero h;//���� ����
	//h.name = "gailun";
	strcpy(h.name, "gailun");
	h.sex = 1;
	printHero(h);

	AdvHero advH;//�� ����
	strcpy(advH.name, "ChunBro");
	advH.sex = 1;

	//��C++�У�
	//�ṹ����඼�Ǹ�������
	//�ṹ��Ҳ�����г�Ա����
	//������г�Ա������Ҳ�����г�Ա�������������Ժ���Ϊ���������ͺ�����
	//�ṹ�����һ���࣬�ṹ������Ψһ�����ǣ�Ĭ�Ϸ��ʿ���Ȩ�޲�ͬ
	//����ģ�壬���������ʵ��

	//��C�����У�
	//�ṹ��ֻ�г�Ա������û�г�Ա����
	return 0;
}
#endif

#include <iostream>
using namespace std;

class Animal
{
	//{}���ڽ�����ڲ������������ⲿ
public:
	//���еı��� ��Ϊ��Ա���� ��Ա����
	//public���¶���ĳ�Ա�����ͳ�Ա����������������ڲ����ⲿ�����Է���
	char kind[64];
	char color[20];

	//���еĺ��� ��Ϊ��Ա���� ��Ա����
	void printAnimal()
	{
		cout << "kind" << kind << endl;
		cout << "color" << color << endl;
	}
	void write()
	{
		cout << kind << "��ʼд��" << endl;
	}
	void run()
	{
		cout << kind << "������" << endl;
	}
private:
	//private���¶���ĳ�Ա�����ͳ�Ա������ֻ�ܹ�������ڲ�����
	
};

int main()
{
	Animal dog;
	//public���¶���ĳ�Ա�����ͳ�Ա������������ⲿʹ��
	strcpy(dog.kind, "dog");
	strcpy(dog.color, "yellow");

	Animal sheep;
	strcpy(sheep.kind, "sheep");
	strcpy(sheep.color, "white");

	dog.write();
	sheep.run();
	return 0;
}