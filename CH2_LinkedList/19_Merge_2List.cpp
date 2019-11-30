/*
2019-11.30
合并两个有序链表
输入:
5
1 2 3 4 5
6 
7 8 9 10 11 12
输出:
1 2 3 4 5 7 8 9 10 11 12
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
        }
    }
    return phead;
}

/*--------------------------------------Code Here--------------------------------------*/

list_node * merge_list(list_node * head1, list_node * head2)
{
	list_node *head = head1->val < head2->val ? head1 : head2;
	list_node *cur1 = head==head1 ? head1 : head2;        // 记录小的--主线
	list_node *cur2 = head==head1 ? head2 : head1;
	list_node *pre = NULL;
	while (cur1 && cur2)      // 有一个为空就退出
	{
		if (cur1->val < cur2->val)
		{
			pre = cur1;              // pre指向当前当前变化的前一个,1<2,故接着1
			cur1 = cur1->next;
		}
		else
		{
			//list_node *next = cur1->next;
			list_node *next = cur2->next;
			pre->next = cur2;
			cur2->next = cur1;
			pre = cur2;           // pre现在才是cur2,此时cur2<cur1
			cur2 = next;
		}
	}
	// 考虑主线结束,但副线还没结束的情形(主线最后一个元素比副线小)
	pre->next = cur1 ? cur1 : cur2;      // 哪个非空跟哪个
	return head;
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
    list_node * head1 = input_list();
    list_node * head2 = input_list();
    list_node * new_head = merge_list(head1, head2);
    print_list(new_head);
    return 0;
}