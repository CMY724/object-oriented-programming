#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//底层实现:虚函数表和虚函数指针

//含有虚函数的类，编译器通常会为它创建:
//1.虚函数表 vftable：存放虚函数的地址
//2.虚函数指针 vfptr：每个对象中保存一个指针，指向所属类的虚函数表

//先继承 父类的虚函数也被继承
//当子类重写父类的虚函数后
//子类中的虚函数表内部会替换成子类的虚函数地址 覆盖了父类的


//通过虚函数表，在运行时根据对象的实际类型进行动态绑定

class Animal
{
public:

	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}

};

class Cat :public Animal
{
public:
	virtual void speak()
	{
		cout << "小猫在说话" << endl;
	}
};

class Dog :public Animal
{
public:
	virtual void speak()
	{
		cout << "小狗在说话" << endl;
	}

};


void doSpeak(Animal& animal) //Animal & animal = cat;
{
	animal.speak();
}

void test01()
{
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

void test02()
{
	cout << "sizeof Animal = " << sizeof(Animal) << endl;
}



int main()
{
	test02();

	return 0;
}