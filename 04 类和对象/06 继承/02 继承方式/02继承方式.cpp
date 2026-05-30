#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//继承语法
//class 子类 : 继承方式 父类

//继承方式

//公共继承
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;

};

class Son1 :public Base1
{
public:

	void func()
	{
		m_A = 10;//父类中的公共权限成员 到子类中依然是公共权限
		m_B = 10;//父类中的保护权限成员 到子类中依然是保护权限
		//m_C = 10;//父类中的私有权限成员 到子类中也不可访问
		
	}

};

void test01()
{
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100; 到Son1中 m_B是保护权限 外界中不可访问

}


//保护继承
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;

};

class Son2 :protected Base2
{
public:
	void func()
	{
		m_A = 100;//父类中公共成员 到子类中变为保护权限
		m_B = 100;//父类中保护成员 到子类中也是保护权限
		//m_C = 100; 父类中私有成员 子类访问不到
	}
};

void test02()
{
	Son2 s2;
	//s2.m_A = 1000;//在Son2 子类中m_A变为了保护权限 外界中不可访问
	//s2.m_B = 1000;//在Son2 子类中m_B是保护权限 外界中不可访问
}

//私有继承
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;

};

class Son3 :private Base3
{
	void func()
	{
		m_A = 100;//父类中公共成员 到子类中变为私有权限
		m_B = 100;//父类中保护成员 到子类中变为私有权限
		//m_C = 100;//父类中私有成员 子类访问不到

	}
};

class GrandSon3 :public Son3
{
public:
	void func()
		{
			//m_A = 1000; 验证在Son3中m_A是私有权限 在GrandSon3中访问不到
		}
};

void test03()
{
	Son3 son3;
	//son3.m_A = 1000; 到Son3中  变为  私有成员 类外访问不到
	//son3.m_B = 1000;到Son3中  变为  私有成员 类外访问不到

}



int main()
{

	return 0;
}
