#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <iostream>
using namespace std;
int g_a = 10;//全局变量
int main()
{
	cout << g_a << endl;

	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
//namespace关键字，自定义一个命名空间，大括号没有";"
namespace spaceA {
	int g_a = 10;
}
int main()
{
	//方式一
	cout << spaceA::g_a << endl;
}
#endif

#if 0
#include <iostream>
using namespace std;
//命名空间必须放在全局外面
namespace spaceA {
	int g_a = 10;
}

int main()
{
	//方式二，局部声明
	using spaceA::g_a;

	cout << g_a << endl;
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
namespace spaceA {
	int g_a = 10;
}
int main()
{
	//方式三，局部引入
	using namespace spaceA;
	cout << g_a << endl;
	return 0;
}
#endif

#if 0
//命名空间的嵌套
#include <iostream>
using namespace std;
namespace spaceB {
	int a = 10;
	namespace spaceC {

		struct teacher
		{
			int id;
			char name[20];
		};
	}
	namespace spaceD {

		struct teacher
		{
			int id;
			char name[20];
		};
	}
}
int main()
{
	using namespace spaceB;
	cout << a << endl;
	//对于嵌套命名空间的使用，不能声明一半，需声明到底，否则会发生歧义，报错
	//注意：
	//1、引用命名空间不能使用spaceB::struct teacher;
	//2、引用命名空间不能使用using spaceB::struct teacher;

	//方法一
	spaceB::spaceC::teacher t1;
	//spaceB::teacher t1;//不可取

	//方法二
	using spaceB::spaceC::teacher;
	struct teacher t2;//可以直接teacher t2;
	//using spaceB::teacher;//不可取
	
	//方法三
	using namespace spaceB::spaceC;
	struct teacher t3;//可以直接teacher t3;
	//using namespace spaceB;//不可取
	//struct teacher t4;

	return 0;
}
#endif

#if 0
//命名空间的嵌套
#include <iostream>
using namespace std;
namespace spaceB {
	int a = 10;
	namespace spaceC {

		struct teacher
		{
			int id;
			char name[20];
		};
	}
	namespace spaceD {

		struct teacher
		{
			int id;
			char name[20];
		};
	}
	using namespace spaceC;
}
int main()
{
	//方法三
	using namespace spaceB;
	struct teacher t3;//可以直接teacher t3;

	return 0;
}
#endif