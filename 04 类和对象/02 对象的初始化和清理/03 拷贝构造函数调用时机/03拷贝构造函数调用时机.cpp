#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


//拷贝构造函数的调用时机

//1.使用一个已经创建完毕的对象来初始化一个新对象

//2.值传递的方式给函数参数传值

//3.值方式返回局部对象

class Person
{
public:
	Person()
	{
		cout << "Person默认构造函数调用" << endl;
	}

	Person(int age)
	{
		cout << "Person有参构造函数调用" << endl;
		m_Age = age;
	}

	Person(const Person& p)
	{
		cout << "Person拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
	}

	~Person()
	{
		cout << "Person析构函数调用" << endl;
	}

	int m_Age;
};

//1.使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
	Person p1(20);
	Person p2(p1);

	cout << "p2的年龄为：" << p2.m_Age << endl;
}

//2.值传递的方式给函数参数传值

void doWork(Person q)
{

}

void test02()
{
	Person p;//默认构造函数调用
	doWork(p);
	//不是把p对象传递给doWork函数，而是把p对象进行拷贝构造，产生了一个新的对象，这个新的对象作为实参传递给doWork函数
}

//3.值方式返回局部对象

Person doWork2()
{
	Person p1;
	cout << (int*)&p1 << endl;//输出p1对象的地址
	return p1;
}//在doWork2函数中，局部对象p1在函数结束时被销毁
//值返回 返回出去的是它的拷贝结果
//但现代 C++ 编译器通常会通过返回值优化，直接构造目标对象，从而不一定真的调用拷贝构造函数

void test03()
{
	Person p = doWork2();
	cout << (int*)&p << endl;
}
//值返回局部对象时，逻辑上是“用局部对象生成返回值”
// 现代编译器常常会优化成“直接在接收对象的位置上构造这个局部对象”，所以 stu 和 s 的地址可能完全相同
int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}
