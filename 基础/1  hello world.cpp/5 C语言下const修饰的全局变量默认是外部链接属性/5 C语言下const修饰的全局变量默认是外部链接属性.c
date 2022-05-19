#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	extern const int a;
	printf("%d\n", a);
	return 0;
}