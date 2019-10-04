/*
2019-9.28
CH1 栈--用一个栈实现另一个栈的排序
5
5 8 4 3 6
*/

#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main()
{
	// freopen("in.txt", "r", stdin);
	stack<int> s1, s2;        // s1是用于存储排序的栈, s2用于存放临时数据
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int temp;
		cin >> temp;
		if (s1.empty() || temp >= s1.top())  // 栈为空或temp比栈顶元素小
			s1.push(temp);
		else            // 当前的数比s1栈顶的元素大
		{
			while (!s1.empty() && temp < s1.top())     // 后面的判断不能掉
			{
				s2.push(s1.top());
				s1.pop();
			}
			s1.push(temp);
			while (!s2.empty())
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