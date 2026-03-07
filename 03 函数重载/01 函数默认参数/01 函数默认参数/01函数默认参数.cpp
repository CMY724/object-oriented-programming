#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//在C++中，函数的形参列表中的形参是可以有默认值的。

//语法：` 返回值类型  函数名 （参数 = 默认值）{}`

int func(int a, int b = 10, int c = 10) {
	return a + b + c;
}

//1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
//2. 如果函数声明有默认值，函数实现的时候就不能有默认参数
int func2(int a = 10, int b = 10);
int func2(int a, int b) {
	return a + b;
}

int main() {

	cout << "ret = " << func(20, 20) << endl;
	cout << "ret = " << func(100) << endl;

	system("pause");

	return 0;
}

//注意 如果形参有默认值 那么在调用函数的时候，如果实参没有传递，那么就会使用默认值，如果实参传递了，那么就会使用实参的值。