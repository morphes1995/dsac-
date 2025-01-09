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
 * 剑指 Offer 22. 链表中倒数第k个节点
 * 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点
 *
 * 思路：快慢指针
 * 拓展：求链表的中间节点， 快指针一次走两步，慢指针一次走一步，遍历一次即可
 */

public ListNode getKthFromEnd(ListNode head, int k) {
    if(k<=0){
        return null;
    }

    int i=0;
    ListNode fast =head;
    while(fast!=null && i<k){
        fast =fast.next;
        i++;
    }
    if(i<k) return null; // 防止出现k 大于 链表节点个数的情况

    ListNode slow = head;
    while(fast!=null){
        fast =fast.next;
        slow =slow.next;
    }

    return slow;
}

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

