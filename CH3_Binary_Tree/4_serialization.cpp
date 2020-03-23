#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int val;
	Node *left, *right;
};

Node* Construct()             // 构造二叉树
{
	// 输入格式: 节点个数+头结点编号
	// 每行对应当前节点的编号、左右儿子, 0表示是空节点
	int n, root_ind;
	cin >> n >> root_ind;         // 输入节点数和根节点
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
	if (root == NULL) {
		cout << "#!";
		return ;
	}
	cout << root->val << "!";
	PreOrder(root->left);
	PreOrder(root->right);
}

void LevelOrder(Node* root) {
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();
		if (temp == NULL)     // 确保后面的工作都不做
			cout << "#!";
		else {
			cout << temp->val << "!";
			q.push(temp->left);
			q.push(temp->right);
		}
	}
}

int main()
{
	Node *root = Construct();     // 构建二叉树
	PreOrder(root);
	cout << endl;
	LevelOrder(root);
	return 0;
}