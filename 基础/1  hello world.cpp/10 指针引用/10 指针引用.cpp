#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
struct teacher
{
	int id;
	char name[20];
};
//二级指针
int get_mem1(struct teacher **tpp)//结构体指针访问->成员，结构体变量访问.成员 
{
	//tpp指向t的指针，*tpp指针，指向的是t本体，**tpp t本体
	//直接*tpp = (struct teacher*)malloc(sizeof(struct teacher));
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
//同级指针引用
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