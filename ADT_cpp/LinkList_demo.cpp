/*
2019-10.13 
链表的创建及其部分基础操作的C++实现
链表结构如下:(数字代表位置pos)
head(0)-->node(1)-->node(2)-->...
*/

#include <iostream>
#include <cstdio>

using namespace std;

struct node
{
	int data;
	node* next;
};


node* create(int Array[], int len)      // 使用数组生成链表
{
	node *head = new node;   
	head->next = NULL;
	node *temp = head;        // temp遍历时的控制指针

	for (int i = 0; i < len; i++)
	{
		node *p = new node;
		p->data = Array[i];
		p->next = NULL;
		temp->next = p;
		temp = temp->next;
	}
	return head;
}

int search(node* head, int pos)    // 查找第pos位置的元素
{
	int cnt = 1;
	node* L = head->next;
	while(L)
	{
		if (cnt == pos)
			return L->data;
		cnt++;
		L = L->next;
	}
	return -1;
}

node* Insert(node* head, int pos, int x)    // 把x插入到第pos位置上
{
	int cnt = 0;
	node* L = head;
	while(L)                       // 等价于while (L != NULL)
	{
		if (cnt == pos - 1)        // 找到pos-1位置
		{
			node* new_node = new node;
			new_node->data = x;
			new_node->next = L->next;
			L->next = new_node;
			return head;
		}
		L = L->next;
	}
	return NULL;
}


void Del(node* head, int x)      // 删除值==x的节点
{
	node* pre = head;
	node* temp = pre->next;

	while(temp)
	{
		if (temp->data == x)
		{
			pre->next = temp->next;
			delete(temp);
			temp = pre->next;
		}
		else
		{
			pre = pre->next;
			temp = temp->next;
		}
	}
}


void Print_List(node* head)
{
	node* L = head->next;
	while(L)
	{
		printf("%d ",L->data);
		L = L->next;
	}
	printf("\n");
}


int main()
{
	int Array[5] = {5,3,6,1,2};
	// 创建
	node* head = create(Array, 5);
	Print_List(head);

	// 查找第3个位置的元素值
	printf("val = %d\n",search(head, 3));

    // 插入0到第一个位置上
    Insert(head, 1, 0);
	Print_List(head);

	// 删除数值是1的结点
	Del(head, 1);
	Print_List(head);

    return 0;
}
