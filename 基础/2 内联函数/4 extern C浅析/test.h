#pragma once
//#include <stdio.h> 
//void show();
//由于c++编译器会将函数名进行二次修饰，如_Z4showv，导致在c文件中找不到该函数名，因此会链接失败

#ifdef __cplusplus
extern "C"
{
#endif

	//各种需要的函数声明
	#include <stdio.h>
		void show();

#ifdef __cplusplus 
}
#endif