#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
struct Person
{
	char name[64];
	int age;
};
void PersonEating(struct Person *p)//�ṹ�崫ַ����
{
	printf("%s���ڳԷ�\n", p->name);
}
struct Dog
{
	char name[64];
	int age;
};
void DogEating(struct Dog* d)//�ṹ�崫ַ����
{
	printf("%s���ڹ���\n", d->name);
}
int main()
{
	struct Person p;
	strcpy(p.name, "����");
	PersonEating(&p);//�ṹ�崫ַ���ýϺ�

	struct Dog d;
	strcpy(d.name, "����");
	DogEating(&d);

	struct Person p2;
	strcpy(p2.name, "����");
	DogEating(&p2);
	return 0;
}
//C�����µķ�װ��ȱ�㣺���Ժ���Ϊ����