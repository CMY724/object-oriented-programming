#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//函数调用符()也可以重载
//由于重载之后使用方式非常像函数调用 称之仿函数 没有固定写法 非常灵活


//打印输出类
class MyPrint
{
public:

	//重载函数调用运算符
	void operator()(string test)
	{
		cout << test << endl;
	}


};
void MyPrint02(string test)
{
	cout << test << endl;
}

void test01()
{
	MyPrint myPrint;

	myPrint("hello world");//由于使用起来非常像函数调用 因此称为仿函数
	MyPrint02("hello world");
}

//仿函数非常灵活 没有固定写法
//加法类

class MyAdd
{
public:

	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

void test02()
{
	MyAdd myadd;
	int res = myadd(100, 100);
	cout << "res = " << res << endl;

	//匿名函数对象
	cout << MyAdd()(100, 100) << endl;
	//MyAdd()创建了一个匿名对象 当前行执行完直接被释放 
	//类+() 是匿名对象
}

int main()
{
	/*test01();*/
	test02();
	return 0;
}
