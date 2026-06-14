#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//虚析构和纯虚析构

class Animal
{
public:

	Animal()
	{
		cout << "Animal的构造函数调用" << endl;
	}
	//纯虚函数
	virtual void speak() = 0;

	//利用虚析构 解决父类指针在释放子类对象时不干净的问题
	
	/*virtual ~Animal()
	{
		cout << "Animal的析构函数调用" << endl;
	}*/

	//纯虚析构 需要声明也需要有具体实现
	//有了纯虚析构后这个类也属于抽象类 无法实例化对象
	virtual ~Animal() = 0;
};

Animal::~Animal()
{
	cout << "Animal的纯虚析构函数调用" << endl;
}


class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat的构造函数调用" << endl;
		m_Name = new string(name);
	}

	virtual void speak()
	{
		cout << *m_Name << "小猫在说话" << endl;
	}

	~Cat()
	{
		if (m_Name != NULL)
		{
			cout << "Cat的析构函数调用" << endl;
			delete m_Name;
		}
		m_Name = NULL;
	}

	string * m_Name;
};

void test01()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	
	//父类指针在析构时候 不会调用子类的析构函数 
	//导致子类如果有堆区属性 会出现内存泄漏
	delete animal;

}


int main()
{
	test01();

	return 0;
}

//子类属性开辟到堆区 需要在父类析构函数加上virtual 变成虚析构 才能调用子类析构函数

//虚析构 virtual ~ 类名 (){}
//纯虚析构 virtual ~ 类名()=0;
//类名 ::~类名(){}; 纯虚析构需要声明也需要有具体实现


//虚析构或纯虚析构 用来解决通过父类指针释放子类对象 
//如果子类中没有堆区数据 可以不写虚析构或纯虚析构
//拥有纯虚析构函数的类也属于抽象类
