#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//类模版中成员函数类外实现
template<class T1, class T2>
class Person
{
public:

	Person(T1 name, T2 age);
	//{
	//	this->m_Name = name;
	//	this->m_Age = age;
	//}

	void showPerson();
	//{
	//	cout << "姓名: " << this->m_Name << "年龄: " << this->m_Age << endl;
	//}

	T1 m_Name;
	T2 m_Age;

};

//构造函数的类外实现 声明模版 作用域 让编译器知道T1 T2到底是什么
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	
	this->m_Name = name;
	this->m_Age = age;

}

//成员函数的类外实现
template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "姓名: " << this->m_Name << "年龄: " << this->m_Age << endl;
}

void test01()
{
	Person<string, int>p("Tom", 20);
	p.showPerson();
}


int main()
{
	test01();

	return 0;
}
