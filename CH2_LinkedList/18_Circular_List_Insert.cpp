/*
2019-11.23
向有序环形单链表中插入元素
输入:
5
1 2 3 4 5
6
输出:
1 2 3 4 5 6
*/
# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};


list_node * input_list(void)
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
            if (i == n) {
                new_pnode->next = phead;
            }
        }
    }
    return phead;
}

/*--------------------------------------Code Here--------------------------------------*/

list_node * insert_num(list_node * head, int num)
{
	list_node *pre = head;
	list_node *cur = head;
	while (pre->next != head)
		pre = pre->next;            // 找到末尾节点(头结点的前驱)
	while (1)
	{
		if (cur->val > num)         // 插入头部或中部(头部需要多加一步)
		{
			list_node *node = new list_node();
			node->val = num;
			pre->next = node;
			node->next = cur;
			if (cur == head)        // 在显示时默认显示在最后,需要做一步调整
				head = node;
			break;
		}
		pre = cur;
		cur = cur->next;
		if (cur == head)      // 插入末尾
		{
			list_node *node = new list_node();
			node->val = num;
			pre->next = node;
			node->next = cur;
			break;
		}
	}
	return head;
}


void print_list(list_node * head)
{
    list_node * h = head;
    while (1) {
        printf("%d ", head->val);
        if (head->next == h) break;
        head = head->next;
    }
    puts("");
}


int main ()
{
    list_node * head = input_list();
    int n;
    scanf("%d", &n);
    list_node * new_head = insert_num(head, n);
    print_list(new_head);
    return 0;
}