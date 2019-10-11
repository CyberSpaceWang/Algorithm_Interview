/*
2019-10.11
CH1 栈--单调栈结构--进阶,有重复
测试样例:
7
3 4 1 5 6 2 7

输出:
-1 2
0 2
-1 -1
2 5
3 5
2 -1
5 -1
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

const int maxn = 1000005;
int arr[maxn][2];
vector<int> vec;
stack<int> s, s_temp;            // 存储索引而不是值
int k = -1;

int get_lind(stack<int> &s, int val)
{
	if (s.empty())
	{
		k = -1;
		return k;
	}
	if (s.top() != val)
	{
		k = s.top();
		return k;
	}
	int result = s.top();      // 取出来存着
	s.pop();
	arr[result][0] = get_lind(s, val)
	s.push(result);            // 回溯时加回来
	return k;
}

int main()
{
	freopen("in.txt", "r", stdin);
	int len, val, lind, rind;
	cin >> len;
	for (int i = 0; i < len; i++)
	{
		cin >> val;
		vec.push_back(val);
	}
	
	for (int i = 0; i < len; i++)
	{
		while (!s.empty() && vec[s.top()] > vec[i])     // 自顶向下不是单调递增栈
		{
			int val = s.top();     
			s.pop();     // pop后栈顶元素开始与下面相同
			arr[val][0] = get_lind(s, val);
			arr[val][1] = rind;
		}
		s.push(i);
	}
	
	while (!s.empty())            // 处理最后剩余的元素
	{
		int val = s.top();
		s.pop();
		arr[val][0] = get_lind(s, val);
		arr[val][1] = -1;          // 因为单调递增,故右边不存在更小的值,右索引为-1
	}
	
	for (int i = 0; i < len; i++)
		cout << arr[i][0] << " " << arr[i][1] << endl;
	return 0;
}
