/*
2019-10.17
CH2 链表--打印两个有序链表的公共部分
输入:
4
1 2 3 4
5
1 2 3 5 6
输出:
1 2 3
*/

# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
}; //链表的节点

list_node * input_list(void) //读入链表
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d", &n);
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


void sol(list_node * a_head, list_node * b_head)
{
    //////在下面完成代码
	while (a_head && b_head)
	{
		if (a_head->val == b_head->val)
		{
			cout << a_head->val << " ";
			a_head = a_head->next;
			b_head = b_head->next;
		}
		else if (a_head == NULL || a_head->val > b_head->val)
			b_head = b_head->next;
		else
			a_head = a_head->next;
	}
}

int main ()
{
	freopen("in.txt", "r", stdin);
    list_node * a_head = input_list(); // A 链表的头节点
    list_node * b_head = input_list(); // B 链表的头节点
    sol(a_head, b_head);
    return 0;
}