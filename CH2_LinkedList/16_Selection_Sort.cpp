/*
2019-11.23
单链表的选择排序
输入:
5
1 3 2 4 5
输出:
1 2 3 4 5
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

list_node* getSmallestPreNode(list_node* head)
{
	list_node *cur = head, *pre = NULL;
	list_node *small = head, *pre_small = NULL;
	while (cur)
	{
		if (cur->val < small->val)         // small用于对比数值的大小
		{
			small = cur;
			pre_small = pre;
		}
		pre = cur; 
		// pre = pre->next;      这样写会段错误, 应该按上一行的表达式
		cur = cur->next;
	}
	return pre_small;
}


list_node * selection_sort(list_node * head)  //   2 4 5 1 3 --> 1 2 4 5 3
{
	list_node *cur = head, *pre = NULL;
	list_node *small = NULL, *tail = NULL;
	while (cur)
	{
		pre = getSmallestPreNode(cur);      // 获取要最小值节点的前驱
		if (pre)     // pre非空,即最小的元素不是未排序数组的第一个
		{
			small = pre->next;
			pre->next = small->next;
		}
		else
			small = cur;        // pre==NULL
		if (tail)     // tail非空(已排序的元素不止一个)
		{
			tail->next = small;
			tail = tail->next;
		}
		else     
		{
			head = small;       // 最后返回的地址
			tail = small;
		}
		cur = cur==small ? cur->next : cur;
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
    list_node * new_head = selection_sort(head);
    print_list(new_head);
    return 0;
}