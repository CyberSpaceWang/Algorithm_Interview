/*
2019-12.7
将二叉搜索树转换为双向链表
输入:
9
6 4 7
4 2 5
2 1 3
5 0 0
1 0 0
3 0 0
7 0 9
9 8 0
8 0 0
输出:
1 2 3 4 5 6 7 8 9
*/

# include <bits/stdc++.h>
using namespace std;

struct double_list_node{
    int val;
    struct double_list_node * pre, * next;
};

struct BST{
    int val;
    struct BST * lch, * rch;
};

BST * input_BST()
{
    int n, fa, lch, rch;
    scanf("%d", &n);
    BST * root, * new_node;
    map<int, BST *> mp;                      // 一个索引对应一个二叉树节点
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &fa, &lch, &rch);
        if (mp.find(fa) == mp.end()) {
            new_node = (BST *)malloc(sizeof(BST));
            mp[fa] = new_node;
            new_node->val = fa;
            if (i == 1) root = new_node;
        }
        if (lch && mp.find(lch) == mp.end()) {
            new_node = (BST *)malloc(sizeof(BST));
            mp[lch] = new_node;
            new_node->val = lch; new_node->lch = new_node->rch = NULL;
        }
        if (rch && mp.find(rch) == mp.end()) {
            new_node = (BST *)malloc(sizeof(BST));
            mp[rch] = new_node;
            new_node->val = rch; new_node->lch = new_node->rch = NULL;
        }
        mp[fa]->lch = (lch ? mp[lch] : NULL);
        mp[fa]->rch = (rch ? mp[rch] : NULL);
    }
    return root;
}

/*--------------------------------------Code Here--------------------------------------*/

double_list_node* process(BST* root)         // 返回一个双向链表,包含左右指针
{
    if (root == NULL)
    {
        double_list_node* node = new double_list_node();
        node->pre = NULL;
        node->next = NULL;
        return node;
    }
    
    double_list_node* pre = process(root->pre);
    double_list_node* next = process(root->next);
    double_list_node* node;
    node->val = root->val;
    
    
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
    BST * root = input_BST();
    double_list_node * new_double_head = convert(root);
    print_double_list(new_double_head);
    return 0;
}