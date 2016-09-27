#pragma once
#include <iostream>
//交换列表中的值
namespace recursion {
	void swap(int *a, int i, int j) {
		int temp = *(a + i);
		*(a + i) = *(a + j);
		*(a + j) = temp;
	}
}

/*全排列问题*/
void perm(int *a, int k, int m) {
	if (k == m) {
		for (int i = 0; i < m; ++i) {
			std::cout << *(a + i) << "\t";
		}
		std::cout << "递归返回" << std::endl;
		std::cout << std::endl;
	}
	else {
		for (int i = k; i < m; ++i) {
			recursion::swap(a, k, i);
			for (int j = 0; j < 4; ++j) {
				std::cout << *(a + j) << "\t";
			}
			std::cout << "递归前k=" << k << "i=" << i << std::endl;
			perm(a, k + 1, m);
	
			recursion::swap(a, k, i);
		}
	}
}


