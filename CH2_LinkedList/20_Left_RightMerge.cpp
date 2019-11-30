/*
2019-11.30
按左右半区的方式重新组合单链表
输入:
6
1 2 3 4 5 6
输出:
1 4 2 5 3 6
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

list_node * relocate(list_node * head)
{
    list_node *last_left = head, *last = head->next;
    while (last->next && last->next->next)      // 处心积虑
    {
        last = last->next->next;
        last_left = last_left->next;
    }
    // last_left是左半边最末端的一个
    list_node *left = head, *right = last_left->next;
    last_left->next = NULL;
    while (left && right)       // 左侧和右侧都非空时进入循环
    {
        list_node *next_left = left->next;       // 1 2 3 vs 4 5 6 --> 1 4 2 3 vs 5 6
        list_node *next_right = right->next;
        left->next = right;
        if (next_left)
            right->next = next_left;
        right = next_right;
        left = next_left;
    }
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
    list_node * head = input_list();
    list_node * new_head = relocate(head);
    print_list(new_head);
    return 0;
}