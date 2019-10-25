#include <iostream>

using namespace std;

int main()
{
	int n, m, new_num;
	cin >> n >> m;
	int last = 1;
	for (int i = 2; i <= n; i++)
	{
		new_num = (last+m-1)%i+1;        // 注意m是报到num就自杀
		last = new_num;
	}
	cout << last;
	return 0;
}