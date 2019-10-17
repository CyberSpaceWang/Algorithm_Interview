/*
2019-10.15
CH1 双端队列--最大值减最小值<=num的子数组数量
输入:
5 2 
1 2 3 4 5

输出:
12
*/

#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

deque<int> qmax;
deque<int> qmin;
const int maxn = 1000005;
int arr[maxn];

int main()
{
	// freopen("in.txt", "r", stdin);
	int len, num;
	cin >> len >> num;
	
	for (int i = 0; i < len; i++)
		cin >> arr[i];
	int i = 0, j = 0, res = 0;
	
	while (i < len)
	{
		while (j < len)
		{
            while (!qmax.empty() && arr[qmax.back()] <= arr[j])
            qmax.pop_back();
             qmax.push_back(j);
    
            while (!qmin.empty() && arr[qmin.back()] >= arr[j])
                qmin.pop_back();
            qmin.push_back(j);
			// 此时,双端队列维护单的是[i,j]中的最大最小值
			if (arr[qmax.front()] - arr[qmin.front()] > num)
				break;
			j++;
		}
		res += j - i;
		if (qmin.front() == i)     // 避免队头元素越界
			qmin.pop_front();
		
		if (qmax.front() == i)
			qmax.pop_front();
		i++; 
	}
	
	cout << res << endl;
	return 0;
}
