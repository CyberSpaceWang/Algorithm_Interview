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

int Get_Remove_Last_Ele(stack<int> &s)   // 获取底层元素值并删除之，其他正常放入!
{
	int temp = s.top();     // 当前元素,后续也应当push该值
	s.pop();
	if (s.empty())
		return temp;
	else
	{
		int result = Get_Remove_Last_Ele(s);
		// 回溯部分
		s.push(temp);
		return result;        // 此函数并不完美,
	}
}

void reverse(stack<int> &s)
{
	if (s.empty())
		return ;
	int last = Get_Remove_Last_Ele(s);
	reverse(s);       // 要获取元素之后再递归, 否则递归无限次! 仔细思考
	cout << last << " ";
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
	return 0;
}
