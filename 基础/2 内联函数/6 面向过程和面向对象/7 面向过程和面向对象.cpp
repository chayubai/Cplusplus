#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Dog
{
public:
	char name[64];
	//面向对象：狗.吃(shi)
	void eat(const char* food)
	{
		cout << name << "吃" << food << endl;
	}
};
//面向过程：吃(狗，shi)
void eat(class Dog& dog, const char* food)
{
	cout << dog.name << "吃" << food << endl;
}
int main()
{
	Dog dog;
	strcpy(dog.name, "狗");
	//面向过程
	eat(dog, "翔");

	//面向对象
	dog.eat("翔");
	return 0;
}