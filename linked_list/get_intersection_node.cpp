#include <locale>

#include "list_node.h"


/**
* 160. 相交链表
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
如果两个链表不存在相交节点，返回 null
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        ListNode *currA = headA;
        while(currA!=nullptr){
            lenA ++;
            currA = currA->next;
        }

        int lenB= 0;
        ListNode *currB = headB;
        while(currB!=nullptr){
            lenB ++;
            currB = currB->next;
        }

        if (lenA > lenB){
            int delta = lenA - lenB;
            while(delta>0){
                headA = headA->next;
                delta--;
            }
        }else{
            int delta = lenB - lenA;
            while(delta>0){
                headB = headB->next;
                delta--;
            }
        }

        while(headA != headB){
            headA = headA->next;
            headB= headB->next;
        }

        return headA;
    }
};
