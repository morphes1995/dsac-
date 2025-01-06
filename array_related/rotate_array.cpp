#include <vector>
#include <algorithm>
using namespace std;

/**
* 189. 轮转数组给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
    输入: nums = [1,2,3,4,5,6,7], k = 3
    输出: [5,6,7,1,2,3,4]
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k% nums.size(); // 防止k 大于 nums size的情况
        int start=0;
        int end=nums.size()-1;
        reverse(nums,start, end); // 反转全部

        reverse(nums,start, k-1);// 反转部分
        reverse(nums,k,end);// 反转部分
    }

    void reverse(vector<int>& nums, int i, int j){
        while(i<j){
            int tmp = nums[i];
            nums[i]=nums[j];
            nums[j] = tmp;

            i++;
            j--;
        }
    }
};