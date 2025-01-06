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