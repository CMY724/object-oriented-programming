#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//实现通用 对数组进行排序的函数
//从大到小
//选择排序
//用 char int 数组 进行测试


//交换函数模版
template <class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


//排序算法
template<class T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;//认定最大值下标

		for (int j = i + 1; j < len; j++)
		{
			//认定的最大值比遍历出的数值要小 说明j下标元素才是真正最大值
			if (arr[max] < arr[j])
			{
				max = j;//更新最大值下标
			}
		}
		if (max != i)
		{
			//交换max和i下标的元素
			mySwap(arr[max], arr[i]);
		}

	}
}

//打印数组模版
template <class T>
void PrintArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


void test01()
{
	//测试char数组
	char charArr[] = "badcfe";  

	int num = sizeof(charArr) / sizeof(char);

	mySort(charArr, num);
	
	PrintArray(charArr, num);
	


}

void test02()
{
	//测试int数组

	int intArr[] = { 7,5,1,3,9,2.4,6,8 };
	
	int num = sizeof(intArr) / sizeof(int);

	mySort(intArr, num);

	PrintArray(intArr, num);
}



int main()
{
	test01();
	test02();

	return 0;
}