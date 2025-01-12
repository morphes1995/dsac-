#include <vector>
using namespace std;
/**
 * 121. 买卖股票的最佳时机
 * 剑指 Offer 63. 股票的最大利润
 * 假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
 *
 * 思路：遍历数组时保存当前遍历过的数组元素的最小值， 每次遍历一个元素时就用当前值和最小值计算利润，并保存最大利润
 */
int maxProfit(vector<int>& prices) {
    int prevMin= prices[0];
    int maxProfit = 0;
    for(int i=1;i<prices.size();i++){

        if(prices[i]-prevMin>maxProfit){
            maxProfit = prices[i]-prevMin;
        }

        if(prices[i]<prevMin){
            prevMin= prices[i];
        }

    }
    return maxProfit;

}