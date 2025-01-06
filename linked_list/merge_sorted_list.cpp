#include "list_node.h"
#include <vector>
#include <queue>
class Solution {
public:
    class NodeItem {
    public:NodeItem(ListNode *node):node(node){}
        ListNode *node;
        // 注意参数为常引用，返回值也为const
        bool operator < (const NodeItem &another) const{
            if (node->val < another.node->val){
                return false; // 从小到大排序
            }
            return  true;
        }
    };

    /**
    * 21. 合并两个有序链表
    * 将两个升序链表合并为一个新的 升序 链表并返回
    * 新链表是通过拼接给定的两个链表的所有节点组成的。
    */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode();
        ListNode *tail = dummy; // 尾插法

        while(list1!=nullptr && list2 != nullptr){
            if (list1->val < list2->val){
                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            }else{
                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }
        }

        // 处理链表长度不一致的情况
        if (list1!=nullptr){
            tail->next = list1;
        }
        if (list2!=nullptr){
            tail->next = list2;
        }

        return dummy->next;    
    }

    /**
    *23. 合并 K 个升序链表
    *给你一个链表数组，每个链表都已经按升序排列。
    *请你将所有链表合并到一个升序链表中，返回合并后的链表。
     *
     * 维护当前每个链表没有被合并的元素的最前面一个，
     * k 个链表就最多有 k 个满足这样条件的元素，每次在这些元素里面选取 val 属性最小的元素合并到答案中。
     * 在选取最小元素的时候，我们可以用优先队列来优化这个过程。
     */
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // 参数类型不能为指针
        std::priority_queue<NodeItem> pq;
        for(ListNode* node : lists){
            if (node != nullptr){
                pq.push({node});
            }
        }

        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;

        while(!pq.empty()){
            NodeItem n = pq.top();
            pq.pop();
            //尾插
            tail->next = n.node;
            tail = n.node;

            if (n.node->next != nullptr){
                pq.push(NodeItem(n.node->next));
            }
        }

        return dummy->next;

    }
};

// int main() {
//     ListNode *a2 = new ListNode(3);
//     ListNode *a1 = new ListNode(1,a2);
//
//     ListNode *b2 = new ListNode(2);
//     ListNode *b1 = new ListNode(1, b2);
//
//     Solution *s = new Solution();
//     std::vector<ListNode*>  lists;
//     lists.push_back(a1);
//     lists.push_back(b1);
//
//     ListNode *res = s->mergeKLists(lists);
//     printList(res);
//
// }