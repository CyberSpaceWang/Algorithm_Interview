/*
2019-10.19
CH2 链表--删除链表倒数第k个节点
输入:
5
1 2 3 4 5

输出:
1 2 4 5
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

//------------------------------------------Code Here-------------------------------------------//
list_node * remove_last_kth_node(list_node * head)
{
    //////在下面完成代码
    if (head == NULL || head->next == NULL)
        return NULL;
    if (head->next->next == NULL)
        return head->next;
	list_node* pre = head, *cur = head->next->next;
    while (cur->next && cur->next->next) // 必须有cur->next这个判断,否则段错误,因为NULL没有next指针,访问错误
    {
        pre = pre->next;
        cur = cur->next->next;
    }
    pre->next = pre->next->next;
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
    list_node * rhead = remove_last_kth_node(head);
    print_list(rhead);
    return 0;
}