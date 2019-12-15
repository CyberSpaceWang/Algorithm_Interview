/*
2019-12.1
二叉树模板
*/

#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node *left, *right;
};

Node* Construct()             // 构造二叉树
{
	int n, root_ind;
	cin >> n >> root_ind;
	Node *node = new Node[n+1];          // 注意默认构造函数问题!
	int fa, lch, rch;
	for (int i = 1; i <= n; i++)
	{
		cin >> fa >> lch >> rch;
		node[fa].val = fa;
		node[fa].left = lch!=0 ? &node[lch] : NULL;    // 是0则为NULL,否则指向lch的地址
		node[fa].right = rch!=0 ? &node[rch] : NULL;
	}
	return &node[root_ind];         // 返回指针
}


void PreOrder(Node* root)        // 先序:中左右
{
	if (root == NULL)
		return ;
	cout << root->val << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}


int main()
{
	Node *root = Construct();     // 构建二叉树
	PreOrder(root);
	cout << endl;

	return 0;
}

