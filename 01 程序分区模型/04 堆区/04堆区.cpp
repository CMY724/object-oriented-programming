#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int* func();

int main()
{
	//堆区数据由程序员手动管理开辟和释放。
	//若程序员不释放, 程序结束时由操作系统回收

	//在堆区用 new 开辟数据
	int* a = func();

	cout << *a << endl;


	system("pause");


	return 0;
}

int* func()
{
	int* p = new int(10);  //指针本质是局部变量，放在栈上，指针保存的数据放在堆区
	return p;
}
