#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

/**
* 11. 盛最多水的容器
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。
 */
class Solution {
public:
    // 使用双指针
    // 若向内 移动短板 ，水槽的短板 min(h[i], h[j])min(h[i],h[j]) 可能变大，因此下个水槽的面积 可能增大 。
    // 若向内 移动长板 ，水槽的短板 min(h[i], h[j])min(h[i],h[j])​ 不变或变小，因此下个水槽的面积 一定变小
    int maxArea(vector<int>& height) {


        int maxArea =0;

        for (int left =0, right = height.size()-1 ;right-left >=1;){

            maxArea=calcuteArea(height,left,right,maxArea);

            if (height[left]>height[right]){
                right-- ; // 左侧高于右侧，移动右侧
            }else {
                left++; // 右侧高于左侧，移动左侧
            }
        }

        return maxArea;
    }

    int calcuteArea(vector<int>& height ,int left,int right, int maxArea){
        int h = int(min(height[left],height[right]));
        int tempArea =h*(right-left);
        if (tempArea> maxArea){
            return tempArea;
        }
        return maxArea;
    }
};