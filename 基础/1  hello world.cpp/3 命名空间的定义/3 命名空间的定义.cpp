#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <iostream>
using namespace std;
int g_a = 10;//ȫ�ֱ���
int main()
{
	cout << g_a << endl;

	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
//namespace�ؼ��֣��Զ���һ�������ռ䣬������û��";"
namespace spaceA {
	int g_a = 10;
}
int main()
{
	//��ʽһ
	cout << spaceA::g_a << endl;
}
#endif

#if 0
#include <iostream>
using namespace std;
//�����ռ�������ȫ������
namespace spaceA {
	int g_a = 10;
}

int main()
{
	//��ʽ�����ֲ�����
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
	//��ʽ�����ֲ�����
	using namespace spaceA;
	cout << g_a << endl;
	return 0;
}
#endif

#if 0
//�����ռ��Ƕ��
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
	//����Ƕ�������ռ��ʹ�ã���������һ�룬���������ף�����ᷢ�����壬����
	//ע�⣺
	//1�����������ռ䲻��ʹ��spaceB::struct teacher;
	//2�����������ռ䲻��ʹ��using spaceB::struct teacher;

	//����һ
	spaceB::spaceC::teacher t1;
	//spaceB::teacher t1;//����ȡ

	//������
	using spaceB::spaceC::teacher;
	struct teacher t2;//����ֱ��teacher t2;
	//using spaceB::teacher;//����ȡ
	
	//������
	using namespace spaceB::spaceC;
	struct teacher t3;//����ֱ��teacher t3;
	//using namespace spaceB;//����ȡ
	//struct teacher t4;

	return 0;
}
#endif

#if 0
//�����ռ��Ƕ��
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
	//������
	using namespace spaceB;
	struct teacher t3;//����ֱ��teacher t3;

	return 0;
}
#endif