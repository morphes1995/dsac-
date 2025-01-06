#include <vector>
#include <list>
#include <set>
using namespace std;

/**
*78. 子集
*给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的
子集
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        list<int> curr;
        getSubSets(res, nums,0, curr);
        return res;
    }

    void getSubSets(vector<vector<int>> &res, vector<int> &nums, int startIdx, list<int> &cur){

        if(startIdx==nums.size()){
            vector<int> ans;
            for(int val:cur){
                ans.push_back(val);
            }
            res.push_back(ans);
            return;
        }


        getSubSets(res,nums,startIdx+1,cur); // 子集中不包含当前元素

        cur.push_back(nums[startIdx]);
        getSubSets(res,nums,startIdx+1,cur); // 子集中包含当前元素
        cur.pop_back();
    }
};

