#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//加号运算符重载

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
	//1.成员函数重载+ operator+
	Person operator+(Person& p)
	{
		Person temp;
	}

	int m_A;
	int m_B;
};

void test01()
{
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;
	Person p2;
	p2.m_A = 10;
	p2.m_B = 10;


	Person p3 = p1 + p2;
}



//2.全局函数重载+

int main()
{


	return 0;
}