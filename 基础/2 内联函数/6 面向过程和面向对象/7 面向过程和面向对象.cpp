#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Dog
{
public:
	char name[64];
	//������󣺹�.��(shi)
	void eat(const char* food)
	{
		cout << name << "��" << food << endl;
	}
};
//������̣���(����shi)
void eat(class Dog& dog, const char* food)
{
	cout << dog.name << "��" << food << endl;
}
int main()
{
	Dog dog;
	strcpy(dog.name, "��");
	//�������
	eat(dog, "��");

	//�������
	dog.eat("��");
	return 0;
}