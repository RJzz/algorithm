#include "recursion.h"
#include "divide.h"
#include "dynamicprogramming.h"
using namespace std;
int main() {
	//ȫ��������
	//int a[] = { 1, 2, 3, 4 };
	//perm(a, 0, 4);
	cout << endl;

	int b[] = { 3,-2,1,2,-3 };//�������59ms
	int c[] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };//���������500ms
	int low = 0, high = 0;
	
	//����ʱ�����
	int linearLow = 0;
	int linearHigh = 0;
	int linearAnswer = maxLinearArray(c, linearLow, linearHigh, 15);

	//�������
	int* x = maxArray(c, 15, low, high);
	//for (int i = 0; i <= high - low; ++i) {
	//	cout << *(x + i) << "\t";
	//}

	//��С������������
	int* fuck = maxSubArray(c, 0, 15);
	//for (int i = 0; i <= 2; ++i) {
	//	cout << *(fuck + i) << "\t";
	//}

	//��������
	/*int result = binarySearch(c, -3, 0, 15);
	cout << "���������Ľ����" << result;
	system("PAUSE");*/

	//�������˷�����
	int **m;
	int **s;

	//��ʼ���������
	m = new int*[6];
	s = new int*[6];
	for (int i = 0; i < 6; ++i) {
		//���ֱ�ʾ��ʽ������
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

