#include "tree_node.h"
#include <vector>
using namespace std;


class Solution {
public:
    /**
    * 105. 从前序与中序遍历序列构造二叉树
    * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历，
    * inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
     */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder,0,preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
        int preStart, int preEnd, int inStart, int inEnd){
        if(preStart>preEnd){
            return nullptr;
        }

        TreeNode *node = new TreeNode(preorder[preStart]);
        int idx = findInInorder(inorder, preorder[preStart], inStart, inEnd);
        node->left = buildTree(preorder, inorder, preStart+1, preStart+(idx-inStart), inStart, idx-1);
        node->right = buildTree(preorder, inorder,preStart+(idx-inStart)+1, preEnd, idx+1,inEnd);

        return node;
    }

    int findInInorder(vector<int>& inorder, int target, int inStart, int inEnd){

        for(int i=inStart ; i <=inEnd; i++){
            if (inorder[i]==target){
                return i;
            }
        }
        return -1;// should not reach here
    }

    /**
    *  106. 从中序与后序遍历序列构造二叉树
    *  给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历，
    *  postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
    */
    TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(postorder, inorder,0,postorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* buildTree2(vector<int>& postorder, vector<int>& inorder,
        int postStart, int postEnd, int inStart, int inEnd){
        if(postStart>postEnd){
            return nullptr;
        }

        TreeNode *node = new TreeNode(postorder[postEnd]);
        int idx = findInInorder(inorder, postorder[postEnd], inStart, inEnd);
        node->left = buildTree2(postorder, inorder, postStart, postStart+(idx-inStart)-1, inStart, idx-1);
        node->right = buildTree2(postorder, inorder,postStart+(idx-inStart), postEnd-1, idx+1,inEnd);

        return node;
    }
};