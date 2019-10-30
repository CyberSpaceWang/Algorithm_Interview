/*
2019-10.21
CH2 链表--约瑟夫问题--基础,这一题需要读者自己创建循环链表!!!
输入:
5 2
输出:
3
*/

#include <iostream>
#include <vector>
using namespace std;

struct circular_list      // 循环链表:结构体内容与单链表相同,但操作不同
{
	int val;
	circular_list* next;
};


circular_list* input_list(int n)
{
	circular_list* head = new circular_list();  // 局部变量使用栈区存储,动态变量为堆区存储
	circular_list* cur = head;
	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
			cur->val = i;
		else
		{
			circular_list* temp = new circular_list();
			temp->val = i;
			cur->next = temp;
			cur = cur->next;
		}
	}
	cur->next = head;
	return head;
}

//------------------------------------------Code Here-------------------------------------------//
void Joseph(circular_list* head, int num)       // 报数到num个人删除一次
{
	int cnt = 0;
	circular_list* last = head;
	while (last->next != head)
		last = last->next;
	while (last != head)
	{
		cnt++;
		if (cnt == num)      // 删除当前节点
		{
			last->next = head->next;
			cnt = 0;
		}
		else
			last = last->next;
		head = head->next;
	}
	cout << head->val;
}


void print_list(circular_list* head)
{
	circular_list* cur = head;
	do
	{
		cout << cur->val << " ";
		cur = cur->next;
	}while(cur != head);
}

int main()
{
	int n, num;
	cin >> n >> num;
	circular_list* list = input_list(n);
	Joseph(list, num);
	
	return 0;
}