#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//静态成员变量
class Person
{
public:
	
	//1.所有对象都共享同一份数据
	//2.在编译阶段分配内存
	//3.在类内声明，在类外初始化!!!!必须这么做
	static int m_A;

	//静态成员变量也是有访问权限的
private:
	static int m_B;
};


int Person::m_A = 100;//m_A是Person作用域下的静态成员变量，必须在类外进行初始化
int Person::m_B = 200;

void test01()
{
	Person p;
	cout << p.m_A << endl;

	Person p2;
	p2.m_A = 200;
	cout << p.m_A << endl;//用p去访问也输出200 体现静态成员变量是所有对象共享同一个
} 

void test02()
{
	//静态成员变量不属于某个对象，所有对象都共享同一份数据
	//因此静态成员变量有两种访问方式

	//1.通过对象进行访问
	Person p;
	cout << p.m_A << endl;
	//2.通过类名进行访问  语法  类名::静态成员变量名(作用域解析符)
	cout << Person::m_A << endl;

	//cout << Person::m_B << endl;   private 类外不可访问私有的静态成员变量
}

int main()
{
	//test01();
	test02();
	return 0;
}
