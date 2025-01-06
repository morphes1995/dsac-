#include "tree_node.h"
#include <vector>
#include "../linked_list/list_node.h"
using namespace std;


class Solution {
public:
    /**
    * 108. 将有序数组转换为二叉搜索树
    * 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 平衡二叉搜索树。
     */
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums,0, nums.size()-1);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        if(end< start){
            return nullptr;
        }
        int mid = (start+end)/2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBST(nums,start, mid-1);
        node->right = sortedArrayToBST(nums,mid+1, end);

        return node;
    }

    /**
    * 109. 有序链表转换二叉搜索树
    * 给定一个单链表的头节点  head ，其中的元素 按升序排序 ，将其转换为 平衡二叉搜索树。
     */
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr) {
            return nullptr;
        }
        if(head->next==nullptr){ // 对于本段链表只有一个节点的场景，直接创建一个TreeNode (叶子节点)并返回即可
            return new TreeNode(head->val);
        }
        ListNode *mid = findMidNode(head);
        TreeNode *node = new TreeNode(mid->val);

        node->left=sortedListToBST(head);
        node->right=sortedListToBST(mid->next);
        return node;
    }

    // 要确保 head->next != null
    ListNode* findMidNode(ListNode *head){
        // 以head为起始结点的链表至少有两个节点
        // 所以在初始化slow，fast时可以提前一步
        ListNode* pre = head;
        ListNode* slow= head->next;
        ListNode* fast=head->next->next;
        while(fast!=nullptr && fast->next!=nullptr){
            pre = slow;
            slow = slow->next;
            fast= fast->next->next;
        }
        pre->next = nullptr; // 断开链表， 此时slow是链表后半部分的头结点

        return slow;
    }


};