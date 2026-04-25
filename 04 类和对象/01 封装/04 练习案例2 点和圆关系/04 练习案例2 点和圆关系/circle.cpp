#define _CRT_SECURE_NO_WARNINGS
#include "Circle.h"
//Circle:: 作用域解析符 说明这个函数是Circle类的成员函数
//圆类


//设置半径
void Circle::setR(int r)
{
	m_R = r;
}
//获取半径
int Circle::getR()
{
	return m_R;
}
//设置圆心
void Circle::setCenter(Point center)
{
	m_Center = center;
}
//获取圆心
Point Circle::getCenter()
{
	return m_Center;
}//在类中 可以让另外一个类作为本类成员

