#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

//类模版的分文件编写的问题以及解决

//第一种解决方式 直接包含源文件

#include "person.cpp"//类模版成员函数在调用时才创建 "person.h"编译器看不到(产生问题原因)

//因此要"person.cpp" 这样编译器也能看到"person.h"


//第二种解决方式 将.h和.cpp内容写到一起 后缀名改为.hpp
#include "person.hpp"
using namespace std;



//template <class T1, class T2>
//class Person
//{
//public:
//	Person(T1 name, T2 age);
//
//
//	void showPerson();
//
//
//	T1 m_Name;
//	T2 m_Age;
//};
//
//template <class T1,class T2>
//Person<T1, T2>::Person(T1 name, T2 age)
//{
//	this->m_Name = name;
//	this->m_Age = age;
//}
//
//template <class T1, class T2>
//void Person<T1, T2>::showPerson()
//{
//	cout << "姓名: " << this->m_Name << "年龄: " << this->m_Age << endl;
//}

void test01()
{
	Person<string, int>p("Jerry", 18);
	p.showPerson();
}

int main()
{
	test01();

	return 0;
}
