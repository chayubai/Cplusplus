#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
struct teacher
{
	int id;
	char name[20];
};
//����ָ��
int get_mem1(struct teacher **tpp)//�ṹ��ָ�����->��Ա���ṹ���������.��Ա 
{
	//tppָ��t��ָ�룬*tppָ�룬ָ�����t���壬**tpp t����
	//ֱ��*tpp = (struct teacher*)malloc(sizeof(struct teacher));
	struct teacher* tp = NULL;
	tp = (struct teacher*)malloc(sizeof(struct teacher));
	if (tp == NULL)
	{
		return -1;
	}
	tp->id = 100;
	strcpy(tp->name, "lisi");

	*tpp = tp;
	return 0;
}
void free_teacher1(struct teacher** tpp)
{
	if (tpp == NULL)
		return;
	struct teacher* tp = *tpp;
	if (tp != NULL)
	{
		free(tp);
		*tpp = NULL;
	}
}
//ͬ��ָ������
int get_mem2(struct teacher* &tp)//struct teacher* t = NULL;struct teacher* &tp = t
{
	tp = (struct teacher*)malloc(sizeof(struct teacher));
	if (tp == NULL)
	{
		return -1;
	}
	tp->id = 100;
	strcpy(tp->name, "wangwu");

	return 0;
}
void free_teacher2(struct teacher* &tp)
{
	if (tp != NULL)
	{
		free(tp);
		tp = NULL;
	}
}
int main()
{
	struct teacher* t = NULL;
	get_mem1(&t);
	cout << "id = " << t->id << ",name = " << t->name << endl;
	free_teacher1(&t);

	get_mem2(t);
	cout << "id = " << t->id << ",name = " << t->name << endl;
	free_teacher2(t);
	return 0;
}