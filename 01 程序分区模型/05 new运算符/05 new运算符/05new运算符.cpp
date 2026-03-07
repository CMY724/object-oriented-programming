#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


	//new的基本语法：new+数据类型
	//new返回的是该数据类型的指针
	//int * p=new int (10);
	//double* p = new double(xxx);

//delete p;即可释放堆区数据

	int* func()
	{
		int* a = new int(10);
		return a;
	}

	int main() {

		int* p = func();

		cout << *p << endl;
		cout << *p << endl;

		//利用delete释放堆区数据
		delete p;

		/*cout << *p << endl;*/ //报错，释放的空间不可访问

		system("pause");

		return 0;
	}


	//例2：在堆区用new开辟数组
	int main() {

		int* arr = new int[10];

		for (int i = 0; i < 10; i++)
		{
			arr[i] = i + 100;
		}

		for (int i = 0; i < 10; i++)
		{
			cout << arr[i] << endl;
		}
		//释放数组 delete 后加 [] 表示释放的是数组
		delete[] arr;

		system("pause");

		return 0;
	}

	