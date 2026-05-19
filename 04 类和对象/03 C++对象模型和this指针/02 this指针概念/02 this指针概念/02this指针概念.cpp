#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//this指针
//隐含每一个非静态成员函数内 可以直接使用

class Person
{
public:
	Person(int age)
	{
		//this指针指向的是被调用的成员函数所属的对象
		this->age = age;
	}

	Person& PersonAddAge(Person &p)//引用传参 返回引用 如果不 返回 引用只 返回 值 第一次调用完返回的不是p2本体 而是按照本体拷贝了一份数据(拷贝构造函数) 不再是p2本身了
	{
		this->age += p.age;

		//this是指向p2的指针  而*this指向的是p2这个对象本体
		return *this;
	}
	//若
	//Person 返回值 返回当前对象副本  链式调用后续操作作用在副本上
	//Person p 参数  传入副本  会拷贝，修改不到原对象

	int age;

};

//1.解决名称冲突 当形参与成员变量同名 用this指针来区分
void test01()
{
	Person p1(18);//this指向p1
	cout << "p1的年龄为: " << p1.age << endl;
}
//2.返回对象本身用 *this
void test02()
{
	Person p1(10);
	Person p2(10);
	
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);//链式编程思想
	//只加了一次10岁 想多加几次
	//想实现p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1).... 这样语法不通过
	//想让p2.PersonAddAge(p1)返回成p2


	cout << "p2的年龄为: " << p2.age << endl;
}


int main()
{
	//test01();
	test02();
	return 0;
}