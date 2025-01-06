#include <vector>
#include <stack>
using namespace std;

/**
* 739. 每日温度
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer
，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。
如果气温在这之后都不会升高，请在该位置用 0 来代替。
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n); // 存储 temperatures 数组的下标
        stack<int> s;
        // 单调栈满足从栈底到栈顶元素对应的温度递减，
        // 因此每次有元素进栈时，会将温度更低的元素全部移除，并更新出栈元素对应的等待天数，
        // 这样可以确保等待天数一定是最小的。
        // 如果一个下标在单调栈里，则表示尚未找到下一次温度更高的下标。
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int previousIndex = s.top();
                s.pop();
                ans[previousIndex] = i - previousIndex; // 更新出栈元素对应的等待天数
            }
            // 温度更低的元素已经全部移除
            s.push(i);
        }
        return ans;

    }
};