#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//重载递增运算符

//一个自定义的整型
class MyInteger
{
	friend ostream& operator<<(ostream& cout,const MyInteger& myint);//全局函数做友元，重载左移运算符
public:
	MyInteger()
	{
		m_Num = 0;
	}

	//重载前置++运算符
	MyInteger& operator++()//返回引用是为了支持连续递增 对同一个数据递增 若返回值是一个对象 则会调用拷贝构造函数 只是值拷贝 并不是一直对myint进行递增
	{
		//先进行++运算
		m_Num++;

		//再将自身返回
		return * this;
	}

	//重载后置++运算符
	MyInteger operator++(int)//返回值不可以作为重载条件 加个参数区分 int代表占位参数 只是为了区分前置和后置 这个参数没有实际意义
	{
		//后置递增
		//先 返回结果 不能return 即先记录当时结果
		MyInteger temp = *this;
		//后 递增
		m_Num++;
		//最后将记录的结果返回
		return temp;
	}//后置返回引用的话是局部对象 非法操作

private:

	int m_Num;
};

//总结:前置递增返回引用  后置递增返回值

//重载左移运算符
ostream& operator<<(ostream& cout, const MyInteger& myint)//只读不改都加const 加了const能够接收临时对象myint++
{
	cout << myint.m_Num;
	return cout;
}

void test01()
{
	MyInteger myint;

	cout << ++(++myint) << endl;
	cout << myint << endl;

}

void test02()
{
	MyInteger myint;

	cout << myint++ << endl;
	cout << myint << endl;
}


int main()
{
	test01();
	test02();
	return 0;
}