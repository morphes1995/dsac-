
/**
 * 冒泡排序 O(N*N)
 * 具有稳定性
 */
public void bubbleSort(int[] arr){

    if (arr==null || arr.length<2){
        return;
    }

    for (int i = 0; i <arr.length-1; i++) { // 总共循环len-1次
        for (int j = 0; j <arr.length-i-1 ; j++) { //每次从第0个元素开始， 每次循环后确定数组最后一个元素的值,因此 本次内循环 比前一次内循环 元素比较的次数减一
            if (arr[j]>arr[j+1]){
                NumberUtils.swap(arr,j,j+1);
            }
        }
    }
}

/**
 *
 * leetcode 912. 排序数组
 *
 *  堆： 本质上是一个完全二叉树， 数据可以存放在数组中
 *  不具有稳定性 时间复杂度O(N*logN) ,空间复杂度 O(1)
 *  leftChild = parent*2 +1;
 *  rightChild = parent*2+2;
 *  parent = (child-1)/2;
 *
 *  1. 构建堆的过程 (heapInsert or heapify )
 *     heapify的使用条件：    已知 arr[i+1:n]已经是一个大根堆， 通过heapify操作将第i个元素加入到该大根堆中 使之仍为一个大根堆
 *     heapInsert的使用条件： 已知 arr[0:i-1]已经是一个大根堆， 通过heapify操作将第i个元素加入到该大根堆中 使之仍为一个大根堆
 *
 *    heapInsert
 *    3  2  1
 *    |  |  |      O          |
 *    |  |        /\          |
 *    |  |       O O       |  |
 *    |         /\ /\      |  |
 *    |        O O O O  |  |  |
 *                      1  2  3
 *                       heapify
 *
 *  2. 调整堆的过程  heapify
 *
 */
vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    for(int i=n/2-1;i>=0;i--){// 从第一个非叶子节点开始调整
        heapify(nums,i, n);
    }

    for(int i=0;i<n; i++){
        // 将堆顶元素交换到数组后面
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

        if(heap[maxChild]>heap[parentIdx]){// 大根堆
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

/**
 *插入排序
 **/
public void insertionSort(int[] arr){
    if (arr==null || arr.length<2){
        return ;
    }

    for (int i = 0; i < arr.length; i++) {
        for (int j = i; j > 0 && arr[j-1]>arr[j] ; j--) {
            // 如果第j个元素前面还有元素 且  第j-1个元素（前面的元素）比第j个元素大，
            // 则交换j-1个元素与j个元素的位置； 同时继续向前比较
            NumberUtils.swap(arr,j-1,j);
        }
    }
}