#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

//文件类型分为两种
//1.文本文件 文件以文本的ASCII码形式存储在计算机中
//2.二进制文件 文件以文本的二进制形式存储在计算机中

//操作文件的三大类
//1.ofstream 写操作
//2.ifstream 读操作
//3.fstream 读写操作


//文本文件中的写文件

void test01()
{
	//1.包含头文件 fstream

	//2.创建流对象 类名是ofstream

	ofstream ofs;

	//3.指定打开方式 (文件路径 可以写文件名,打开方式）
	ofs.open("test.txt", ios::out);
	//ios::in 为读文件而打开文件
	//ios::out 为写文件而打开文件
	//ios::binary 二进制方式

	//4.写内容
	ofs << "姓名: 张三" << endl;
	ofs << "姓别:男" << endl;
	ofs << "年龄: 18" << endl;

	//5.关闭文件
	ofs.close();

}

int main()
{
	test01();


	return 0;
}


//总结:
//文件操作必须包含头文件fstream
//读文件可以用ofstream或fstream类
//打开文件时候需要指定操作文件的路径 以及打开方式
//利用<<可以向文件中写数据
//操作完毕要关闭文件
