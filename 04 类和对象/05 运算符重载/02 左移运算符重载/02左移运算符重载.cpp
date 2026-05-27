#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//左移运算符重载
//配合友元可以输出自定义数据类型

class Person
{
friend ostream & operator<<(ostream& cout, Person& p);//友元函数 让全局函数访问私有成员

public:
	Person(int a,int b)
	{
		m_A = a;
		m_B = b;
	}
private:

	//1.利用成员函数重载左移运算符 operator<<
	//p.operator<<(cout); 简化版本为 p<<cout
	//void operator<<(Person &p)

	//不会利用成员函数重载<<运算符 因为无法实现cout在左侧


	int m_A;
	int m_B;
};


//只能利用全局函数重载<<运算符  ostream 输出流对象 全局只能有一个不能创建新的 必须引用
 ostream & operator<<(ostream& cout, Person& p)//本质为 operator<<(cout,p) 简化为cout << p
{
	cout << "m_A = " << p.m_A <<" " << "m_B = " << p.m_B ;
	return cout;//返回的是cout对象 必须引用是因为全局只能有一个cout对象 不能创建新的cout对象 只能返回引用
}
 //ostream & operator<<(ostream& out, Person& p) 写成out都可以 相当于取别名 但是习惯上使用cout来表示输出流对象

 
 void test01()
{
	Person p(10,10);
	

	cout << p << endl << "hello world" << endl;//链式编程思想 cout<<p要返回cout对象 这样才能继续使用cout输出其他内容 或者追加endl

}


int main()
{
	test01();

	return 0;
}
