#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;


//类模版与函数模版的区别
template<class NameType,class AgeType = int>
class Person
{
public:

	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
	}


	NameType m_Name;
	AgeType m_Age;
};

//1.类模版没有自动类型推导的使用方式

void test01()
{
	//错误 无法自动类型推导
	//Person p("孙悟空", 1000);

	Person<string,int> p("孙悟空", 1000);//正确 只能用显示指定类型
	
	p.showPerson();
}

//2.类模版在模版参数列表中可以有默认参数

void test02()
{
	Person<string>p("猪八戒", 999);//模版中有默认参数class AgeType = int 这里不需要再写int
	p.showPerson();
}

int main()
{
	//test01();
	test02();
	return 0;
}
