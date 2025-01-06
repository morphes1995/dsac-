#include <vector>
#include <list>
#include <unordered_map>
using namespace std;


/**
*
39. 组合总和
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，
找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合
，并以列表形式返回。你可以按 任意顺序 返回这些组合。
candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        list<int> curr;
        combine(res,curr,0,0, candidates,target);
        return res;
    }

    void combine( vector<vector<int>> &res,list<int> &cur,int curSum,int startIdx,
                        vector<int> &candidates, int target){
        if(curSum>target){
            return;
        }
        if(curSum==target){
            vector<int> ans;
            ans.reserve(cur.size());
            for(int val:cur){
                ans.push_back(val);
            }
            res.push_back(ans);
            return;
        }
        if(startIdx==candidates.size()){
            return ;
        }


        combine(res,cur,curSum,startIdx+1,candidates,target);// 不包含当前元素

        cur.push_back(candidates[startIdx]);
        curSum += candidates[startIdx];
        // 包含当前元素, 由于startIdx没有加一，因此允许重复包含当前元素
        combine(res,cur,curSum,startIdx,candidates,target);
        curSum -= candidates[startIdx];
        cur.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        list<int> curr;
        sort(candidates.begin(), candidates.end());// 排序
        combine2(res,curr,0,0, candidates,target);

        return res;
    }

    void combine2( vector<vector<int>> &res,list<int> &cur,int curSum,int startIdx,
                        vector<int> &candidates, int target){
        if(curSum>target){
            return;
        }
        if(curSum==target){
            vector<int> ans;
            ans.reserve(cur.size());
            for(int val:cur){
                ans.push_back(val);
            }
            res.push_back(ans);
            return;
        }
        if(startIdx==candidates.size()){
            return ;
        }

        int i=1;
        while(startIdx+i<candidates.size()&& candidates[startIdx]==candidates[startIdx+i]){
            i++;
        }

        // eg
        //  10, 10 ,11 ...
        //   Y  Y （case 1）
        //      N （case 2）
        //   N  N （case 3） 如果跳过第一个10， 则第二个也需要一起跳过, 否则case 2， case 4 会重复
        //      Y （case 4）
        combine(res,cur,curSum,startIdx+i,candidates,target);// 不包含当前元素, 跳过所有重复的元素

        cur.push_back(candidates[startIdx]);
        curSum += candidates[startIdx];
        // 包含当前元素, 由于startIdx加一，因此不允许重复包含当前元素
        combine(res,cur,curSum,startIdx+1,candidates,target);
        curSum -= candidates[startIdx];
        cur.pop_back();
    }
};