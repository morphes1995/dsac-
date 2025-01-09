#include <vector>
#include <stack>
using namespace std;

/**
* 剑指 Offer 29. 顺时针打印矩阵 （螺旋矩阵）
* 54. 螺旋矩阵
* 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
*
* (start,start)         (start,colEnd)
*   x   x   x   x   x   x
*   x   y   y   y   y   x
*   x   y   z   z   y   x
*   x   y   y   y   y   x
*   x   x   x   x   x   x
* (rowEnd,start)       (rowEnd,colEnd)
*
*
*
 */
class Solution {
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()==0){
            return res;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        // 可以将矩阵看成若干层，首先输出最外层的元素，
        // 其次输出次外层的元素，直到输出最内层的元素。
        // 计算层数
        int cycle = (min(rows,cols)+1)/2;
        // 起点为(0,0), (1,1) ...
        for(int start = 0;start <cycle;start++){
            int rowEnd = rows -start-1;
            int colEnd =cols -start -1;

            for(int i = start;i<=colEnd;i++){
                res.push_back(matrix[start][i]);
            }

            if(start<rowEnd){
                for(int i = start+1; i<=rowEnd;i++){
                    res.push_back(matrix[i][colEnd]);
                }
            }

            if(start<rowEnd && start<colEnd){
                for(int i=colEnd-1;i>=start;i--){
                    res.push_back(matrix[rowEnd][i]);
                }
            }

            if(start<rowEnd-1 && start<colEnd){
                for(int i=rowEnd-1;i>start;i--){
                    res.push_back(matrix[i][start]);
                }
            }
        }
        return  res;

    }
};