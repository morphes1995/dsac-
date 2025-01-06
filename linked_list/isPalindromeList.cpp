//
// Created by aaab on 2025/1/3.
//
#include "list_node.h"

/**
* 234. 回文链表
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表.
如果是，返回 true ；否则，返回 false 。
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //定位到中间节点
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        // 1. slow 指向 链表的后半部分
        // 1 2 2 1
        //     s
        // 1 2 3 2 1
        //     s

        // 2. reverse 链表的后半部分
        ListNode *head2 = reverse(slow);

        // 3. 前半部分和reverse后的后半部分进行逐个比较
        while(head!=nullptr && head2!=nullptr){
            if(head->val != head2->val){
                return false;
            }
            head = head->next;
            head2= head2->next;
        }

        return true;
    }

    ListNode * reverse(ListNode *head){
        ListNode *dummy = new ListNode();
        ListNode *curr = head;
        while(curr!=nullptr){
            ListNode *next = curr->next;
            curr->next = dummy->next;
            dummy->next=curr;

            curr = next;
        }
        return dummy->next;
    }
};