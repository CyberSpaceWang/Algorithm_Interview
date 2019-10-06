/*
2019-9.28
CH1 栈--用一个栈实现另一个栈的排序
测试样例:
5
5 8 4 3 6

输出:
8 6 5 4 3
*/

#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main()
{
	// freopen("in.txt", "r", stdin);
	stack<int> s1, s2;        // s1是用于存储当前已排序的栈(栈底为min), s2用于存放临时数据
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)          // 边输入边更新排序栈
	{
		int temp;
		cin >> temp;
		if (s1.empty() || temp >= s1.top())  // 栈为空或temp比栈顶元素大
			s1.push(temp);
		else            // temp比s1栈顶的元素小
		{
			while (!s1.empty() && temp < s1.top())   // temp比s1栈顶元素小时,将s1栈顶丢至s2中.
				s2.push(s1.top());
				s1.pop();
			}
			s1.push(temp);
			while (!s2.empty())       // 再把s2中临时存放的元素丢回s1
			{
				s1.push(s2.top());
				s2.pop();
			}
		}
	}
	while (!s1.empty())
	{
		cout << s1.top() << " ";
		s1.pop();
	}
}