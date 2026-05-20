#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//空指针调用成员函数

class Person
{
public:

	void showClassName()
	{
		cout << "this is Person class" << endl;
	}

	void showPersonAge()
	{
		if (this == NULL)
		{
			return;
		}
		
		cout << "age = " << this->m_Age << endl;
		//this指针不写也是默认加上的 但这里this是空指针 没有指向确切的对象 所以会报错
	
	}

	int m_Age;

};

void test01()
{
	Person * p = NULL;

	p->showClassName();

	p->showPersonAge();

}

int main()
{
	test01();

	return 0;
}