/*
2019-9.26
CH1 栈--使用递归函数和栈操作逆序一个栈
测试样例
5
1 2 3 4 5
*/

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

stack <int> s;

int Get_Remove_Last_Ele(stack<int> &s)   // 删除底层元素，其他正常放入!
{
	int temp = s.top();     // 当前元素,后续也应当push该值
	s.pop();
	if (s.empty())
	{
		return temp;
	}
	else
	{
		int result = Get_Remove_Last_Ele(s);
		// 回溯
		s.push(temp);
		return result;        // 此函数并不完美,
	}
}

void reverse(stack<int> &s)
{
	// int temp = s.pop();
	int last = Get_Remove_Last_Ele(s);
	if (s.empty())
	{
		cout << last << " ";
		// s.push(last);
		return ;
	}
	else
	{
		reverse(s);
		// s.push(last);
		cout << last << " ";
	}

}

int main()
{
	// freopen("in.txt", "r", stdin);
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int val;
		cin >> val;
		s.push(val);
	}
	reverse(s);
	/*
	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	*/
	return 0;
}
