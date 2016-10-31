#include "recursion.h"
#include "divide.h"
#include "dynamicprogramming.h"
using namespace std;
int main() {
	//全排列问题
	//int a[] = { 1, 2, 3, 4 };
	//perm(a, 0, 4);
	cout << endl;

	int b[] = { 3,-2,1,2,-3 };//暴力求解59ms
	int c[] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };//暴力求解大概500ms
	int low = 0, high = 0;
	
	//线性时间求解
	int linearLow = 0;
	int linearHigh = 0;
	int linearAnswer = maxLinearArray(c, linearLow, linearHigh, 15);

	//暴力求解
	int* x = maxArray(c, 15, low, high);
	//for (int i = 0; i <= high - low; ++i) {
	//	cout << *(x + i) << "\t";
	//}

	//最小子数组分治求解
	int* fuck = maxSubArray(c, 0, 15);
	//for (int i = 0; i <= 2; ++i) {
	//	cout << *(fuck + i) << "\t";
	//}

	//二分搜索
	/*int result = binarySearch(c, -3, 0, 15);
	cout << "二分搜索的结果是" << result;
	system("PAUSE");*/

	//矩阵链乘法问题
	int **m;
	int **s;

	//初始化结果矩阵
	m = new int*[6];
	s = new int*[6];
	for (int i = 0; i < 6; ++i) {
		//两种表示方式都可以
		m[i] = new int[6];
		*(s + i) = new int[6];
	}
	matrixchain(m, s, 6);
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			cout << s[i][j] << "\t";
		}
		cout << endl;
	}
	//int a = 1;
	//int *key = &a;
	//std::cout << "a:" << &a << endl;
 //	std::cout << key << "\t" << &key << "\t" << *key;

	traceBack(s, 0, 5);
	//printBestAnswer(s, 6);
	printAnswer(s, 6);
	system("PAUSE");

	return 0;
}

