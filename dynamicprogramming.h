#ifndef DP_H_
#define DP_H_
#include <map>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
/*��̬�滮��ⲽ�裺1.�̻�һ�����Ž�Ľṹ����
				  2.�ݹ�ض������Ž��ֵ
				  3.�������Ž��ֵ��ͨ�������Ե����ϵķ���
				  4.���ü��������Ϣ����һ�����Ž�
*/
//pi��ֵ����
int p[7] = { 30, 35, 15, 5, 10, 20, 25 };
std::string sourceData[6] = { "A1", "A2", "A3", "A4", "A5", "A6" };

void matrixchain(int **m, int **s, int n) {
	//���ڱ�����С��ֵ
	long long int q = 0;
	//��ʼ��
	for (int i = 0; i < n; ++i) {
		m[i][i] = 0;
	}
	for (int l = 2; l <= n; ++l) {
		//�������ʣ����n-l + 1�����Ǹ�ʲô��
		for (int i = 0; i < n - l + 1; ++i) {
			int j = i + l - 1;
			//INT_MAX���b��Ȼ��2��31�η���ô����զ�������أ����� 
			m[i][j] = m[i + 1][j] + p[i] * p[i + 1] * p[j + 1];
			s[i][j] = i;
	/*		std::cout << m[i][j];*/
			for (int k = i + 1; k < j; ++k) {
				//��ô�ӵĻ�������������ҵĸ��Թ�
				q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}


//�ݹ�Ĵ�ӡ�����
void traceBack(int **s, int i, int j) {
	if (i == j) {
		std::cout << sourceData[i]; 
		return;
	}
	else {
		std::cout << "(";
		traceBack(s, i, s[i][j]);
		traceBack(s, s[i][j] + 1, j);
		std::cout << ")";
	}
}


//�ǵݹ��㷨���
void printAnswer(int **s, int n) {
	int size = 1;
	std::stack<int> left;
	stack<int> right;
	stack<int> info;	//info��ֵ��ʾ�ǵ�һ�����û��ǵڶ������� 0��ʾ��һ�����á�1��ʾ�ڶ�������
	left.push(0);
	right.push(5);
	info.push(0);
	int k = 0;
	while (!left.empty() && !right.empty()) {
		//������õ��ǵ�һ������
		if (left.top() == right.top()) {
			//֮ǰ���õ��ǵ�һ��
			if (info.top() == 0) {
				cout << sourceData[left.top()];
				left.pop();
				right.pop();
				info.pop();
				//��һ���������ص�ʱ��   ��ڱ�Ϊ�ڶ�������������ջ���ı�־Ҫ�ĳ�1
				//�������ص��õڶ���
				if (!info.empty()) {
					info.pop();
					info.push(1);
				}
				left.push(s[left.top()][right.top()] + 1);
				right.push(right.top());
				info.push(1);
			}
			else {
				while (!info.empty()) {
					if (info.top() == 1) {
						if (left.top() == right.top()) {
							cout << sourceData[left.top()];
							left.pop();
							right.pop();
							info.pop();
						}
						else {
							left.pop();
							right.pop();
							info.pop();
							cout << ")";
						}
						
					}
					else {
						break;
					}
				}
				//���õڶ���
				if (!left.empty() && !right.empty()) {
					left.push(s[left.top()][right.top()] + 1);
					right.push(right.top());
					if (!info.empty()) {
						info.pop();
						info.push(1);
						info.push(1);
					}
				}
				else {
					break;
				}

			}
			continue;
		}
		while (!left.empty() && !right.empty() && left.top() != right.top()) {
			cout << "(";
			//k = s[left.top()][right.top()];
			//����Ӧ�������߶�Ҫpush��
			//���õ�һ��
			left.push(left.top());
			right.push(s[left.top()][right.top()]);
			if (!info.empty()) {
				info.pop();
				info.push(0);
			}
			info.push(0);
		}
		if (left.top() == right.top()) {
			//���������ȵĻ���ֱ�ӽ����жϲ���
			continue;
		}
		//���õڶ���
		left.push(s[left.top()][right.top()] + 1);
		right.push(right.top());
		if (!info.empty()) {
			info.pop();
			info.push(1);
			info.push(1);
		}
	}
}
////�ݹ鷵�ء������ǲ��Ƕ�Ҫ��ջ,�жϺ����ڵ�һ���ط���
//while (size) {
//	if (left.top() == right.top()) {
//		cout << sourceData[left.top()];
//		left.pop();
//		right.pop();
//	}
//	else {
//		cout << ")";
//		left.pop();
//		right.pop();
//	}
//}
//left.push(s[left.top()][right.top()] + 1);
//right.push(right.top());





//�ǵݹ�ش�ӡ�����ŵĽ�:ʹ��ջ
//���ȼ���s[0,5]��ֵΪ2����0��2���ַ�push��ջ
//Ȼ�����s[0��2]��ֵΪ0�� pop��һ����
//
void printBestAnswer(int **s, int n) {

	int k = s[0][n - 1];
	int left = 0;
	int right = 0;
	std::stack<int> position;
	position.push(k);
	while (position.empty()) {
		k = 
		left = s[0][k];
		right = s[k + 1][n - 1];
	}
	
	std::stack<std::string> stack;
	for (int i = k; i >= 0; --i) {
		stack.push(sourceData[i]);
	}
	std::cout << "(";
	std::string hehe = stack.top();
	std::cout << hehe;
}

#endif DP_H_