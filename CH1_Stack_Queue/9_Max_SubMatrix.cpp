/*
2019-10.15
CH1 栈--最大子矩阵
输入样例:
3 4
1 0 1 1
1 1 1 1
1 1 1 0

输出:
6
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

const int maxn = 2005;
int matrix[maxn][maxn];
int height[maxn];       // 动态切割数组
stack<int> s;


int Get_Max_Area(int height[], int n)    // 某一行(n个元素)切割完之后进入该函数计算最大矩形
{
	int max_area = -1;
	for (int i = 0; i < n; i++)
	{
		while (!s.empty() && height[s.top()] >= height[i])    // 栈内不允许出现重复的数值情况!
		{
			int j = s.top();        // 栈顶元素,需要记录左右索引的元素
			s.pop();
			int k = s.empty() ? -1 : s.top();  // 
			int area = (i-1-k)*height[j];   // 事实上应该是(i-1)-(k+1)+1 == i-k-1;
			max_area = max(area, max_area);
		}
		s.push(i);           // 注意存放的是索引而不是值
	}
	
	while (!s.empty())
	{
		int j = s.top();
		s.pop();
		int k = s.empty() ? -1 : s.top();
		int area = (n-1-k)*height[j];
		max_area = max(area, max_area); 
	}
	return max_area;
	
}

int main()
{
	// freopen("in.txt", "r", stdin);
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
	memset(height, 0, sizeof(height));
	
	int max_area = -1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			height[j] = matrix[i][j] == 0 ? 0 : height[j] + 1;   // +1不能忘了
		}
		int temp_max = Get_Max_Area(height, n);
		max_area = max(max_area, temp_max);
	}	
	
	cout << max_area << endl;
	
	return 0;
}
