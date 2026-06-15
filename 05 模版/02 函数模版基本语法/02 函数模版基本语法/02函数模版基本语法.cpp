#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//函数模版

//交换两个整型函数
void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//交换两个浮点型函数
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}



//函数模版
//template<typename T>
//template 声明创建模版
//typename 表明后面的符号是一种数据类型 也可用class
//T 通用的数据类型 

template<typename T>    //声明一个模版 告诉编译器后面代码中紧跟着的T不要报错 T是一个通用的数据类型
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;
	//swapInt(a, b);
	//利用函数模版进行交换
	
	//两种方式
	
	//1.自动类型推导
	// mySwap(a, b);

	 //2.显示指定类型
	mySwap<int>(a, b);



	cout << "a = " << a << endl;
	cout << "b = " << b << endl;


	double c = 1.1;
	double d = 2.2;
	swapDouble(c, d);

	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

}



int main()
{
	test01();

	return 0;
}

//总结
//函数模版利用关键字template
//两种方式使用 自动类型推导 显示指定类型
//目的是为了提高复用性 将类型参数化