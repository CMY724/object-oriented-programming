#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//总结:
//常函数 在成员函数后加const 让this指向的值不可修改
//想修改要在属性前加mutable 让这个属性在常函数中也可修改
//常对象 在对象前加const 让对象的值不可修改
//mutable类型的属性 在常对象中也可修改
//常对象不可调用普通成员函数 只能调用常函数


//常函数

class Person
{
public:
	//this指针的本质 是指针常量 指针的指向不可以修改
	// const Person * const this;
	//在成员函数后面加const 修饰的是this指向 让指向的值也不可修改

	void showPerson() const//相当于上面的第一个const
	{
		//this->m_A = 100; //每个成员函数都有一个隐藏的参数this，指向调用该成员函数的对象
		//this = NULL; this指针不可修改指向 但其指向的值可以修改
		this->m_B = 100;
	}

	void func()
	{

	}

	int m_A;
	mutable int m_B;//特殊变量 想在常函数中也可修改这个值 加关键字 mutable

};

void test01()
{
	Person p;
	p.showPerson();

}

//常对象

void test02()
{
	const Person p;//在对象前加const 变为常对象
	//p.m_A = 100; 无法修改
	p.m_B = 100;//m_B是mutable类型的变量 在常对象中也可以修改

	//常对象只能调用常函数
	p.showPerson();
	//p.func(); //常对象只能调用常函数 不能调用普通函数 因为普通函数可以修改属性
}

int main()
{

	return 0;
}