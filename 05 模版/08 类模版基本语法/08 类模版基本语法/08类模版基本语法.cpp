#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//类模版 与函数模版语法相似
template<class NameType,class AgeType>
class Person
{
public:

	Person(NameType name,AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "name: " << this->m_Name << "age: " << this->m_Age << endl;


 	}

	NameType m_Name;
	AgeType m_Age;//两个数据类型不一样 需要写两个class
};

void test01()
{
	Person<string, int>p1("孙悟空", 999);//<> 模版的参数列表

	p1.showPerson();


}

int main()
{
	test01();

	return 0;
}