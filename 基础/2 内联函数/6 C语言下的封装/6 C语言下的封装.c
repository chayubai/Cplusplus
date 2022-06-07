#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
struct Person
{
	char name[64];
	int age;
};
void PersonEating(struct Person *p)//结构体传址调用
{
	printf("%s正在吃饭\n", p->name);
}
struct Dog
{
	char name[64];
	int age;
};
void DogEating(struct Dog* d)//结构体传址调用
{
	printf("%s正在狗粮\n", d->name);
}
int main()
{
	struct Person p;
	strcpy(p.name, "张三");
	PersonEating(&p);//结构体传址调用较好

	struct Dog d;
	strcpy(d.name, "旺财");
	DogEating(&d);

	struct Person p2;
	strcpy(p2.name, "李四");
	DogEating(&p2);
	return 0;
}
//C语言下的封装，缺点：属性和行为分离