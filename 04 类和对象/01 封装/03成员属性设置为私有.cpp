#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
// 成员属性设置为私有
//优点1:将所有成员属性设置为私有，可以自己控制读写权限
//优点2:对于写权限 我们可以检测数据的有效性

//优点1:自己控制读写权限
class Person
{
public:
	//设置姓名
	void setName(string name)
	{
		m_Name = name;
	}

	//获取姓名
	string getName()
	{
		return m_Name;
	}

	//获取年龄
	int getAge()
	{
		return m_Age;
	}

	//设置偶像
	void setIdol(string idol)
	{
		m_Idol = idol;
	}
private:
	string m_Name;//姓名 设置为可读可写 有设置有获取

	int m_Age = 20;//年龄 设置为只读 只有获取没有设置

	string m_Idol;//偶像 设置为只写 只有设置没有获取
};

//优点2:可以检测数据有效性
class Person2
{
public:
	//设置姓名
	void setName(string name)
	{
		m_Name = name;
	}

	//获取姓名
	string getName()
	{
		return m_Name;
	}

	//获取年龄
	int getAge()
	{
		return m_Age;
	}

	//设置年龄 要在0-150之间
	void setAge(int age)
	{
		if (age < 0 || age>150)
		{
			cout << "年龄" << age << "输入有误!赋值失败!" << endl;
			return;
		}
		m_Age = age;
	}
	//设置偶像
	void setIdol(string idol)
	{
		m_Idol = idol;
	}
private:
	string m_Name;//姓名 设置为可读可写 有设置有获取

	int m_Age = 20;//年龄 可读 也可以写 但是我们在设置年龄的时候检测数据的有效性 年龄必须在0-150之间

	string m_Idol;//偶像 设置为只写 只有设置没有获取
};


int main()
{
	Person p;
	//姓名设置
	p.setName("chumingyu");
	cout << "姓名: " << p.getName() << endl;

	//年龄设置
	//p.setAge(30);错误，年龄没有设置函数
	//p.m_Age = 30;错误，年龄是私有属性

	//年龄获取
	cout << "年龄: " << p.getAge() << endl;
	 
	//偶像设置
	p.setIdol("htx");
	//cout << "偶像: " << p.setIdol() << endl; 只写状态 外界访问不到 没有setIdol函数


	Person2 p2;
	p2.setAge(200);
	cout << "年龄: " << p2.getAge() << endl;
	system("pause");

}
