#define _CRT_SECURE_NO_WARNINGS 1
extern const int b = 100;//默认内部链接属性
//只能在本文件中使用
//如果需要拿到这个变量，加上extern关键字，提高作用域。
//注意C语言下隐式的加了这个关键字