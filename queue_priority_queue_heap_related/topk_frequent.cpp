
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/**
* 347. 前 K 个高频元素
* 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 */
class Solution {
public:
    struct Item{
        int val;
        int count;
        bool operator < (const Item &other) const{
            return count > other.count; // 根据count排序， 构造小根堆
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        //  // 使用字典，统计每个元素出现的次数，元素为键，元素出现的次数为值
        unordered_map<int,int> map;
        for(int val:nums){
            map[val]++;
        }

        // 遍历map，用最小堆保存频率最大的k个元素
        priority_queue<Item> pq;
        int c=0;
        for (auto it=map.begin();it!=map.end();it++) {
            if(c<k){
                pq.push({it->first, it->second});
                c++;
            }else if(it->second > pq.top().count){
                pq.pop();
                pq.push({it->first, it->second});
            }
        }

        // 取出最小堆中的元素
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().val);
            pq.pop();
        }

        return res;
    }
};