/*
2019-10.25
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


list_node * check(list_node * head)        // 时间复杂度O(2n),空间复杂度O(n)
{
    //////在下面完成代码
    list_node* cur = head;
    stack<int> s;
    while (cur)
    {
        s.push(cur->val);
        cur = cur->next;
    }
    
    cur = head;
    while (!s.empty())
    {
        if (s.top() != cur->val)
        {
            cout << "false";
            return head;
        }
        s.pop();
        cur = cur->next;
    }
    
    cout << "true";
    return head;

}


int main ()
{
    int L, R;
    list_node * head = input_list();
    check(head);
    return 0;
}