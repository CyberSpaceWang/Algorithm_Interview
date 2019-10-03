/*
2019-9.24
CH1 栈--设计一个有getMin功能的栈，测试用例
6
push 3
push 2
push 1
getMin
pop
getMin
*/
#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
using namespace std;

int main()
{
	stack<int> stackData, stackMin;
	// freopen("in1.txt", "r", stdin);     
	int op;
	cin >> op;
	for (int i = 0; i < op; i++)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			int num;
			cin >> num;
			stackData.push(num);    // 栈不为空时stackMin.top()会出现段错误
			if (stackMin.empty() || num <= stackMin.top())
				stackMin.push(num);
		}
		else if (s == "pop")
		{
			int num = stackData.top();
			stackData.pop();
			if (num == stackMin.top())
				stackMin.pop();
		}
		else
		{
			cout << stackMin.top() << endl;
		}
	}	
	return 0;
}
