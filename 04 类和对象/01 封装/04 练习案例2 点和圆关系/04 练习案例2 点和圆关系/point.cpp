#define _CRT_SECURE_NO_WARNINGS
#include "Point.h"
//Point:: 作用域解析符 说明这个函数是Point类的成员函数

//点类

//设置x坐标
void Point::setX(int x)
{
	m_X = x;
}
//获取x坐标
int Point::getX()
{
	return m_X;
}
//设置y坐标
void Point::setY(int y)
{
	m_Y = y;
}
//获取y坐标
int Point::getY()
{
	return m_Y;
}
