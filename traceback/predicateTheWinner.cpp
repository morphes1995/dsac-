/**
* leetcode 486. 预测赢家
     * 给你一个整数数组 nums 。玩家 1 和玩家 2 基于这个数组设计了一个游戏。
     * 玩家 1 和玩家 2 轮流进行自己的回合，玩家 1 先手。
     * 开始时，两个玩家的初始分值都是 0 。每一回合，玩家从数组的任意一端取一个数字（即，nums[0] 或 nums[nums.length - 1]），
     * 取到的数字将会从数组中移除。玩家选中的数字将会加到他的得分上。当数组中没有剩余数字可取时，游戏结束。
     * 如果玩家 1 能成为赢家，返回 true 。如果两个玩家得分相等，同样认为玩家 1 是游戏的赢家，也返回 true 。
     *
     *
     * 思路： 考虑只有两个元素的特殊场景
     **/


    public boolean PredictTheWinner(int[] nums) {
        return f(nums,0,nums.length-1) >= s(nums,0,nums.length-1);
    }

    // 对于一个特定的区间，玩家为先手时的逻辑
    public int f(int[] nums,int start,int end){
        if(start==end){
            return nums[start];
        }
        // 先手玩家在选择一个元素(nums[start] or nums[end])后，在排除该元素后的新区间中变为了后手玩家
        return Math.max(nums[start]+s(nums,start+1,end),nums[end]+s(nums,start,end-1));
    }
    // 对于一个特定的区间，玩家为后手时的逻辑
    public int s(int[] nums,int start,int end){
        if(start==end){
            return 0;
        }
        // 在[start:end]区间上后手玩家不会挑选元素
        // 后手玩家会在先手玩家挑选完最佳元素(nums[start] or nums[end])的区间上成为先手玩家
        return Math.min(f(nums,start+1,end),f(nums,start,end-1));
}