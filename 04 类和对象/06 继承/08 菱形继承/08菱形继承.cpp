#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//菱形继承


//动物类

class Animal
{
public:

	int m_Age;
};


//菱形继承主要问题是子类继承两份相同的数据


//利用虚继承可以解决菱形继承的问题
//在继承之前 加上关键字  virtual 变为虚继承
//Animal类称为  虚基类
//虚继承的作用: 解决菱形继承问题 让最底层的子类 只有一份虚基类的数据


//羊类

class sheep :virtual public Animal
{

};

//驼类

class Tuo :virtual public Animal
{

};

//羊驼类

class SheepTuo :public sheep, public Tuo
{

};

void test01()
{
	SheepTuo st;

	st.sheep::m_Age = 18;
	st.Tuo::m_Age = 28;
	//出现菱形继承时 两个父类拥有相同的数据 需要加作用域区分
	cout << "sheep age = " << st.sheep::m_Age << endl;
	cout << "Tuo age = " << st.Tuo::m_Age << endl;
	cout << "st.m_Age = " << st.m_Age << endl;
	//这份数据 我们知道只要有一份就可以了 菱形继承导致了数据有两份 资源浪费
}

int main()
{
	test01();

	return 0;
}
