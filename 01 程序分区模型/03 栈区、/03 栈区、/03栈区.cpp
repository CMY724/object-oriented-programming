#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int* func()
{
	int a = 10;
	return &a;
}

int main()
{
	//存放形参，局部变量
	//注意：不要返回局部变量的地址
    //栈区的数据在函数执行完后自动释放
	

	

		int* p = func();

		cout << *p << endl;
		cout << *p << endl;
		cout << *p << endl;
		cout << *p << endl;
		cout << *p << endl;
		cout << *p << endl;

		system("pause");

		return 0;
	}