/*
2019-9.24
CH1 栈--使用两个栈模拟队列,测试数据:
6
add 1
add 2
add 3
peek
poll
peek
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;

stack<int> spush, spop;

void ToPop()         // 将push栈的元素全部压入pop栈中
{
	if (spop.empty())   // pop栈为空,需要从push栈中一次性导入(这个判断条件是必须的)
	{
		while (!spush.empty())
		{
			int num = spush.top();
			spush.pop();
			spop.push(num);
		}
	}
}


int main()
{
	// freopen("in.txt", "r", stdin);
	int op;
	cin >> op;
	for (int i = 0; i < op; i++)
	{
		string s;
		cin >> s;
		if (s == "add")
		{
			int num;
			cin >> num;
			spush.push(num);
		}
		else if (s == "poll")
		{
			ToPop();
			spop.pop();
		}
		else
		{
			ToPop();
			cout << spop.top() << endl;
		}
	}
	return 0;
}
