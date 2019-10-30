/*
2019-10.27
CH2 链表--判断链表是否是回文结构
输入:
4
1 2 2 1

输出:
true
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


//------------------------------------------Code Here-------------------------------------------//
list_node * check(list_node * head)
{
    //////在下面完成代码
    list_node* subhead = head;       // subhead:后半边的头节点(开始进行反转)
    list_node* last = head;
    list_node* node_front = NULL;    // 追随subhead的前一个节点
    while (last && last->next)
    {
        node_front = subhead;
        subhead = subhead->next;
        last = last->next->next;
    }
    // 此时已经找到了subhead
    // subhead->next = NULL;
    list_node* node = subhead;
    list_node* node_last = NULL;        // 
    while (node)                        // 反转后半部分链表
    {
        node_last = node->next;
        node->next = node_front;
        node_front = node;
        node = node_last;
    }
    subhead->next = NULL;
    // 此时node_front是单链表的末尾节点
    list_node* first_half = head;
    list_node* second_half = node_front;
    int ok = 1;
    while (first_half && second_half)
    {
        if (first_half->val != second_half->val)
        {
            ok = 0;
            cout << "false";
            break;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }
    if (ok)
        cout << "true";
    // 使用node_front, node_last, node进行后半部分反转
    node = node_front;       // 指向最后一个节点
    while (node)
    {
        node_front = node_front->next;
        node->next = node_last;
        node_last = node;
        node = node_front;
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
    int L, R;
    list_node * head = input_list();
    check(head);
    // print_list(head);
    return 0;
}