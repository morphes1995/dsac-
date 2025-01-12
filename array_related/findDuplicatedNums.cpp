#include <vector>
using namespace std;

/**
 *  442. 数组中重复的数据
给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 内，且每个整数出现 最多两次 。
请你找出所有出现 两次 的整数，并以数组形式返回。
你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间（不包括存储输出所需的空间）的算法解决此问题。
 *
 *
* 使用正负号作为标记
思路与算法
我们首先对数组进行一次遍历。当遍历到位置 i 时，我们考虑 nums[nums[i]−1] 的正负性：
如果 nums[nums[i]−1] 是正数，说明 nums[i] 还没有出现过，我们将 nums[nums[i]−1] 加上负号；
如果 nums[nums[i]−1] 是负数，说明 nums[i] 已经出现过一次，我们将 nums[i] 放入答案。

细节
由于 nums[i] 本身可能已经为负数，因此在将 nums[i] 作为下标或者放入答案时，需要取绝对值。

 */
vector<int> findDuplicates(vector<int>& nums) {

    vector<int> res;

    for(int i=0;i<nums.size();i++){
        int val = nums[i];
        if(val<0){
            val *=-1; // nums[i] 设为负数后，就不能改回正数了，需要使用一个临时变量val= abs（nums[i]）来作为数组下标进行访问
        }
        if(nums[val-1] <0){
            res.push_back(val);
        }else{
            nums[val-1] *= -1;
        }
    }
    return res;

}