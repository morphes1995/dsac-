#include "tree_node.h"
#include <vector>

class Solution {
public:
    /**
    * 226. 翻转二叉树
    * 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
     */
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        // 前序、后序均可
        invertTree(root->left);
        invertTree(root->right);

        TreeNode *tmp = root->left;
        root->left=root->right;
        root->right=tmp;

        // invertTree(root->left);
        // invertTree(root->right);

        return root;
    }

    /**
    *  2415. 反转二叉树的奇数层
    *  给你一棵 完美 二叉树的根节点 root ，请你反转这棵树中每个 奇数 层的节点值。
        例如，假设第 3 层的节点值是 [2,1,3,4,7,11,29,18] ，那么反转后它应该变成 [18,29,11,7,4,3,1,2] 。
        反转后，返回树的根节点。
        完美 二叉树需满足：二叉树的所有父节点都有两个子节点，且所有叶子节点都在同一层。
        节点的 层数 等于该节点到根节点之间的边数。

          0
      m       m
    x   Y   Y  x
   a b c d d c b a


     */
    TreeNode* reverseOddLevels(TreeNode* root) {
        reverse(root->left, root->right, 1);
        return root;
    }

    void reverse(TreeNode *left, TreeNode *right, int level){
        if(left==nullptr || right==nullptr){
            return;
        }

        if (level%2!=0){
            int tmpVal = left->val;
            left->val = right->val;
            right->val = tmpVal;
        }

        reverse(left->left, right->right,level+1);
        reverse(left->right, right->left,level+1);

    }

    /**
    * 101. 对称二叉树
    * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
     */
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr){
            return false;
        }
        return symmetric(root->left,root->right);
    }

    bool symmetric(TreeNode *left, TreeNode *right){
        if(left==nullptr && right==nullptr){
            return true;
        }
        if(left==nullptr || right==nullptr){
            return false;
        }

        if(left->val!=right->val){
            return false;
        }

        return symmetric(left->left,right->right) && symmetric(left->right,right->left);
    }
};