// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

/**
* 138. 随机链表的复制
给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random
该指针可以指向链表中的任何节点或空节点。
构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。
新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，
并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。
返回复制链表的头节点。
 */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return head;
        }

        // 1. 构造链表 node1-> copy1->node2 ->copy2...
        Node *curr = head;
        while(curr != nullptr){
            Node *copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }
        // 2. 填充copy节点的random指针
        curr = head;
        while(curr!=nullptr){
            Node *copy = curr->next;
            copy->random = curr->random==nullptr? nullptr: curr->random->next;
            curr = copy->next;
        }

        // 3. 链表分离
        // node1-> copy1->node2 ->copy2...
        // to
        // node1->node2 ...
        // copy1->copy2 ...
        curr = head;
        Node *copyHead = curr->next;
        while(curr!=nullptr && curr->next!=nullptr){
            Node *next = curr->next;
            curr->next = next->next;
            curr = next;
        }

        return copyHead;

    }
};