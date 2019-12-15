/*
2019-12.15
打印二叉树边界节点
输入:
太多
输出:
1 2 4 7 11 13 14 15 16 12 10 6 3
1 2 4 7 13 14 15 16 10 6 3
*/

#include <iostream>
#include <cstring>
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


const int maxn = 1000005;
int edgemap[maxn][2];
int height = -1;          // 树的高度

// 标准一
void setEdgeMap1(Node* node, int h, int edgemap[][2])      // 类似于先序遍历
{
	if (node == NULL)
	{
		if (h > height)
			height = h;
		return ;
	}
	edgemap[h][0] = edgemap[h][0]==0? node->val : edgemap[h][0];
	edgemap[h][1] = node->val;
	setEdgeMap1(node->left, h+1, edgemap);
	setEdgeMap1(node->right, h+1, edgemap);
}

// 标准二
void setEdgeMap2Left(Node* node, int h, int edgemap[][2])      // 类似于先序遍历
{
	if (!node->left && !node->right)
		return ;
	edgemap[h][0] = node->val;
	if (node->left)
		setEdgeMap2Left(node->left, h+1, edgemap);
	else
		setEdgeMap2Left(node->right, h+1, edgemap);
}

void setEdgeMap2Right(Node* node, int h, int edgemap[][2])
{
	if (!node->left && !node->right)
		return ;
	edgemap[h][1] = node->val;
	if (node->right)
		setEdgeMap2Right(node->right, h+1, edgemap);
	else
		setEdgeMap2Right(node->left, h+1, edgemap);
}

// 打印叶子节点(不包括最左/右)
void printLeaf(Node* node, int h, int edgemap[][2])
{
	if (node == NULL)
		return ;
	if (!node->left && !node->right && edgemap[h][0] != node->val && edgemap[h][1] != node->val)
		cout << node->val << " ";
	printLeaf(node->left, h+1, edgemap);
	printLeaf(node->right, h+1, edgemap);
}


int main()
{
	Node *root = Construct();            // 构建二叉树
	memset(edgemap, 0, sizeof(edgemap));
	
	/* ----------------- 标准一 -------------------*/
	setEdgeMap1(root, 0, edgemap);       // 寻找边界点
	for (int i = 0; i < height; i++)     // 打印左边界点
		cout << edgemap[i][0] << " ";
	printLeaf(root, 0, edgemap);         // 打印叶子节点
	for (int i = height-1; i >= 0; i--)
		if (edgemap[i][0] != edgemap[i][1])     // 打印右边界点
			cout << edgemap[i][1] << " ";
	cout << endl;
	/* ----------------- 标准二 -------------------*/
	memset(edgemap, 0, sizeof(edgemap));
	setEdgeMap2Left(root, 0, edgemap);       // 构建左右两边
	setEdgeMap2Right(root, 0, edgemap);
	for (int i = 0; i < height; i++)
		if (edgemap[i][0] != 0)
			cout << edgemap[i][0] << " ";
	printLeaf(root, 0, edgemap);
	for (int i = height-1; i >= 0; i--)
		if (edgemap[i][0] != edgemap[i][1] && edgemap[i][1] != 0)
			cout << edgemap[i][1] << " ";
	return 0;
}
