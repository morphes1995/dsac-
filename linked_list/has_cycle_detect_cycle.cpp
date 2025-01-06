#include "list_node.h"

/**
* 141. 环形链表
给你一个链表的头节点 head ，判断链表中是否有环。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 快慢指针
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow==fast){
                return true;
            }
        }
        return false;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast){
                // 当发现 slow 与 fast 相遇时，
                // 我们再额外使用一个指针 start2。起始，它指向链表头部；
                // 随后，它和 slow 每次向后移动一个位置。最终，它们会在入环点相遇
                ListNode *start1 = slow;
                ListNode *start2 = head;
                while(start1 != start2){
                    start1=start1->next;
                    start2=start2->next;
                }
                return start1;
            }
        }
        return nullptr;
    }
};