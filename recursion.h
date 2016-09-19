#pragma once
#include <iostream>
//�����б��е�ֵ
namespace recursion {
	void swap(int *a, int i, int j) {
		int temp = *(a + i);
		*(a + i) = *(a + j);
		*(a + j) = temp;
	}
}

/*��������*/
void perm(int *a, int k, int m) {
	if (k == m) {
		for (int i = 0; i < m; ++i) {
			std::cout << *(a + i) << "\t";
		}
		std::cout << std::endl;
	}
	else {
		for (int i = k; i < m; ++i) {
			recursion::swap(a, k, i);
			perm(a, k + 1, m);
			recursion::swap(a, k, i);
		}
	}
}


