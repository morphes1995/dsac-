#include <vector>
#include <list>
#include <string>
using namespace std;

/**
*22. 括号生成
*数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
*  eg n=2
*                start
*                /    \
*               (
*            /      \
*           (         )
*          / \       / \
*             )     (
*            / \   / \
*              )  )
*/
class Solution {
public:
    list<string> generateParenthesis(int n) {
        list<string> res;
        dfs(res,n,n,"");
        return res;
    }

    void dfs( List<String> res, int left,int right,String curStr){
        if(left==0 && right==0){
            res.add(curStr);
            return;
        }

        // 如果左括号数量不大于 n，我们可以放一个左括号
        if(left>0){
            dfs(res,left-1,right,curStr+"(");
        }

        //如果右括号数量小于左括号的数量，我们可以放一个右括号。
        if(left<right){
            dfs(res,left,right-1,curStr+")");
        }
    }
};