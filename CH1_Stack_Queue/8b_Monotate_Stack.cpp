/*
2019-10.11
CH1 栈--单调栈结构--基础,空间换时间O(N)求解
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
stack<int> s;            // 存储索引而不是值

int main()
{
	// freopen("in.txt", "r", stdin);
	int len, val, lind, rind;
	cin >> len;
	for (int i = 0; i < len; i++)
	{
		cin >> val;
		vec.push_back(val);
	}
	
	for (int i = 0; i < len; i++)
	{
		while (!s.empty() && vec[s.top()] > vec[i])     // 不是单调栈
		{
			int val = s.top();
			s.pop();
			lind = s.empty() ? -1 : s.top();   // 判断栈是否为空从而确定左索引
			rind = i;            // 因为加入i后单调性被破坏,故右索引为i
			arr[val][0] = lind;
			arr[val][1] = rind;
		}
		s.push(i);
	}
	
	while (!s.empty())            // 处理最后剩余的元素
	{
		int val = s.top();
		s.pop();
		lind = s.empty() ? -1 : s.top();
		arr[val][0] = lind;
		arr[val][1] = -1;          // 因为单调递增,故右边不存在更小的值,右索引为-1
	}
	
	for (int i = 0; i < len; i++)
		cout << arr[i][0] << " " << arr[i][1] << endl;
	return 0;
}
