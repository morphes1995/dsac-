#include <vector>
using namespace std;

/**
 *
*283. 移动零
*给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
* 请注意 ，必须在不复制数组的情况下原地对数组进行操作。
*
* 双指针
思路及解法

使用双指针，左指针指向当前已经处理好的序列的尾部，右指针指向待处理序列的头部。
右指针不断向右移动，每次右指针指向非零数，则将左右指针对应的数交换，同时左指针右移。

注意到以下性质：
左指针左边均为非零数；
右指针左边直到左指针处均为零。
因此每次交换，都是将左指针的零与右指针的非零数交换，且非零数的相对顺序并未改变
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int left =0;

        for(int right=0;right<nums.size();right++){
            if(nums[right]!=0){
                swap(nums,left,right);
                left++;
                // 左指针左边均为非零数
            }
        }  
    }

    void swap(vector<int>& arr,int i,int j){
        if(i!=j){
            arr[i]=arr[i]^arr[j];
            arr[j]=arr[i]^arr[j];
            arr[i]=arr[i]^arr[j];
        }

    }

    /**
    * 27. 移除元素
    * 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。
    * 元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
    * 输入：nums = [3,2,2,3], val = 3
    输出：2, nums = [2,2,_,_]
     */
    int removeElement(vector<int>& nums, int val) {
        int left =0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]!=val){
                swap(nums,left,right);
                left++;
                // 左指针左边均为非零数
            }
        }
        return left;
    }
};