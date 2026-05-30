#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//继承中的对象模型

class Base
{
public:
	int m_A;

protected:
	int m_B;

private:
	int m_C;

};

class Son :public Base
{
public:
	int m_D;

};

void test01()
{
	cout << "size of Son = " << sizeof(Son) << endl;
}

int main()
{



	return 0;
}