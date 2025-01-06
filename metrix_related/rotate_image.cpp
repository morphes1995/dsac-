#include <vector>
#include <stack>
using namespace std;

/**
* 48. 旋转图像
* 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 先沿着对角线反转
        int n = matrix.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix,i,j);
            }
        }

        // 然后将每一行反转
        for(int i=0;i<n;i++){
            reverseRow(matrix[i]);
        }
    }


    void reverseRow(vector<int> &row){
        int len= row.size();
        int i=0;
        int j=len-1;
        while(i<j){
            int tmp = row[i];
            row[i] =row[j];
            row[j]= tmp;
            i++;
            j--;
        }
    }
    void swap(vector<vector<int>> &matrix, int i, int j){
        int tmp = matrix[i][j];
        matrix[i][j]= matrix[j][i];
        matrix[j][i]= tmp;
    }
};