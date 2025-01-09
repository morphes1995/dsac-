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


 /**
* LCR 152. 验证二叉搜索树的后序遍历序列
 * 剑指 Offer 33. 二叉搜索树的后序遍历序列
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。
 * 假设输入的数组的任意两个数字都互不相同
 */
public boolean verifyPostorder(int[] postorder) {
    if(postorder==null){
        return false;
    }
    return verify(postorder,0,postorder.length-1);
}

private boolean verify(int[] postorder,int start,int end) {
    if(start>=end){
        return true;
    }
    int rootVal = postorder[end];
    int i = start;
    int j= end-1;
    while(i<=j){
        if(postorder[i]<rootVal){
            i++;
        }else if(postorder[j]>rootVal){
            j--;
        }else{
            return false; //不满足前部分元素值均小于后部分元素值
        }
    }
    // 此时满足前部分元素值均小于后部分元素值 ，j指向前半部分的最后一个， i指向右半部分的第一个
    return  verify(postorder,start,j) && verify(postorder,i,end-1);
}


/**
    *LCR 155. 将二叉搜索树转化为排序的双向链表
    将一个 二叉搜索树 就地转化为一个 已排序的双向循环链表

* 剑指 Offer 36. 二叉搜索树与双向链表
* 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的 循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
*/
class Node {
    public int val;
    public Node left;
    public Node right;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val,Node _left,Node _right) {
        val = _val;
        left = _left;
        right = _right;
    }
}


// 基于二叉排序树的迭代写法
public Node treeToDoublyList(Node root) {
    if(root==null){
        return null;
    }

    Node head =null;
    Node tail =null;

    LinkedList<Node> stack = new LinkedList<Node>();
    Node cur =root;
    while(!stack.isEmpty() || cur!=null){
        while(cur!=null){
            stack.addFirst(cur);
            cur=cur.left;
        }

        cur = stack.removeFirst();

        if(head==null){
            head = cur;
            tail =cur;
        }else{
            tail.right=cur;
            cur.left =tail;  // 尾插法构造双向链表
            tail =cur;
        }

        cur =cur.right;
    }

    tail.right =head;  // 连接双向链表的首尾
    head.left=tail;

    return head;
}


};