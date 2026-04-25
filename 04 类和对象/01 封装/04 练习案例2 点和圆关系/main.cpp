#define _CRT_SECURE_NO_WARNINGS

#include <iostream> 
#include "Circle.h"
#include "Point.h"
using namespace std;
//点和圆关系

//核心内容:
//1.在类中 可以让另外一个类作为本类成员 即在Circle中包含Point
//2.把点类和圆类分开写 让代码更清晰  分文件编写



////点类
//class Point
//{
//public:
//	//设置x坐标
//	void setX(int x)
//	{
//		m_X = x;
//	}
//	//获取x坐标
//	int getX()
//	{
//		return m_X;
//	}
//	//设置y坐标
//	void setY(int y)
//	{
//		m_Y = y;
//	}
//	//获取y坐标
//	int getY()
//	{
//		return m_Y;
//	}
//private:
//	int m_X;
//	int m_Y;
//};

////圆类
//class Circle
//{
//public:
//	//设置半径
//	void setR(int r)
//	{
//		m_R = r;
//	}
//	//获取半径
//	int getR()
//	{
//		return m_R;
//	}
//	//设置圆心
//	void setCenter(Point center)
//	{
//		m_Center = center;
//	}
//	//获取圆心
//	Point getCenter()
//	{
//		return m_Center;
//	}//在类中 可以让另外一个类作为本类成员
//private:
//	int m_R;//半径
//
//	Point m_Center;//圆心 自己定义一个点类
//};


//判断点和圆的关系
void isInCircle(Circle& c, Point& p)
{
	//计算点到圆心的距离的平方
	int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	//计算半径的平方
	int r =c.getR() * c.getR();

	//判断
	if (distance == r)
	{
		cout << "点在圆上" << endl;
	}
	else if (distance > r)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}
int main()
{
	//创建圆对象
	Circle c;
	c.setR(10);

	Point center;
	center.setX(10);
	center.setY(0);
	c.setCenter(center);

	//创建点对象
	Point p;
	p.setX(10);
	p.setY(9);

	//判断
	isInCircle(c, p);

	return 0;
}

