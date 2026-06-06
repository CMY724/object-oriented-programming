#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//继承中同名成员处理方式

class Base
{
public:
	
	Base()
	{
		m_A = 100;
	}

	void func()
	{
		cout << "Base中的func函数调用" << endl;
	}

	void func(int a)//重载
	{
		cout << "Base中的func(int a)函数调用" << endl;
	}
	
	int m_A;

};

class Son :public Base
{
public:

	Son()
	{
		m_A = 200;
	}

	void func()
	{
		cout << "Son中的func函数调用" << endl;
	}
	
	
	int m_A;//子类中定义了一个和父类同名的成员变量

};

//同名成员属性处理
void test01()
{
	Son s;
	cout << "Son的m_A = " << s.m_A << endl;
	cout << "Base的m_A = " << s.Base::m_A << endl;//通过 作用域运算符 访问父类中同名成员
}
//如果通过子类对象访问同名成员，默认访问的是子类中的成员
//如果要访问父类中的同名成员，需要加上父类的作用域。



//同名成员函数处理
void test02()
{
	Son s;
	s.func();//默认访问子类中的同名函数
	
	s.Base::func();//通过 作用域运算符 访问父类中同名函数

	//如果子类中出现和父类同名的成员函数 子类的同名成员函数会隐藏父类中所有同名成员函数(不管参数列表 重载也一样被隐藏)
	//如果要访问父类中被隐藏的同名成员函数   需要加上父类的作用域。
	s.Base::func(100);
}

int main()
{
	test02();
	//test01();
	return 0;
}