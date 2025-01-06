#include "list_node.h"

/**
* 24. 两两交换链表中的节点
* 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
* 你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        ListNode *dummy = new ListNode();
        dummy->next= head;

        // 需要pre，cur，next 三个指针
        ListNode *pre = dummy;
        ListNode *cur = pre->next;
        while(cur!=nullptr && cur->next !=nullptr){
            ListNode *next = cur->next;

            pre->next = next;
            cur->next = next->next;
            next->next = cur; //  next->next要提前保存好

            // cur->next = next->next;
            // next->next = cur; //  next->next要提前保存好
            // pre->next = next;

            pre = cur;
            cur = cur->next;
        }

        return dummy->next;

    }
};