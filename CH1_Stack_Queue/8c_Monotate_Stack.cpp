/*
2019-10.11
CH1 栈--单调栈结构--进阶,有重复元素
测试样例:
9
3 1 3 4 3 5 3 2 2

输出:
-1 1
-1 -1
1 7
2 4
1 7
4 6
1 7
1 -1
1 -1
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

const int maxn = 1000005;
stack <vector<int> > s;
int arr[maxn][2];
vector<int> vec;

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
	
	for (int i = 0; i < len; i++)    // vec[i]在栈外
	{
		while(!s.empty() && vec[s.top()[0]] > vec[i]) // 若加入vec[i]后不再单调递增,故处理单调的序列
		{
			vector<int> repeat = s.top();
			s.pop(); // 必须紧跟
			// 记录repeat中元素的左索引,为栈顶元素最末尾的索引值,注意不是repeat.size(),repeat已被弹出
			int lind = s.empty() ? -1 : s.top()[s.top().size()-1];
			for (int j = 0; j < repeat.size(); j++)
			{
				arr[repeat[j]][0] = lind;
				arr[repeat[j]][1] = i;   
			}
		}
		if (!s.empty() && vec[s.top()[0]] == vec[i])  // 添加时需要考虑重复的情况,如果重复
		{
			vector<int> re_push = s.top();   // 返回值而非引用,故必须pop()出来添加后再push
			s.pop();
			re_push.push_back(i);    // i是索引,vec[i]是值,比大小时用vec[i],元素添加时用i
			s.push(re_push);
		}
		else                         // 不重复直接添加即可        
		{
			vector<int> re_push;      
			re_push.push_back(i);
			s.push(re_push);
		}
	}
	
	while(!s.empty())       // 处理最后的情况
	{
		vector<int> repeat = s.top();
		s.pop();
		int lind = s.empty() ? -1 : s.top()[s.top().size()-1];
		for (int i = 0; i < repeat.size(); i++)
		{
			arr[repeat[i]][0] = lind;
			arr[repeat[i]][1] = -1;       // 因为单调递增,所以右索引为-1
		}
	}
	
	for (int i = 0; i < len; i++)
		cout << arr[i][0] << " " << arr[i][1] << endl;
	return 0;
}
