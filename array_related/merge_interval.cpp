#include <vector>
#include <algorithm>
using namespace std;

/**
* 56. 合并区间
* 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
* 请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
 */
class Solution {
public:
    static bool cmp(vector<int> &v1, vector<int> &v2){
        return v1[0]<v2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 区间按左边界排序
        // sort(intervals.begin(), intervals.end()); // 元素为vector，默认按照vector的第一个数据排序的
        sort(intervals.begin(), intervals.end(), cmp);
        int mergedIdx = 0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<= intervals[mergedIdx][1]){
                intervals[mergedIdx][1] = max(intervals[mergedIdx][1], intervals[i][1]);
            }else{
                // 区间没有重叠，重新生成一个区间
                mergedIdx ++;
                intervals[mergedIdx] = intervals[i];
            }
        }

        vector<vector<int>> res(mergedIdx+1);
        for(int i=0;i<= mergedIdx;i++){
            res[i]= intervals[i];
        }
        return res;
    }
};