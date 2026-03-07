#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//引用必须初始化
//引用一旦被初始化后，就不能再指向其他对象了

int main() {

	int a = 10;
	int b = 20;
	//int &c; //错误，引用必须初始化
	int& c = a; //一旦初始化后，就不可以更改
	c = b; //这是赋值操作，不是更改引用

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	system("pause");
	
	return 0;
}