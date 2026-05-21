#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>

//类做友元

class Building;

class GoodGay
{
public:
	GoodGay();

	void visit();//参观函数 访问buliding中的属性

private:
	Building* building;
};

class Building
{
	friend class GoodGay;//friend关键字 GoodGay是本类的好朋友 可以访问本类中私有成员

public:
	Building();

public:

	string m_SettingRoom;//客厅

private:

	string m_BedRoom;// 卧室

};

//类外写成员函数 (构造函数) 要加作用域
Building::Building()
{
	m_SettingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
	//创建建筑物对象
	building = new Building;
}

void GoodGay::visit() //作用域要紧跟函数名
{
	cout << "好基友类正在访问: " << building->m_SettingRoom << endl;

	cout << "好基友类正在访问: " << building->m_BedRoom << endl;
}

void test01()
{
	GoodGay gg;
	gg.visit();
}

int main()
{
	test01();
	return 0;
}
