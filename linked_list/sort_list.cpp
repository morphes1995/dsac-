#include "list_node.h"

/**
* 148. 排序链表
* 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
*/
class Solution {
public:
    // merge sort 解法
    ListNode* sortList(ListNode* head) {
        if (head ==nullptr || head->next ==nullptr){
            return head;
        }
        // 快慢指针定位中间节点
        // node   node
        //  s
        // node node node
        //       s

        ListNode *slow = head;
        ListNode *fast =head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow = slow->next;
            fast= fast->next->next;
        }
        // 此时s指向中间节点
        ListNode *rightHead = slow->next;
        slow->next = nullptr;
        
        ListNode *leftPart = sortList(head);
        ListNode *rightPart = sortList(rightHead);
        // leetcode 21
        return mergeSortList(leftPart, rightPart);
    }

    ListNode* mergeSortList(ListNode* head1, ListNode* head2){
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while(head1!=nullptr && head2!=nullptr){
            if(head1->val< head2->val){
                tail->next = head1;
                tail = tail->next;
                head1 = head1->next;
            }else{
                tail->next = head2;
                tail = tail->next;
                head2 = head2->next;
            }
        }

        ListNode *left = head1!=nullptr? head1:head2;
        tail->next = left;

        return dummy->next;
    }
};

/**
 * leetcode 147. 对链表进行插入排序
 */
public ListNode insertionSortList(ListNode head) {
    if(head==null){
        return head;
    }

    ListNode newDummyNode = new ListNode();

    ListNode dummyNode = new ListNode();
    dummyNode.next= head;
    ListNode pre = dummyNode;

    ListNode curr = head;
    while(curr!=null){ // 对于每个节点都要进行比较，并插入，性能差
        ListNode next = curr.next;
        pre.next =next;
        curr.next =null;
        insert(newDummyNode,curr);

        curr = next;
    }

    return newDummyNode.next;
}

private void insert(ListNode head, ListNode node){

    ListNode pre = head;
    ListNode cur = head.next;

    while(cur!=null){
        if(cur.val>node.val){
            pre.next=node;
            node.next=cur;
            break;
        }
        pre =cur;
        cur = cur.next;
    }

    if(cur==null){
        pre.next = node;
    }
}

// int main() {
//     ListNode n4(4);
//     ListNode n3(3,&n4);
//     ListNode n2(2,&n3);
//     ListNode n1(1,&n2);
//
//     Solution *s = new Solution();
//     ListNode *res = s->sortList(&n1);
//     printList(res);
//
// }