#include <vector>
#include <stack>
using namespace std;

/**
* 240. 搜索二维矩阵 II
* 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
 */
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // 从矩阵的右上角开始遍历， 根据当前元素与target的关系来移动
    int row =0;
    int col = matrix[0].size()-1;
    while(row<=matrix.size()-1 && col>=0){

        if(matrix[row][col]==target){
            return true;
        }else if (matrix[row][col]<target){
            row ++;
        }else if (matrix[row][col]>target){
            col --;
        }
    }
    return false;
}

/**
*74. 搜索二维矩阵
*
*给你一个满足下述两条属性的 m x n 整数矩阵：

每行中的整数从左到右按非严格递增顺序排列。
每行的第一个整数大于前一行的最后一个整数。

使用与leetcode240一样的解法
*/