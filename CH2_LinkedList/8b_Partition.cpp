/*
2019-10.27 
CH2 链表--将单链表按某值划分成左边小、中间相等、右边大的形式
时间复杂度O(N),空间复杂度O(N)

输入:
7 5
7 9 1 8 5 2 5
输出:
1 2 5 5 7 9 8
*/

# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

int pivot;
const int maxn = 1000005;
int arr[maxn];

list_node * input_list(void)
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d%d", &n, &pivot);
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

list_node * list_partition(list_node * head, int pivot)
{
    //////在下面完成代码,注:arr[]在全局处定义
    list_node* sH = NULL, *sL = NULL;
    list_node* eH = NULL, *eL = NULL;
    list_node* bH = NULL, *bL = NULL;
    while (head)
    {
        if (head->val < pivot)
        {
            if (sH == NULL)
            {
                sH = head;             // 两个都要更新
                sL = head;
            }    
            else
            {
                sL->next = head;
                sL = sL->next;          // 注意要更新
            }
        }
        else if (head->val == pivot)
        {
            if (eH == NULL)
            {
                eH = head;
                eL = head;
            }
            else
            {
                eL->next = head;
                eL = eL->next;
            }
            
        }
        else
        {
            if (bH == NULL)
            {
                bH = head;       
                bL = head;
            }
            else
            {
                bL->next = head;
                bL = bL->next;
            }
        }
        head = head->next;
    }
    if (sL)                // 把前一段的末尾连到下一段的开头,但若前一段为空则不用考虑
    {
        sL->next = eH;     // 若下一段为空则连到下下一段
        eL = eL==NULL ? bH:eL;
    }
    if (eL)
    {
        eL->next = bH;
    }
    
    if (bL)
    {
        bL->next = NULL;
    }
    else
    {
        if (eL)
            eL->next = NULL;
        else
            sL->next = NULL;
    }
    
    return sH==NULL ? eH==NULL?bH:eH : sH; 
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
    list_node * head = input_list();
    head = list_partition(head, pivot);         // 注意有返回值
    print_list(head);
    return 0;
}