#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//继承中的同名静态成员处理方式

class Base
{

public:

	static int m_A;

	static void func()
	{
		cout << "Base-static void func()" << endl;
	}
};

class Son:public Base
{
public:

	static int m_A;
	static void func()
	{
		cout << "Son-static void func()" << endl;
	}
};

int Base::m_A = 100;

int Son::m_A = 200;

//同名静态成员属性
void test01()
{
	//1.通过对象访问
	cout << "通过对象访问" << endl;
	Son s;
	cout << "Son的m_A = " << s.m_A << endl;
	cout << "Base的m_A = " << s.Base::m_A << endl;

	//2.通过类名访问
	cout << "通过类名访问" << endl;
	cout << "Son的m_A = " << Son::m_A << endl;
	//第一个::代表通过类名方式访问
	//第二个::代表访问父类作用域下的成员
	cout << "Base的m_A = " << Son::Base::m_A << endl;


}
//同名静态成员函数
void test02()
{
	//1.通过对象访问
	cout << "通过对象访问" << endl;
	Son s;
	s.func();
	s.Base::func();

	//2.通过类名访问
	cout << "通过类名访问" << endl;
	Son::func();
	Son::Base::func();

	//子类出现和父类同名静态函数 也会隐藏父类中所有同名函数  不管参数列表是否一样
	//如果想访问父类中被隐藏的同名函数 需要加作用域
}



int main()
{
	test02();
	//test01();
	return 0;
}
