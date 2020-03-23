/*
2020-3.22
未排序正数数组中累加和为给定值的最长子数组长度
输入:
5 3
1 2 1 1 1
输出:
3
*/

#include <iostream>
using namespace std;

const int maxn = 100005;
int arr[maxn];

int main()
{
	int N, k;
	cin >> N >> k;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int left=0, right=0;
	int sum = arr[0];             // 注意: 在循环中, 判断的是上一次循环中的结果!!
	int max_len = 0;
	
	while (right < N) {         // 每次循环只移动left或right, 且只移动一个单位
		if (sum == k) {         // 最特殊的情况
			if ((right - left + 1) > max_len) {
				max_len = right - left + 1;
			}
			sum -= arr[left];
			left++;	
		}
		else if (sum < k) {       // 普遍情况
			right++;
			if (right == N)        // 此句别写会有bug!! 因为下一句可能导致数组越界
				break; 
			sum += arr[right];
		}
		else {         // 如果超过范围, 大了, 退回
			sum -= arr[left];
			left++;
		}
	}
	
	cout << max_len << endl;
	return 0;
}