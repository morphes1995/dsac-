#include <vector>
using namespace std;

/**
* 238. 除自身以外数组的乘积
* 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
请 不要使用除法，且在 O(n) 时间复杂度内完成此题。

    nums:                 2 ,      3,      4,       5
    res:               3x4x5     2x4x5   2x3x5    2x3x4
    left->right :       1         2       2x3      2x3x4
    right->left:      3x4x5      4x5       5         1


 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int leftPartProduct =1;
        int rightPartProduct =1;

        vector<int> res(nums.size());
        for(int i=0;i<nums.size();i++){
            res[i] =1;
        }



        for(int i=0;i<nums.size();i++){
            res[i] *= leftPartProduct;
            leftPartProduct *= nums[i];
        }

        for(int i=nums.size()-1;i>=0;i--){
            res[i] *= rightPartProduct;
            rightPartProduct *= nums[i];
        }

        return res;
    }
};