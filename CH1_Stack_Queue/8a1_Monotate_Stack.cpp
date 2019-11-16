/*
2019-10.11
栈--单调栈结构--基础
时间O(N^2)
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
using namespace std;

vector<int> vec;

int main()
{
	// freopen("in.txt", "r", stdin);
	int num, val;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> val;
		vec.push_back(val);
	}
	
	for (int i = 0; i < num; i++)
	{
		int lind = -1, rind = -1;
		for (int j = i-1; j >= 0; j--)        // 向左遍历
		{
			if (vec[j] < vec[i])
			{
				lind = j;
				break;
			}
		}
		cout << lind << " ";
		
		for (int j = i+1; j < num; j++)       // 向右遍历
		{
			if (vec[j] < vec[i])
			{
				rind = j;
				break;
			}
		}
		cout << rind << endl;
	}
	return 0;
}