#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>

//建筑物类
class Building
{
	//goodGay全局函数是Building类的好朋友，可以访问Building类中的私有成员
	friend void goodGay(Building& building);// friend 关键字  友元函数 写在类的内部 但不是成员函数  可以访问类中的私有成员

public:
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";

	}


public:
	string m_SittingRoom;// 客厅

private:
	string m_BedRoom;// 卧室

};

//全局函数 做友元
void goodGay(Building &building)
{
	cout << "好基友全局函数  正在访问:" << building.m_SittingRoom << endl;
	
	cout << "好基友全局函数  正在访问:" << building.m_BedRoom << endl;
}

void test01()
{
	Building building;
	goodGay(building);
}


int main()
{
	test01();
	return 0;
}