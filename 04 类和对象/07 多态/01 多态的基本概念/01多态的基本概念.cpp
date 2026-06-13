#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//多态


//动物类
class Animal
{
public:

	//虚函数
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}

};

//猫类
class Cat :public Animal
{
public:
	//重写 函数返回值类型 函数名 参数列表 完全相同 子类的virtual可写可不写
	virtual void speak()
	{
		cout << "小猫在说话" << endl;
	}
};

//狗类
class Dog :public Animal
{
public:
	virtual void speak()
	{
		cout << "小狗在说话" << endl;
	}

};

//执行说话的函数

//地址早绑定 在编译阶段就确定了函数地址

//如果想执行让猫说话 这个函数的地址不能提前绑定 需要在运行阶段再进行绑定
//即地址晚绑定
void doSpeak(Animal & animal) //Animal & animal = cat;
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



int main()
{
	test01();

	return 0;
}

//动态多态的满足条件
// 1.有继承关系
// 2.子类要重写父类的虚函数

//动态多态的使用
//父类的指针或者引用 指向子类的对象

//动态多态 函数地址晚绑定 运行阶段才确定函数地址
