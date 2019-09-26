#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
using namespace std;


class Solution
{
public:
	stack<int> stackData, stackMin;
	void push(int value)
	{
		stackData.push(value);
		if (stackMin.empty() || value <= stackData.top())
		{
			stackMin.push(value);
		}
	}

	void pop()
	{
		int num = stackData.top();
		stackData.pop();
		if (num == stackMin.top())
			stackMin.pop();
	}

	int getMin()
	{
		return stackMin.top();
	}

};


int main()
{
	// freopen("in1.txt", "r", stdin);
	int op;
	cin >> op;
	Solution obj;
	for (int i = 0; i < op; i++)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			int num;
			cin >> num;
			obj.push(num);
		}
		else if (s == "pop")
		{
			obj.pop();
		}
		else
			cout << obj.getMin() << endl;
	}
	return 0;
}