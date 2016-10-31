#ifndef DP_H_
#define DP_H_
#include <map>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
/*动态规划求解步骤：1.刻画一个最优解的结构特征
				  2.递归地定义最优解的值
				  3.计算最优解的值，通常采用自底向上的方法
				  4.利用计算出的信息构造一个最优解
*/
//pi的值数组
int p[7] = { 30, 35, 15, 5, 10, 20, 25 };
std::string sourceData[6] = { "A1", "A2", "A3", "A4", "A5", "A6" };

void matrixchain(int **m, int **s, int n) {
	//用于保存最小的值
	long long int q = 0;
	//初始化
	for (int i = 0; i < n; ++i) {
		m[i][i] = 0;
	}
	for (int l = 2; l <= n; ++l) {
		//保存疑问：这个n-l + 1到底是个什么鬼
		for (int i = 0; i < n - l + 1; ++i) {
			int j = i + l - 1;
			//INT_MAX这个b竟然有2的31次方那么大，你咋不上天呢？？？ 
			m[i][j] = m[i + 1][j] + p[i] * p[i + 1] * p[j + 1];
			s[i][j] = i;
	/*		std::cout << m[i][j];*/
			for (int k = i + 1; k < j; ++k) {
				//这么加的话。。会溢出。我的个乖乖
				q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}


//递归的打印出结果
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


//非递归算法输出
void printAnswer(int **s, int n) {
	int size = 1;
	std::stack<int> left;
	stack<int> right;
	stack<int> info;	//info的值表示是第一个调用还是第二个调用 0表示第一个调用。1表示第二个调用
	left.push(0);
	right.push(5);
	info.push(0);
	int k = 0;
	while (!left.empty() && !right.empty()) {
		//这里调用的是第一个函数
		if (left.top() == right.top()) {
			//之前调用的是第一个
			if (info.top() == 0) {
				cout << sourceData[left.top()];
				left.pop();
				right.pop();
				info.pop();
				//第一个函数返回的时候   入口变为第二个函数，所以栈顶的标志要改成1
				//函数返回调用第二个
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
				//调用第二个
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
			//这里应该是两边都要push的
			//调用第一个
			left.push(left.top());
			right.push(s[left.top()][right.top()]);
			if (!info.empty()) {
				info.pop();
				info.push(0);
			}
			info.push(0);
		}
		if (left.top() == right.top()) {
			//如果两个相等的话。直接进入判断部分
			continue;
		}
		//调用第二个
		left.push(s[left.top()][right.top()] + 1);
		right.push(right.top());
		if (!info.empty()) {
			info.pop();
			info.push(1);
			info.push(1);
		}
	}
}
////递归返回。不管是不是都要退栈,判断函数在第一个地方有
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





//非递归地打印出最优的解:使用栈
//优先计算s[0,5]的值为2，从0到2将字符push进栈
//然后计算s[0，2]的值为0， pop第一个，
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