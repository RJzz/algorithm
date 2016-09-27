#pragma once
#define INT_MAX 0x7fffffff 
#define INT_MIN 0x80000000
int* maxSubArray(int* a, int low, int high);
int* maxCrossSubArray(int* a, int low, int mid, int high);
int* maxArray(int* a, int n, int &lowRe, int &highRe);


/*最大子数组问题*/
int* maxSubArray(int* a, int low, int high) {
	if (low == high) {
		int result[] = {low, high, *(a + low)};
		return result;
	}
	else {
		int middle = (low + high) / 2;
		//声明3个数组存放结果
		int *left = new int[3];
		int *right = new int[3];
		int *cross = new int[3];
		//左边的
		left = maxSubArray(a, low, middle);
		right = maxSubArray(a, middle + 1, high);
		cross = maxCrossSubArray(a, low, middle, high);
		if (*(left + 2) >= *(cross + 2) && *(left + 2) >= *(right + 2)) {
			return left;
		}
		else if (*(right + 2) >= *(cross + 2) && *(right + 2) >= *(left + 2)) {
			return right;
		}
		else {
			//for (int i = 0; i <= 2; ++i) {
			//	std::cout << *(cross + i) << "\t";
			//}
			return cross;
		}
	}
}


/*找到从中间切开的最大子数组*/
int* maxCrossSubArray(int* a, int low, int mid, int high) {
	//左子数组的标记
	int left = 0;
	int leftSum = INT_MIN;
	int sumL = 0;
	for (int i = mid; i >= low; --i) {
		sumL += *(a + i);
		if (sumL > leftSum) {
			leftSum = sumL;
			left = i;	
		}
	}
	//右子数组的标记
	int right = 0;
	int rightSum = INT_MIN;
	int sumR = 0;
	for (int i = mid + 1; i <= high; ++i) {
		sumR += *(a + i);
		if (sumR > rightSum) {
			rightSum = sumR;
			right = i;
		}
	}
	int *result = new int[3];
	*(result) = left;
	*(result + 1) = right;
	*(result + 2) = leftSum + rightSum;
	//int result[] = { left, right, leftSum + rightSum };
	//for (int i = 0; i <= 2; ++i) {
	//	std::cout << *(result + i) << "\t";
	//}
	return result;
}


/*暴力求解，找一个最大的数组返回，算法的时间复杂度是n的平方*/
int* maxArray(int* a, int n, int &lowRe, int &highRe) {
	int low = 0, high = 0;
	int max = 0;
	//找出从i到j中最大子数组(假设)
	for (int i = 0; i < n; ++i) {
		int sum = *(a + i);
		if (max < sum) {
			low = i;
			high = i;
			max = sum;
		}
		for (int j = i + 1; j < n; ++j) {
			sum += *(a + j);
			if (sum > max) {
				max = sum;
				low = i; 
				high = j;
			}
		}
	}
	lowRe = low;
	highRe = high;
	//找出low high后new一个最大子数组返回
	int* big = new int[high - low + 1];
	for (int i = 0; i <= high - low; ++i) {
		*(big + i) = *(a + low + i);
	}
	return big;
}


//二分搜索
int binarySearch(int *a, int x, int left, int right) {
	while (left < right) {
		int middle = (right + left) / 2;
		if (*(a + middle) == x) {
			return *(a + middle);
		}
		else if (*(a + middle) < x) {
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}
	return -1;
}