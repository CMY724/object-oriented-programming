#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//加号运算符重载
//实现两个自定义数据类型的对象进行加法运算



//对于内置数据类型 编译器知道如何进行运算 

//int a=10; int b=10; int c=a+b; 编译器会做

//class Person
//{
//public:
//	int m_A;
//	int m_B;
//};
//
//Person p1;
//p1.m_A = 10;
//p1.m_B = 10;
//
//Person p2;
//p2.m_A = 10;
//p2.m_B = 10;

//Person p3 = p1 + p2;  编译器不会做了

class Person
{
public:
	//1.成员函数重载+    operator+
	/*Person operator+(Person& p)
	{
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}*/

	int m_A;
	int m_B;
};


//2.全局函数重载+
Person operator+(Person& p1, Person& p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}

//函数重载的版本
Person operator+(Person& p1, int num)
{
	Person temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}


void test01()
{
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;
	Person p2;
	p2.m_A = 10;
	p2.m_B = 10;

	//成员函数重载的本质调用
	//Person p3 = p1.operator+(p2);
	//全局函数重载的本质调用
	//Person p3 = operator+(p1, p2);
	Person p3 = p1 + p2;
	//运算符重载 也可以发生函数重载

	Person p4 = p1 + 100;//Person+int 正常加不了 写函数可以


	cout << "p3.m_A = " << p3.m_A << endl;
	cout << "p3.m_B = " << p3.m_B << endl;
	cout << "p4.m_A = " << p4.m_A << endl;
	cout << "p4.m_B = " << p4.m_B << endl;
}





int main()
{
	test01();

	return 0;
}
//总结
//对于内置的数据类型表达式 运算符不可改变
//不要滥用运算符重载 只有当运算符重载符合人们的习惯时 才使用