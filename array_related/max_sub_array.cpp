#include <vector>
#include <stack>
using namespace std;

/**
* 53. 最大子数组和
* 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组
是数组中的一个连续部分。

/**
 * 剑指 Offer 42. 连续子数组的最大和
 * 输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值
 * 要求时间复杂度为O(n)。
 *
 * 思路: 求 max(f(i)) , 0<=i<=arr.length-1
 *  f(i) =  arr[i] , i=0 || f(i-1)<=0
 *  f(i) = arr[i]+f(i-1), i!=0 && f(i-1)>0
 *
 *
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