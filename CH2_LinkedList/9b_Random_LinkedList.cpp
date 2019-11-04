/*
2019-11.4
复制带有随机指针节点的链表
时间O(N),空间O(1)
注意LeetCode有输入为空的Bug
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        Node* cur = head;
        while (cur)
        {
            Node* node = new Node(cur->val);
            node->next = cur->next;
            cur->next = node;
            cur = cur->next->next;
        }
        
        cur = head;
        Node* cur2 = NULL;
        while (cur)                     // Random的修改
        {
            cur2 = cur->next;                // 注意步骤不能反
            cur2->random = cur->random==NULL ? NULL : cur->random->next;
            cur = cur->next->next;
        }
        
        cur2 = head->next;
        // cur = NULL;
        Node* hhead = head;
        while (hhead->next)
        {
            cur = hhead->next;
            hhead->next = cur->next;            // head->cur->...
            hhead = cur;
            // cur = cur->next;
        }
        return cur2;
    }
};