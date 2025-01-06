#include <vector>
#include <stack>
using namespace std;

/**
* 53. 最大子数组和
* 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组
是数组中的一个连续部分。
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum =INT_MIN;
        int curSum =0;

        for(int i=0;i<nums.size();i++){

            if(curSum<0){
                curSum=0;
            }
            curSum += nums[i];

            maxSum = curSum>maxSum? curSum:maxSum;
        }

        return maxSum;
    }
};