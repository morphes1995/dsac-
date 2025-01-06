#include "tree_node.h"
#include <algorithm>
#include <vector>

class Solution {
public:
    /**
    * 104. 二叉树的最大深度
    * 二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
     */
    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }

        return std::max(maxDepth(root->left),maxDepth(root->right))+1;
        // int leftDepth = maxDepth(root->left);
        // int rightDepth = maxDepth(root->right);
        // int maxDepth = leftDepth>rightDepth?leftDepth:rightDepth;
        // return maxDepth+1;
    }

    /**
    * 111. 二叉树的最小深度
    * 给定一个二叉树，找出其最小深度。
    * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
    * 说明：叶子节点是指没有子节点的节点。
     */
    int minDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }

        if(root->left==nullptr && root->right==nullptr){
            return 1;
        }

        if(root->left==nullptr){
            return minDepth(root->right)+1;
        }else if(root->right==nullptr){
            return minDepth(root->left)+1;
        }else{
            return std::min(minDepth(root->left),minDepth(root->right))+1;
        }


    }
};

class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution2 {
public:
    /**
    * 559. N 叉树的最大深度
        给定一个 N 叉树，找到其最大深度。
        最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
        N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）
     */
    int maxDepth(Node* root) {

        if(root==nullptr){
            return 0;
        }
        int maxChildDepth =0;
        for(Node *child:root->children){
            int depth = maxDepth(child);
            maxChildDepth = std::max(depth,maxChildDepth);
        }
        return maxChildDepth+1;
    }
};