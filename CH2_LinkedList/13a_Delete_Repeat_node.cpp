/*
删除无序单链表中重复出现的节点
时间:O(N),空间:O(N)
输入:
5
1 3 2 3 1
输出:
1 2 3
*/


# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list()
{
    int val, n;
    scanf("%d", &n);
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
const int maxn = 2000005;
int hash[maxn];

list_node * remove_rep(list_node * head)
{
    memset(hash, 0, sizeof(hash));
    list_node* cur = head, *pre = NULL;
    while (cur)
    {
        if (hash[cur->val + 1000000] == 1)
            pre->next = cur->next;
        else
        {
            hash[cur->val + 1000000] = 1;
            pre = cur;
        }
        cur = cur->next;
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
    list_node * new_head = remove_rep(head);
    print_list(new_head);
    return 0;
}