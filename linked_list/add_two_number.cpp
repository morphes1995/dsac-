#include "list_node.h"

/**
* 2. 两数相加
* 给你两个 非空 的链表，表示两个非负的整数。
* 它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
* 请你将两个数相加，并以相同形式返回一个表示和的链表。
* 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *tail = dummy; // 尾插法

        int carry =0 ;// 进位
        while(l1!=nullptr && l2!=nullptr){
            ListNode *node = new ListNode((l1->val+l2->val+carry)%10);
            tail->next = node;
            tail = node;

            carry = (l1->val+l2->val+carry)/10;

            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode *left = l1!=nullptr? l1:l2;
        while(left!=nullptr){
            ListNode *node = new ListNode((left->val+carry)%10);
            tail->next = node;
            tail = node;

            carry = (left->val+carry)/10;

            left = left->next;
        }

        if (carry>0){
            ListNode *node = new ListNode(carry);
            tail->next = node;
        }

        return dummy->next;
    }
};