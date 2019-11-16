/*
2019-11.7
链表--将链表的每K个节点逆序
时间O(N),空间O(N/2)
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

stack<list_node*> s;

list_node* Reverse_List(list_node* head, int K)         // 反转链表
{
    int temp = 0;
    list_node* cur = head, *next = NULL, *pre = NULL;
    list_node* new_head = head, *fir = NULL;
    while (cur)
    {
    	next = cur->next;
    	temp++;
    	s.push(cur);           // cur链表中顺序遍历的值
    	if (temp % K == 0)
    	{
    		fir = s.top();        // 栈顶元素			
    		if (pre)
    			pre->next = fir;
    		s.pop();
    		while (!s.empty())
    		{
    			fir->next = s.top();
    			fir = s.top();
    			s.pop();
    		}
    		pre = fir;           // 倒序后的最后一个!3-2-1中的1
    		pre->next = next;    // 针对32145和321654的前者(默认情况,若有改动后续进行调整)
    		new_head = new_head==head ? cur : new_head;
    	}
    	cur = next;
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