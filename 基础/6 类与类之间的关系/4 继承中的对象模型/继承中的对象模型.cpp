#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//注意：父类的私有属性，是被继承的，只是子类访问不到，由编译器给隐藏了
//可以利用开发人员工具查看对象模型
//1、工具的路径：Develper Command Prompt for VS2019 点击打开
//2、跳转盘符，找到代码文件路径下:cd ./VS2019/C++code/C++code/基础/1 类与类之间的关系/4 继承中的对象模型
//或者点击VS中右键点击文件名，“打开所在的文件夹”，复制路径框，右键粘贴
//3、输入命令：dir       查看该路径下的文件或文件夹
//输入命令：cl 清空屏幕
//4、输入名：“cl(字母l) /d1(数字1) reportSingleClassLayout类名 文件名.cpp”
//可以看到指定类的成员布局情况：即父类的私有成员也继承下来了。

class Base
{
public:
	int m_A;
private:
	int m_B;
protected:
	int m_C;
};

class Son :public Base
{
public:
	int m_D;
};

int main()
{
	cout << "size of Son =" << sizeof(Son) << endl;
	//注意：空类的大小为1字节，空结构体大小为1字节

	return 0;
}