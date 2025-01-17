
#include "tree_node.h"
#include <vector>
using namespace std;

class Solution {
public:
    /**
    * 236. 二叉树的最近公共祖先
    给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
    百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
    所有 Node.val 互不相同 。
    p != q
    p 和 q 均存在于给定的二叉树中。
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr){
            return root;
        }

        if(root->val==p->val){
            return p;
        }
        if(root->val ==q->val){
            return q;
        }

        TreeNode *leftRes = lowestCommonAncestor(root->left,p,q);
        TreeNode *rightRes = lowestCommonAncestor(root->right,p,q);

        if(leftRes!=nullptr && rightRes!=nullptr){
            return root;
        }

        return leftRes!=nullptr? leftRes:rightRes;

    }
};