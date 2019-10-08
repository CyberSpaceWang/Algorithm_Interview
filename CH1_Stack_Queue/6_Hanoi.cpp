/*
2019-10.8
CH1 栈--使用栈模拟汉诺塔
输入样例:
2

输出:
Move 1 from left to mid
Move 1 from mid to right
Move 2 from left to mid
Move 1 from right to mid
Move 1 from mid to left
Move 2 from mid to right
Move 1 from left to mid
Move 1 from mid to right
It will move 8 steps.
*/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
                         // 本程序默认中间的柱子固定,若想更灵活使用汉诺塔,可将"mid"改为mid变量
int process(int num, string left, string mid, string right, string from, string to)
{
	if (num == 1)         // 递归边界
	{
		cout << "Move 1 from " << from << " to mid\n";
		cout << "Move 1 from " << "mid to " << to << endl;
		return 2; 
	}                          // 返回值记录步数
	int part1 = process(num-1, left, mid, right, from, to);     // 上层num-1柱子从左->右
	cout << "Move " << num << " from " << from << " to mid\n"; // 底层柱子从from->to,此时from不一定是left
	int part2 = process(num-1, left, mid, right, to, from);     // 上层num-1柱子从右->左
	cout << "Move " << num << " from mid to " << to << endl;	// 底层柱子从to->from
	int part3 = process(num-1, left, mid, right, from, to);     // 上层num-1柱子从左->右
	return part1 + part2 + part3 + 2;
}

int main()
{
	freopen("in.txt", "r", stdin);
	int num;          // 本题输入太少,可不使用freopen
	cin >> num;
	string left = "left", mid = "mid", right="right";
	int steps = process(num, left, mid, right, left, right);
	cout << "It will move "<< steps << " steps." << endl;
	return 0;
}
