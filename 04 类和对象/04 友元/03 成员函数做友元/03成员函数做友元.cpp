#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>


class Building;
class GoodGay
{
public:

	GoodGay();

	void visit();//让visit可以访问Building中私有成员
	void visit2();//让visit2不能访问Building中私有成员

	Building* building;

};

class Building
{
	//friend void visit(); 这是全局函数做友元的写法
	friend void GoodGay::visit();//这是成员函数做友元的写法 加作用域告诉编译器 
	                             //这是GoodGay类下的visit成员函数作为本类的好朋友 可以访问私有成员

public:
	Building();

public:

	string m_SittingRoom;//客厅

private:

	string m_BedRoom;//卧室

	
};

//类外实现成员函数
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit()
{
	cout << "visit函数正在访问: " << building->m_SittingRoom << endl;

	cout << "visit函数正在访问: " << building->m_BedRoom << endl;
}
void GoodGay::visit2()
{
	cout << "visit函数正在访问: " << building->m_SittingRoom << endl;

	//cout << "visit函数正在访问: " << building->m_BedRoom << endl;
	//只有visit函数是做友元 visit2还是无法访问私有的BedRoom
}

void test01()
{
	GoodGay gg;
	gg.visit();
	gg.visit2();
}

int main()
{
	test01();
	return 0;
}
