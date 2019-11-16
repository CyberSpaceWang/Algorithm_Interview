/*
2019-11.16
链表--将链表的每K个节点逆序
时间O(N),空间O(1)
输入:
5
1 2 3 4 5
3
输出:
3 2 1 4 5
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

void Reverse_subList(list_node* head, list_node* tail)      // 如果要逆序123 4,则head为1,tral为4
{
    list_node* cur = head, *next = NULL, *pre = NULL;
    while (cur != tail)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    // return tail;
}


list_node* Reverse_List(list_node* head, int K)         // 反转链表
{
    int temp = 0;
    list_node* cur = head, *next = NULL, *pre = NULL;
    list_node* new_head = head, *fir = NULL;
    list_node* h = head;
    while (cur)
    {
        temp++;
    	next = cur->next;
        if (temp % K == 0)
        {
            if (pre)          // 用于解决第一次不需要匹配的情况
                pre->next = cur;
            Reverse_subList(h, next);
            pre = h;            // pre记录上次需要逆序片段的后缀123的1
            pre->next = next;
            h = next;
            new_head = new_head==head ? cur : new_head;
        }
        cur = next;       // 这里一定不能写成cur=cur->next
    } 
    return new_head;
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
    int n, K;
    scanf("%d", &n);
    list_node * head = input_list(n);
    scanf("%d", &K);
    list_node * new_head = Reverse_List(head, K);
    print_list(new_head);
    return 0;
}