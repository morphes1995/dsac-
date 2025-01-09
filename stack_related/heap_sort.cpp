#include <locale>
#include <vector>
#include <queue>
using namespace std;


/**
* 912. 排序数组
你必须在 不使用任何内置函数 的情况下解决问题，时间复杂度为 O(nlog(n))，并且空间复杂度尽可能小。
 */
class Solution {
public:
    // heap sort
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(nums,i, n);
        }

        for(int i=0;i<n-1; i++){//只需交换n-1次即可
            swap(nums, 0, n-1-i);
            heapify(nums, 0, n-1-i);
        }

        return nums;
    }

    void heapify(vector<int> &heap, int parentIdx, int n){
        int leftChild = parentIdx*2+1;
        while(leftChild<n){
            int maxChild = leftChild;
            if(leftChild+1 < n && heap[leftChild+1] > heap[leftChild]){
                maxChild = leftChild+1;
            }

            if(heap[maxChild]>heap[parentIdx]){
                swap(heap, maxChild, parentIdx);
                parentIdx = maxChild;
                leftChild = parentIdx*2+1;
            }else{
                break;
            }
        }
    }
    void swap(vector<int> &heap, int i, int j){
        int temp = heap[i];
        heap[i] =heap[j];
        heap[j]=temp;
    }
};


/**
* 215. 数组中的第K个最大元素
    给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
    请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
    你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 */
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // 小根堆
        for(int i= 0;i<k;i++){
            pq.push(nums[i]);
        }

        for(int j= k;j<nums.size();j++){
            if(pq.top()< nums[j]){
                pq.pop();
                pq.push(nums[j]);
            }
        }

        return pq.top();
    }

    int findKthLargest2(vector<int>& nums, int k) {
        int heap[k];
        for(int i= 0;i<k;i++){
            heap[i] = nums[i];
        }

        buildHeap(heap,k);// 小根堆, 堆顶元素即为第k大的元素
        for(int j= k;j<nums.size();j++){
            if(heap[0]< nums[j]){
                heap[0] = nums[j];
                heapify(heap, k, 0);
            }
        }

        return heap[0];
    }
    void buildHeap(int heap[], int n){
        for(int i= n/2 -1; i>=0 ;i--){
            heapify(heap, n, i);
        }
    }

    void heapify(int *heap, int n, int parentIdx){
        int leftChild = parentIdx*2+1;
        while(leftChild<n){
            int minChild = leftChild;
            if(leftChild+1 < n && heap[leftChild+1] < heap[leftChild]){
                minChild = leftChild+1;
            }

            if(heap[minChild]<heap[parentIdx]){
                swap(heap, minChild, parentIdx);
                parentIdx = minChild;
                leftChild = parentIdx*2+1;
            }else{
                break;
            }
        }
    }

    void swap(int heap[], int i, int j){
        int temp = heap[i];
        heap[i] =heap[j];
        heap[j]=temp;
    }
};

/**
* 面试题 17.14. 最小K个数
 * 剑指 Offer 40. 数组中最小的k个数 (最小的第k个数，思路类似)
 * 输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4
 */

    // 基于 快排的 partition 函数， 循环直到随机选择的元素 在排序后，是位于数组的第k-1个为止
    // 此时 0~k-1个为 最小的k个元素
    public int[] getLeastNumbers(int[] arr, int k) {

        if(arr==null|| arr.length==0 || k==0){
            return new int[0];
        }

        int left =0;
        int right=arr.length-1;
        int randIdx = left + (int)(Math.random()*(right-left+1));

        int[] bounds = partition(arr,left,right,randIdx);

        while (k-1>bounds[1] || k-1<bounds[0]){

            if(k-1>bounds[1]){
                left = bounds[1]+1;
            }

            if(k-1<bounds[0]){
                right = bounds[0]-1;
            }
            randIdx = left + (int)(Math.random()*(right-left+1));
            bounds = partition(arr,left,right,randIdx);
        }

        int[] res = new int[k];
        for(int i=0;i<k;i++){
            res[i] = arr[i];
        }
        return res;

    }

    private int[] partition(int[] arr, int left, int right, int randIdx){

        int target = arr[randIdx];
        int i= left;

        int m=left;
        int n=right;

        while(i<=n){

            if(arr[i]==target){
                i++;
            }else if(arr[i]>target){
                swap(arr,i,n);
                n--;
            }else if(arr[i]<target){
                swap(arr,i,m);
                i++;
                m++;
            }
        }

        return new int[]{m,n};
    }
    private void swap(int[] nums,int i,int j){
        int tmp =nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
    }
