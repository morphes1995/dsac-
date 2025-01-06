/**
* 15. 三数之和
* 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]]
* 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。
* 请你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。
 */
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);

        for(int i=0;i<nums.length-2;i++){
            int fixedNum = nums[i];
            int target = 0-fixedNum;
            int left = i+1;
            int right = nums.length-1;

            if(nums[i]>0) break; // 排序后，第i个元素后面已经没有负数了，提前终止
            if(i>0 && nums[i]==nums[i-1]) continue; // 排序后，相同的数字仅fix一次，防止重复

            while(left < right){
                if(target==nums[left]+nums[right]){
                    ArrayList<Integer> ans = new ArrayList<Integer>();
                    ans.add(fixedNum);
                    ans.add(nums[left]);
                    ans.add(nums[right]);
                    res.add(ans);
                    // 防止结果集三元组中，在第一个数字相同的情况下，第二个数字重复;
                    // 对于两个三元组，如果第一个，第二个数字均不同，则第三个数字肯定也不同
                    while(left<right && nums[left]==nums[left+1]) left ++;
                    left ++;
                    // 优化，更加快速的定义到下一组 等于target的两个数字
                    while(left<right && nums[right]==nums[right-1]) right --;
                    right --;
                }else if(target > nums[left]+nums[right]){
                    left ++ ;
                }else if(target < nums[left]+nums[right]){
                    right --;
                }
            }
        }

        return res;
    }
};