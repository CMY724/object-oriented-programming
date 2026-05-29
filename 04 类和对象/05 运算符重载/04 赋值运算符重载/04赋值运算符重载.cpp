#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//C++编译器至少给一个类添加4个函数
//1.默认构造函数(无参 函数体为空)
//2.默认析构函数(无参 函数体为空)
//3.默认拷贝构造函数 对属性进行值拷贝

//4.赋值运算符operator= 对属性进行值拷贝

//赋值运算符重载

class Person
{
public:

	Person(int age)
	{
		m_Age = new int(age);//创建在堆区
	}

	~Person()//释放堆区数据 在对=进行重载之前 p2=p1为浅拷贝 析构时对同一块内存进行了两次释放 是违法的 因此要重载= 实现深拷贝
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}

	//重载 赋值运算符 不确定返回值时可以先写void

	Person& operator=(Person& p)
	{
		//编译器提供浅拷贝
		//m_Age=p.m_Age;

		//应该先判断是否有属性在堆区 若有 先释放干净 然后再深拷贝
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}

		m_Age = new int(*p.m_Age);//深拷贝

		return *this;//返回对象本体

	}

	int* m_Age;
};


void test01()
{
	Person p1(18);

	Person p2(20);

	Person p3(30);

	p3 = p2 = p1;//赋值操作 想做连等需要返回对象本身

	cout << "p1的年龄为: " << *p1.m_Age << endl;
	cout << "p2的年龄为: " << *p2.m_Age << endl;
	cout << "p3的年龄为: " << *p3.m_Age << endl;
}

void test02()
{

}

int main()
{
	test01();
	return 0;
}
