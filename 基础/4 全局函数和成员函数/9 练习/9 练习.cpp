#define _CRT_SECURE_NO_WARNINGS 1

//1、this指针的本质是什么？如何在函数中用const修饰this指针
//谁调用，就指向谁对象的常指针。在成员函数后面家const。

//2、友元函数是否有传递性和交换性？举例说明。

//3、实现一个复数类的+=、-=、，前置++、后置++、前置--、后置--、<<、>>等操作符重载

//4、简述操作符重载的规则

//5、课程中自定义数组，实现<<操作符，实现取值操作符[]

//array[i] = 10;
//cout << array << endl;
//cin >> array
//cout << array[i] << endl;
//
//==
//!=
//array1 == array2;
//array1 != array2;