/*
2019-10.27 
CH2 链表--将单链表按某值划分成左边小、中间相等、右边大的形式
输入:
6 3
3 3 3 4 5 1
输出:
1 3 3 3 5 4
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

void swap(int arr[], int a, int b)
{
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

void arrPartition(int arr[], int pivot, int len)
{
    int small = -1, big = len, ind = 0;
    while (ind != big)
    {
        if (arr[ind] == pivot)
            ind++;
        else if (arr[ind] < pivot)          
        // 此时有两种情况: case1--ind比small大1位,case2--ind比small大多位,中间全部是pivot(3 3 3 1 4 5)中的1
            swap(arr, ++small, ind++);   // 用small+1与ind交换,将<pivot放到前面,也有可能是自己与自己交换
        else
        // 因为遍历方向从左至右,故左边元素都已符合要求,但右侧不确定,故此处ind不能++
            swap(arr, ind, --big);   
    }
    
}

list_node * list_partition(list_node * head, int pivot)
{
    //////在下面完成代码,注:arr[]在全局处定义
    int len = 0;
    list_node* cur = head;
    while (cur)
    {
        arr[len++] = cur->val;
        cur = cur->next;
    }
    arrPartition(arr, pivot, len);
    cur = head;
    len = 0;
    while (cur)
    {
        cur->val = arr[len++];
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
}


int main ()
{
    list_node * head = input_list();
    list_partition(head, pivot);
    print_list(head);
    return 0;
}