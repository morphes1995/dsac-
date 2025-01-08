//
// Created by aaab on 2025/1/2
#include "list_node.h"

/**
* 206. 反转链表
* 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
*/
class Solution {
    public:
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy = new ListNode();
        ListNode * curr = head;
        // 循环将curr节点插入到dummy.next的位置 （头插法）
        while (curr !=nullptr) {
            ListNode *next = curr->next; // 预先保存next指针
            curr->next = dummy->next;
            dummy->next = curr;

            curr = next;
        }

        return dummy->next;
    }

    /**
     * 递归解法:
    * 使用递归函数，一直递归到链表的最后一个结点，该结点就是反转后的头结点，记作 newHead
    * 此后，每次函数在返回的过程中，让当前结点（head）的下一个结点的 next 指针指向当前节点。
    * 同时让当前结点的 next 指针指向 NULL ，从而实现从链表尾部开始的局部反转
    * 当递归函数全部出栈后，链表反转完成。
     */
    ListNode* reverseList2(ListNode* head) {
        if(head ==nullptr || head->next == nullptr){
            return head;
        }

        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }

    /**
    * 25. K 个一组翻转链表
    * 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
    * k 是一个正整数，它的值小于或等于链表的长度
    * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
    */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 定位当前group的最后一个node
        ListNode *groupTail = head;
        int count =k-1;
        while(groupTail!=nullptr && count>0){
            groupTail = groupTail->next;
            count--;
        }

        if(groupTail==nullptr){
            return head;// 从head节点开始，剩下的节点数不足k个， 这些节点不进行reverse 直接返回
        }

        ListNode *newHead = groupTail->next;
        groupTail->next = nullptr; // 切断链表

        // reverse [head,groupTail]这部分链表， 反转后head是最后一个节点
        ListNode *res = reverse(head);

        
        head->next = reverseKGroup(newHead,k);

        return res;
    }
    ListNode* reverse(ListNode* head) {
        ListNode *dummy = new ListNode();
        ListNode *curr = head;
        while(curr != nullptr){
            ListNode *next = curr->next;
            curr->next = dummy->next;
            dummy->next = curr;

            curr = next;
        }

        return dummy->next;
    }
};

/**
 * 反转双向链表, 头插法
 */

ListNode2* reverseList3(ListNode2 *head) {
    //        if(head==null){
    //            return null;
    //        }

    ListNode2 *dummyNode = new ListNode2();
    ListNode2 *cur = head;

    while(cur!=nullptr){
        ListNode2 *next = cur->next;

        cur->next=dummyNode->next;
        if(dummyNode->next!=nullptr){
            dummyNode->next->before = cur;
        }

        dummyNode->next = cur;
        cur->before = dummyNode;

        cur =next;
    }
    return dummyNode->next;
}

/**
     * leetcode 92. 反转链表II
     * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
     * 思路： 整体采用头插法来反转指定区间的链表
     * @param head
     * @param left
     * @param right
     * @return
     */
public ListNode reverseBetween2(ListNode head, int left, int right) {
    ListNode dummy =new ListNode(0);
    dummy.next=head;
    ListNode pre =dummy;
    ListNode cur =pre.next;

    // cur 定位到left
    int i=1;
    for(;i<left;i++){
        pre=pre.next;
        cur=cur.next;
    }
    // 此时cur指向第left个节点， pre指向left的前一个节点
    ListNode reverseRear=cur;
    for(;i<=right;i++){// 头插进行翻转
        ListNode next = cur.next;

        cur.next=pre.next;
        pre.next=cur;
        cur=next;

    }
    // 此时cur指向 right+1
    // 翻转后的区间的最后一个节点的next 指向 第right+1个节点
    reverseRear.next=cur; // left个节点的next指向right+1个节点

    return dummy.next;
}

// int main() {
//     ListNode  *n1 = new ListNode(1);
//     ListNode  *n2 = new ListNode(2);
//     ListNode  *n3 = new ListNode(3);
//     n1->next = n2;
//     n2->next = n3;
//
//     Solution *s = new Solution();
//     ListNode *h2 = s->reverseList(n1);
//     printList(h2);
// }