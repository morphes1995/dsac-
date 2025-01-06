#include "tree_node.h"
#include <algorithm>

/**
* 543. 二叉树的直径
* 给你一棵二叉树的根节点，返回该树的 直径 。
二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。
两节点之间路径的 长度 由它们之间边数表示。
 */
class Solution {
public:
    int maxLen =0;
    int diameterOfBinaryTree(TreeNode* root) {
        getDiameter(root);
        return maxLen;
    }

    int getDiameter(TreeNode *root){
        if(root==nullptr){
            return 0;
        }

        int leftLen =getDiameter(root->left);
        int rightLen = getDiameter(root->right);

        maxLen = maxLen > leftLen + rightLen ? maxLen : leftLen + rightLen;

        return  std::max(leftLen,rightLen)+1;
    }
};