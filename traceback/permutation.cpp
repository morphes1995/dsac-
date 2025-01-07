#include <vector>
#include <list>
#include <set>
using namespace std;

/**
* # [**46. 全排列**](https://leetcode.cn/problems/permutations/)
给定一个**不含重复数字**的数组 `nums` ，返回其 *所有可能的全排列* 。你可以 **按任意顺序** 返回答案。
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>  res;
        doPermute(res,nums,0);
        return res;
    }

    void doPermute(vector<vector<int>> &res, vector<int>& nums, int startIdx){

        if(startIdx==nums.size()-1){
            vector<int> permutation;
            for(int i=0;i<nums.size();i++){
                permutation.push_back(nums[i]);
            }
            res.push_back(permutation);
            return;

        }
        // 考虑深度优先搜索所有排列方案。即通过字符交换，先固定第 1 位字符（ n种情况）、
        // 再固定第 2 位字符（n−1 种情况）、... 、最后固定第 n-1 位字符
        //eg vector = 1,2,3
        // 1 <-> 1 2 <-> 2
        //         2 <-> 3
        // 1 <-> 2 2 <-> 2
        //         2 <-> 3
        // 1 <-> 3 2 <-> 2
        //         2 <-> 3
        // 固定startIdx之前的元素
        for(int i=startIdx;i<nums.size();i++){
            swap(nums,i,startIdx);
            doPermute(res,nums,startIdx+1);
            swap(nums,i,startIdx);
        }
    }

    void swap(vector<int> &nums,int i,int j){
        int tmp = nums[i];
        nums[i]=nums[j];
        nums[j]= tmp;
    }


    /**
    * 47. 全排列 II
    * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
    */
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>  res;
        permute2(res, nums, 0);
        return res;
    }

    void permute2(vector<vector<int>>  &res, vector<int> &nums, int startIdx){
        if(startIdx==nums.size()-1){
            vector<int> permutation;
            for(int val: nums){
                permutation.push_back(val);
            }
            res.push_back(permutation);
            return;
        }
        /*
        vector<bool> visited(21);// 处理nums[startIdx:]时， 记录-10～10 这21个字符哪个访问过了
        for(int i=startIdx;i<nums.size();i++){
            if(visited[nums[i]+10]){
                continue;
            }

            visited[nums[i]+10] = true;
            swap(nums,startIdx, i);
            permute(res, nums, startIdx+1);
            swap(nums,startIdx, i);
        }*/

        //  1   1   2  1
        //  对于 nums[0] nums[1] nums[3], 不需要交换，交换了会产生重复组合
        set<int> visited;
        for(int i=startIdx;i<nums.size();i++){
            if(visited.count(nums[i])){
                continue;
            }
            visited.insert(nums[i]);

            swap(nums,startIdx, i);
            permute2(res, nums, startIdx+1);
            swap(nums,startIdx, i);
        }
    }



};