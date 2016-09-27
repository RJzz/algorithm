#include "recursion.h"
#include "divide.h"
using namespace std;
int main() {
	int a[] = { 1, 2, 3, 4 };
	perm(a, 0, 4);
	cout << endl;
	int b[] = { 3,-2,1,2,-3 };//暴力求解59ms
	int c[] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };//暴力求解大概500ms
	int low = 0, high = 0;

	//暴力求解
	int* x = maxArray(c, 15, low, high);
	for (int i = 0; i <= high - low; ++i) {
		cout << *(x + i) << "\t";
	}

	//最小子数组分治求解
	int* fuck = maxSubArray(c, 0, 15);
	for (int i = 0; i <= 2; ++i) {
		cout << *(fuck + i) << "\t";
	}

	//二分搜索
	int result = binarySearch(c, -3, 0, 15);
	cout << "二分搜索的结果是" << result;
	system("PAUSE");
	return 0;
}
