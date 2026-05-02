#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//深拷贝与浅拷贝

class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}

	Person(int age, int height)
	{
		m_Age = age;
		m_Height = new int(height);//数据开辟在堆区
		cout << "Person的有参构造函数调用" << endl;
	}

	//自己实现拷贝构造函数，解决浅拷贝的问题
	Person(const Person& p)
	{
		cout << "Person 拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height; 编译器默认实现就是这行代码
		//深拷贝操作：自己开辟内存空间，进行数据的复制

		m_Height = new int(*p.m_Height);


	}

	~Person()
	{
		//析构函数作用，将堆区开辟的数据进行释放操作
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "Person的析构函数调用" << endl;
	}

	int m_Age;//年龄
	int* m_Height;//身高指针

};

void test01()
{
	Person p1(18, 160);

	cout << "p1的年龄为：" << p1.m_Age << "身高为： " << *p1.m_Height << endl;

	Person p2(p1);//利用了编译器默认提供的拷贝构造函数，进行浅拷贝

	cout << "p2的年龄为：" << p2.m_Age << "身高为： " << *p2.m_Height << endl;
	//先进后出
	//p2后被创建(后进)，会先析构p2
	//p2指向的堆区内存先被释放了(浅拷贝 p2指向的内存地址和p1一样)
	//p1再释放同一块内存 是非法操作
	//浅拷贝带来的问题:堆区内存重复释放
	//要利用深拷贝解决
}

int main()
{
	test01();

	return 0;
}


//总结
//浅拷贝会把对象里的普通成员变量直接复制一份
//但如果对象里有指针成员，浅拷贝只会复制这个指针的地址
//也就是说，两个对象的指针指向同一块内存
//深拷贝不是简单复制指针地址，而是重新申请一块新的内存，然后把原来的内容复制过去

//如果属性有在堆区开辟的，必须自己提供拷贝构造函数，防止浅拷贝带来的问题