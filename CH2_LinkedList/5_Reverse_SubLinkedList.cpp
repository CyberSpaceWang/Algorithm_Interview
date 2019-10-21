/*
2019-10.21
CH2 链表--反转部分链表
输入:
5
1 2 3 4 5
1 3
输出:
3 2 1 4 5
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

/*----------------------------------------Code Here-------------------------------------*/
list_node * reverse_list(list_node * head, int L, int R)
{
    //////在下面完成代码,分两种情况---反转包括头部和不包括头部
	list_node* node1 = head;
	int cnt = 0;
	list_node* fpre = NULL, *tpos = NULL;
	while (node1)
	{
		cnt++;
		fpre = cnt==L-1 ? node1 : fpre;
		tpos = cnt==R+1 ? node1 : tpos;
		node1 = node1->next;
	}
	
	node1 = fpre==NULL ? head : fpre->next;    // 需要掉顺序的头结点,但不是返回的头结点
	list_node* node2 = node1->next;
	node1->next = tpos;
	list_node* node3 = NULL;       // 先定义为NULL
	while (node2 != tpos)
	{
		node3 = node2->next;
		node2->next = node1;
		node1 = node2;
		node2 = node3;
	}
	if (fpre == NULL)
		return node1;
	else                        // 头结点不需要逆序时,多一步,即将逆序点前一位的节点指向node1
	{
		fpre->next = node1;
		return head;
	}
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
    int L, R;
    list_node * head = input_list();
    scanf("%d%d", &L, &R);
    list_node * new_head = reverse_list(head, L, R);
    print_list(new_head);
    return 0;
}