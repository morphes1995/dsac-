#include "tree_node.h"
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
    * 112. 路径总和
    * 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。
    * 判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。
    * 如果存在，返回 true ；否则，返回 false 。

叶子节点 是指没有子节点的节点。
     */
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){
            return false;
        }
        if(root->left==nullptr && root->right==nullptr){
            return targetSum-root->val==0;
        }

        // 前序遍历
        return hasPathSum(root->left,targetSum-root->val)|| hasPathSum(root->right,targetSum-root->val);
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        list<int> currPath;
        traverse(root, targetSum, res, currPath);
        return res;
    }

    /**
*     剑指 Offer 34. 二叉树中和为某一值的路径
    * 113. 路径总和 II
    * 给你二叉树的根节点 root 和一个整数目标和 targetSum ，
    * 找出 所有 从根节点到叶子节点 路径总和等于给定目标和的路径。叶子节点 是指没有子节点的节点。
     */
    void traverse(TreeNode* root, int targetSum, vector<vector<int>> &res, list<int> &currPath){
        if(root==nullptr){
            return;
        }

        currPath.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            if (targetSum==root->val){
                vector<int> pathFound;
                pathFound.reserve(currPath.size());
                for(int val:currPath){
                    pathFound.push_back(val);
                }
                res.push_back(pathFound);
            }
            currPath.pop_back();
            return;
        }

        traverse(root->left, targetSum-root->val, res, currPath);
        traverse(root->right, targetSum-root->val, res, currPath);
        currPath.pop_back();
    }

    /**
    * 437. 路径总和 III
    * 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
    * 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
    *
    * 前缀和定义
    一个节点的前缀和就是该节点到根之间的路径和。

    拿下图解释：
    节点4的前缀和为：1 + 2 + 4 = 7
    节点8的前缀和：1 + 2 + 4 + 8 = 15
    节点9的前缀和：1 + 2 + 5 + 9 = 17

          1
         /  \
        2    3
       / \    \
      4   5    6
     / \   \
    7   8   9

    题目要求的是找出路径和等于给定数值 的路径总数, 而:
    两节点间的路径和 = 两节点的前缀和之差

    我们只用遍历整颗树一次，记录每个节点的前缀和，并查询该节点的祖先节点中符合条件的个数，将这个数量加到最终结果上。

HashMap的key是前缀和， value是该前缀和的节点数量，记录数量是因为有出现复数路径的可能。
下图树中，前缀和为1的节点有两个: 1, 0
所以路径和为2的路径数就有两条: 0 --> 2, 2

      1
     /
    0
   /
  2
     */
    unordered_map<long, int> prefix;
    int pathSum3(TreeNode* root, int targetSum) {
        prefix[0] =1;
        return traverse3(root, 0, targetSum);
    }

    int traverse3(TreeNode* root, long cur, int targetSum){
        if(root==nullptr) return 0;

        cur = cur+root->val;
        int ret =0;
        if(prefix.count(cur-targetSum)>0){
            ret = prefix[cur-targetSum]; // 如果key不存在，默认值为0
        }


        prefix[cur]++;
        ret += traverse3(root->left, cur,targetSum);
        ret += traverse3(root->right, cur,targetSum);
        prefix[cur]--;
        if (prefix[cur]==0){
            prefix.erase(cur);
        }
        return ret;
    }

    /**
    * 124. 二叉树中的最大路径和
    * 二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。
    * 同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
    * 路径和 是路径中各节点值的总和。
    给你一个二叉树的根节点 root ，返回其 最大路径和 。
     */
    int maxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        doMaxPathSum(root);
        return maxSum;

    }
    int doMaxPathSum(TreeNode *root){
        if(root==nullptr){
            return 0;
        }
        int leftVal = doMaxPathSum(root->left);
        int rightVal = doMaxPathSum(root->right);

        int sumTmp = leftVal+rightVal+root->val;

        maxSum = sumTmp > maxSum? sumTmp : maxSum;

        int childMax = leftVal>rightVal? leftVal:rightVal;

        return childMax+root->val >0 ? childMax+root->val:0;
    }

};