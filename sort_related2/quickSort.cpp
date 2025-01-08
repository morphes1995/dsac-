#include <algorithm>
#include <vector>

using namespace std;

/**
* * leetcode 912. 排序数组
 *
 * V1,V2 最坏时间复杂度 O(N*N) ,eg: 数组是从小到大的， 要求从大到小排序
 * V3 没有最坏时间复杂度， 整体是一个O(N*logN)的实际复杂度 ; 递归使用的额外空间复杂度 O(logN)
 * 不具有稳定性
 *
 */

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        if(nums.size()<=1){
            return nums;
        }

        doQuickSort(nums, 0,nums.size()-1);
        return nums;
    }

    void doQuickSort(vector<int>&nums, int left, int right){
        // 每次函数调用确定target在排好序的数组中的最终位置
        if(right>left){ // 当该部分大于1个元素时才可以继续对该部分排序，只有一个元素时，该部分已经是排好序的了
            // 从left~right中随机抽取一个数作为target,避免最坏情况的O(N*N) 时间复杂度
            int randIdx = left+ (int)((double)rand()/RAND_MAX)*(right-left);
            vector<int > bounds= partition(nums,left, right, randIdx);
            doQuickSort(nums,left,bounds[0]-1);
            doQuickSort(nums,bounds[1]+1, right);
        }

    }
    /**
     **
     * 该M方法将 left~ right分为三部分，[left,m） :  小于target的部分；
     *                              [m,n]     :  等于target的部分；
     *                              (n,right] :  大于target的部分
     * 返回 等于target部分的左边界和右边界
     * @param arr
     * @param left
     * @param right
     * @param randIdx
     * @return
     */
    vector<int> partition(vector<int>&nums, int left, int right, int randIdx){
        int target=nums[randIdx];
        int i=left;
        int m=left;
        int n=right;

        while(i<=n){

            if(nums[i]==target){
                i++;
            }else if(nums[i]>target){
                swap(nums,i,n);
                n--;
            }else{
                swap(nums,i,m);
                m++;
                i++;
            }
        }

        vector<int> res={m,n};
        return res;

    }

    void swap(vector<int> &heap, int i, int j){
        int temp = heap[i];
        heap[i] =heap[j];
        heap[j]=temp;
    }
};