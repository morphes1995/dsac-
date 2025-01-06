#include <vector>
#include <list>
#include <string>
using namespace std;


/**
* 79. 单词搜索
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
如果 word 存在于网格中，返回 true ；否则，返回 false 。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，
其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 */
class Solution {
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i=0;i<rows;i++){
            for(int j =0;j<cols;j++){
                if (exist(board,word,0,i,j,rows-1,cols-1)){
                    return true;
                }
            }
        }
        return false;

    }

    bool exist(vector<vector<char>>& board, string word,int cur,int row,int col,int rows,int cols) {

        if(cur==word.length()){
            return true;
        }

        bool exist =false;
        if(row<=rows && row>=0 && col <= cols && col>=0
           &&  word[cur] == board[row][col]
        ){

            board[row][col] =  (char)(board[row][col] + 200);// 标记已访问
            cur++;
            // 继续朝着四个方向寻找Word的下一个字符
            exist = exist(board,word,cur,row+1,col,rows,cols) ||
                    exist(board,word,cur,row-1,col,rows,cols) ||
                    exist(board,word,cur,row,col+1,rows,cols) ||
                    exist(board,word,cur,row,col-1,rows,cols) ;

            board[row][col] -=  200;// 恢复为未访问

        }
        return exist;
    }
};