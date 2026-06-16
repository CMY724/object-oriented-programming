#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//普通函数与函数模版的调用规则
//1.如果函数模版和普通函数都可以调用 优先调用普通函数
//2.可以通过 空模版的参数列表 来强制调用函数模版
//3.函数模版也可以发生函数重载
//4.如果函数模版可以产生更好的匹配 优先调用函数模版


void myPrint(int a, int b)
{
	cout << "调用普通函数" << endl;
}

template <class T>
void myPrint(T a, T b)
{
	cout << "调用函数模版" << endl;
}

template <class T>
void myPrint(T a, T b,T c)
{
	cout << "调用重载的函数模版" << endl;
}

void test01()
{
	int a = 10;
	int b = 20;

	//myPrint(a, b);//普通函数和函数模版都能调用 优先调用普通函数


	//通过空模版参数列表 强制调用函数模版
	//myPrint<>(a, b,10);

	//如果函数模版产生更好的匹配 优先调用函数模版
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);//函数模版 不用发生隐式类型转换 更好的匹配

}


int main()
{
	test01();


	return 0;
}
//总结  既然提供了函数模版 就不要提供普通函数 容易出现二义性