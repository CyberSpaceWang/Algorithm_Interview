/*
2019-10.19
CH2 链表--删除链表倒数第k个节点
输入:
5 4
1 2 3 4 5

输出:
1 3 4 5
*/

# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
}; //链表的节点

int K;

list_node * input_list(void) //读入链表
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d %d", &n, &K);
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

//------------------------------------------Code Here-------------------------------------------//
list_node * remove_last_kth_node(list_node * head, int K)
{
    //////在下面完成代码
	int len = 0;
	list_node* p = head;
	while (p)       // 计算链表长度
	{ 
		len++;
		p = p->next;
	}
	p = head;
	for (int i = 1; i <= len && p; i++)      // 遍历链表找len-K的位置,注意判断条件
	{
		if (i == len - K)
		{
			list_node* next_node = p->next;
			p->next = next_node->next;
		}
		p = p-> next;
	}
	return head;
}

void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main ()
{
	freopen("in.txt", "r", stdin);
    list_node * head = input_list(); // 链表的头节点
    list_node * rhead = remove_last_kth_node(head, K);
    print_list(rhead);
    return 0;
}