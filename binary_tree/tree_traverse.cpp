#include "tree_node.h"
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    /**
    * 94. 二叉树的中序遍历
    * 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
     */
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;
        TreeNode * curr = root;
        while(!stack.empty() || curr!=nullptr){
            if(curr != nullptr){
                stack.push(curr);
                curr = curr->left;
                continue;
            }

            curr = stack.top();
            stack.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }

        return res;
    }

    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> res;
        doInorderTraverse(root, res);
        return res;
    }

    void doInorderTraverse(TreeNode* root, vector<int> &res) {
        if (root==nullptr){
            return;
        }

        doInorderTraverse(root->left, res);
        res.push_back(root->val);
        doInorderTraverse(root->right, res);
    }

    /**
    * 98. 验证二叉搜索树(二叉搜索树的中序遍历序列是递增的)
    * 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
      有效 二叉搜索树定义如下：
        节点的左
        子树
        只包含 小于 当前节点的数。
        节点的右子树只包含 大于 当前节点的数。
        所有左子树和右子树自身必须也是二叉搜索树。
     */
    bool isValidBST(TreeNode* root) {
        bool initialized = false;
        int prevVal = 0;
        stack<TreeNode*> stack;
        TreeNode * curr = root;
        while(!stack.empty() || curr!=nullptr){
            while(curr != nullptr){
                stack.push(curr);
                curr = curr->left;
                continue;
            }

            curr = stack.top();
            stack.pop();

            if(!initialized){
                initialized=true;
                prevVal = curr->val;
            }else if (curr->val<= prevVal){
                return false;
            }else{
                prevVal = curr->val;
            }
            curr = curr->right;
        }

        return true;
    }

    /**
    * 501. 二叉搜索树中的众数
    * 给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
    * 如果树中有不止一个众数，可以按 任意顺序 返回。
    假定 BST 满足如下定义：
    结点左子树中所含节点的值 小于等于 当前节点的值
    结点右子树中所含节点的值 大于等于 当前节点的值
    左子树和右子树都是二叉搜索树
     */
    vector<int> findMode(TreeNode* root) {
        vector<int> nums;
        int maxFreq =0;
        int freq =0;
        stack<TreeNode*> stack;

        TreeNode *pre= nullptr;
        TreeNode *cur=root;
        while(!stack.empty() || cur!=nullptr){
            if(cur!=nullptr){
                stack.push(cur);
                cur=cur->left;
                continue;
            }
            cur=stack.top();
            stack.pop();

            if(pre!=nullptr && pre->val==cur->val ){
                freq++;
            }else{
                freq=1;
            }
            if(freq>maxFreq){
                nums.clear();
                nums.push_back(cur->val);
                maxFreq=freq;
            }else if(freq==maxFreq){
                nums.push_back(cur->val);
            }

            pre=cur;

            cur=cur->right;
        }

        return nums;
    }

    /**
    * 230. 二叉搜索树中第 K 小的元素
    * 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（从 1 开始计数）。
     */
    int kthSmallest(TreeNode* root, int k) {
        int cursor=1;
        stack<TreeNode*> stack;
        TreeNode *curr = root;
        while(!stack.empty() || curr!=nullptr){
            if(curr != nullptr){
                stack.push(curr);
                curr = curr->left;
                continue;
            }

            curr = stack.top();
            stack.pop();

            if(cursor==k){
                return curr->val;
            }
            cursor++;

            curr = curr->right;
        }
        // should not arrive here
        return -1;
    }

    /**
    * 144. 二叉树的前序遍历
    *  给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
    */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> stack;
        if (root!=nullptr){
            stack.push(root);
        }

        while(!stack.empty()){
            TreeNode *node = stack.top();
            stack.pop();

            res.push_back(node->val);
            // 先右后左
            if(node->right!=nullptr){
                stack.push(node->right);
            }
            if(node->left!=nullptr){
                stack.push(node->left);
            }
        }
        return res;
    }

    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int> res;
        doPreOrderTraversal(root, res);

        return res;
    }

    void doPreOrderTraversal(TreeNode *root, vector<int> &res){
        if(root==nullptr){
            return;
        }

        res.push_back(root->val);
        doPreOrderTraversal(root->left, res);
        doPreOrderTraversal(root->right, res);
    }

    /**
    * 114. 二叉树展开为链表
    * 给你二叉树的根结点 root ，请你将它展开为一个单链表：
    展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
    展开后的单链表应该与二叉树 先序遍历 顺序相同。
     */
    void flatten(TreeNode* root) {
        stack<TreeNode*> stack;
        if(root!=nullptr){
            stack.push(root);
        }

        TreeNode *tail=nullptr;// 当前链表的尾结点

        while(!stack.empty()){
            TreeNode *node = stack.top();
            stack.pop();

            if(tail==nullptr){
                tail=node;
            }else{
                // 尾插法
                tail->right = node;
                tail->left= nullptr;
                tail = node;
            }
            if(node->right!=nullptr){
                stack.push(node->right);
            }
            if(node->left!=nullptr){
                stack.push(node->left);
            }
        }

    }

    /**
    * 145. 二叉树的后序遍历
    * 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
    */
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        // 双stack 来实现
        stack<TreeNode *> s;
        stack<TreeNode *> tmpRes;
        if(root!=nullptr){
            s.push(root);
        }

        while(!s.empty()){
            TreeNode *node = s.top();
            s.pop();
            tmpRes.push(node); // 加入临时结果中

            // 先左后右
            if(node->left!=nullptr){
                s.push(node->left);
            }
            if(node->right!=nullptr){
                s.push(node->right);
            }
        }
        // tmpRes的push 序列反转， 即为最终遍历序列
        while(!tmpRes.empty()){
            res.push_back(tmpRes.top()->val);
            tmpRes.pop();
        }

        return res;
    }

    vector<int> postorderTraversal2(TreeNode* root) {
        vector<int> res;
        doPostOrderTraversal(root, res);
        return res;

    }
    void doPostOrderTraversal(TreeNode *root, vector<int> &res){
        if(root==nullptr){
            return;
        }
        doPostOrderTraversal(root->left, res);
        doPostOrderTraversal(root->right, res);
        res.push_back(root->val);
    }

    /**
    * 102. 二叉树的层序遍历
    * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if(root!=nullptr){
            q.push(root);
        }

        while(!q.empty()){
            int levelSize = q.size();
            vector<int> levelValues;
            levelValues.reserve(levelSize);
            while(levelSize>0){
                TreeNode *node = q.front();
                q.pop();
                levelValues.push_back(node->val);

                if(node->left!=nullptr){
                    q.push(node->left);
                }
                if(node->right!=nullptr){
                    q.push(node->right);
                }
                levelSize --;
            }

            res.push_back(levelValues);
        }

        return res;
    }

    /**
    * 199. 二叉树的右视图
            给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
     */
    // 层序遍历
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode *> q;
        if(root!=nullptr){
            q.push(root);
        }

        while(!q.empty()){
            int levelSize = q.size();
            vector<int> levelValues;
            while(levelSize>0){
                TreeNode *node = q.front();
                q.pop();

                // 仅保存每一层最右侧的节点
                if(levelSize==1){
                    res.push_back(node->val);
                }

                if(node->left!=nullptr){
                    q.push(node->left);
                }
                if(node->right!=nullptr){
                    q.push(node->right);
                }
                levelSize --;
            }
        }

        return res;

    }
    vector<int> rightSideView2(TreeNode* root) {
        vector<int> res;
        dfs(root,res, 1);
        return res;
    }

    void dfs(TreeNode *node, vector<int> &res, int level){
        if(node==nullptr)
            return;

        if(res.size()<level){
            res.push_back(node->val);
        }
        // 先右后左
        dfs(node->right, res, level+1);
        dfs(node->left, res, level+1);
    }
};