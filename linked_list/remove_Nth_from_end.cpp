#include "list_node.h"


/**
* 19. 删除链表的倒数第 N 个结点
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast =dummy;
        // fast 前进n个节点
        while(n>0 && fast !=nullptr){
            fast = fast->next;
            n--;
        }

        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        // fast到达最后一个节点时， slow指向要删除节点的前一个节点

        slow->next = slow->next->next;

        return dummy->next; 
    }
};

/**
 * 剑指offer 18 : O(1)时间内删除链表中的一个节点 (给定的节点 node 可能是链表中的最后一个节点)
 */
// 删除链表中给定值的第一个出现的节点
ListNode* deleteNode(ListNode *head, int val) {
    ListNode *dummyNode = new ListNode();
    dummyNode->next = head;

    ListNode *pre = dummyNode;
    ListNode *cur = pre->next;
    while(cur!=nullptr){
        if(cur->val==val){
            pre->next=cur->next;
            break;
        }
        pre=cur;
        cur=cur->next;
    }

    return dummyNode->next;
}

