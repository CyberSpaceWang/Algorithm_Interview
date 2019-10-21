/*
2019-10.19
CH2 链表--反转单双链表
输入:
3
1 2 3
4
1 2 3 4

输出:
3 2 1
4 3 2 1
*/

# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};
struct double_list_node{
    int val;
    struct double_list_node * pre, * next;
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

double_list_node * input_double_list(void)
{
    int n, val;
    double_list_node * phead = new double_list_node();
    double_list_node * cur_pnode = phead;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
            cur_pnode->pre = NULL;
        }
        else {
            double_list_node * new_pnode = new double_list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            new_pnode->pre = cur_pnode;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}

//---------------------------------------Code Here------------------------------------------//
list_node * reverse_list(list_node * head)
{
    //////在下面完成代码
    if (head->next == NULL)
    	return head;
	list_node* pre = NULL, *cur = head;   // 对pre进行修改
	list_node* next = cur->next;
	while (next)
	{
		cur->next = pre;
		pre = cur;
		cur = next;
		next = next->next;
	}
	cur->next = pre;
	return cur;
}

double_list_node * reverse_double_list(double_list_node * head)
{
    //////在下面完成代码
	double_list_node* pre = NULL, *next = NULL;
	while (head)
	{
		next = head->next;          // 不事先定义位置,进入循环后定义
		head->next = pre;
		head->pre = next;
		// next = pre->pre;
		pre = head;
		head = next; 
	}
	return pre;
	
}

void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}

void print_double_list(double_list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}

int main ()
{
	// freopen("in.txt", "r", stdin);
    list_node * head = input_list();
    double_list_node * double_head = input_double_list();
    list_node * new_head = reverse_list(head);
    double_list_node * new_double_head = reverse_double_list(double_head);
    print_list(new_head);
    print_double_list(new_double_head);
    return 0;
}