/*
2019-11.4
复制带有随机指针节点的链表
时间O(N),空间O(N)

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
        Node* cur = head;
        map<Node*, Node*> hash;
        while (cur)
        {
            hash[cur] = new Node();
            hash[cur]->val = cur->val;
            cur = cur->next;
        }
        cur = head;
        while (cur)
        {
            hash[cur]->next = hash[cur->next];       // hash[]不能掉,否则会接到原链表上!!
            hash[cur]->random = hash[cur->random];
            cur = cur->next;
        }
        return hash[head];
    }
};