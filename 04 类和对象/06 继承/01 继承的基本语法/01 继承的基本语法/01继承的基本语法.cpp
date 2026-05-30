#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//普通实现页面

//Java页面

//class Java
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册...(公共头部)" << endl;
//	}
//
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//	}
//
//	void left()
//	{
//		cout << "Java、Python、C++...(公共分类列表)" << endl;
//	}
//
//	void content()
//	{
//		cout << "Java学科视频" << endl;
//	}
//
//};
//
////Python页面
//
//class Python
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册...(公共头部)" << endl;
//	}
//
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//	}
//
//	void left()
//	{
//		cout << "Java、Python、C++...(公共分类列表)" << endl;
//	}
//
//	void content()
//	{
//		cout << "Python学科视频" << endl;
//	}
//
//};
//
////C++页面
//
//class CPP
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册...(公共头部)" << endl;
//	}
//
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//	}
//
//	void left()
//	{
//		cout << "Java、Python、C++...(公共分类列表)" << endl;
//	}
//
//	void content()
//	{
//		cout << "C++学科视频" << endl;
//	}
//
//};
//




//继承实现页面

//公共页面
class BasePage
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...(公共头部)" << endl;
	}
		
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
		
	void left()
	{
		cout << "Java、Python、C++...(公共分类列表)" << endl;
	}
};

//继承的好处: 减少重复代码
//语法: class 子类 : 继承方式 父类
//子类  也称为  派生类
//父类  也称为  基类

//派生类中包含两部分成员
//一类是基类继承的 一类是自己的成员
//从基类继承的表现其共性 自己新增的成员体现个性



//Java页面
class Java :public BasePage
{
public:
	void content()
	{
	   cout << "Java学科视频" << endl;
	}
};
//Python页面
class Python :public BasePage
{
public:
	void content()
	{
		cout << "Python学科视频" << endl;
	}
};

//C++页面
class CPP :public BasePage
{
public:
	void content()
	{
		cout << "C++学科视频" << endl;
	}
};

void test01()
{
	cout << "Java下载视频页面如下: " << endl;
	Java java;
	java.header();
	java.footer();
	java.left();
	java.content();

	cout << "------------------------------" << endl;
	cout << "Python下载视频页面如下: " << endl;
	Python python;
	python.header();
	python.footer();
	python.left();
	python.content();

	cout << "------------------------------" << endl;
	cout << "C++下载视频页面如下: " << endl;
	CPP cpp;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();

}



int main()
{
	test01();


	return 0;
}