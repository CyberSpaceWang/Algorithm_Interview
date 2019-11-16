/*
2019-10.30
链表--将两个单链表相加链表
时间O(N),空间O(N)
输入:
3 2
9 3 7
6 3
输出:
1 0 0 0
*/

# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list(int n)
{
    int val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
        }
        else {
            list_node * new_pnode = new list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}


/*--------------------------------------Code Here--------------------------------------*/

list_node * add_list(list_node * head1, list_node * head2)   // 要求返回链表
{
    //////在下面完成代码
	stack<int> s1, s2;
	while (head1)
	{
		s1.push(head1->val);
		head1 = head1->next;
	}
	while (head2)
	{
		s2.push(head2->val);
		head2 = head2->next;
	}
	int add=0, val1, val2, tot;
	list_node* cur = NULL;
	while (!s1.empty() || !s2.empty())
	{
		val1 = s1.empty() ? 0 : s1.top();
		if (!s1.empty())
			s1.pop();
		val2 = s2.empty() ? 0 : s2.top();
		if (!s2.empty())
			s2.pop();
		tot = val1 + val2 + add;
		if (tot >= 10)
		{
			tot -= 10;
			add = 1;
		}
		else
			add = 0;
		list_node* node = new list_node();
		node->val = tot;
		node->next = cur;
		cur = node;
	}
	if (add)
	{
		list_node* node = new list_node();
		node->val = add;
		node->next = cur;
		cur = node;
	}
	return cur;
}


void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}

int main ()
{
    int n, m;
    scanf("%d%d", &n, &m);
    list_node * head1 = input_list(n), * head2 = input_list(m);
    list_node * new_head = add_list(head1, head2);
    print_list(new_head);
    return 0;
}