//
// Created by Daolin on 2019/10/30.
//

#include "../commonHeader.h"

/**
 * 记忆化搜索
 * 由于sum可能为负数所以使用map进行计算
 */

class Solution {
private:
    int findSum(vector<int>& nums, vector<unordered_map<int, int>>& memo, int index, int sum, int target){
        if(index == nums.size())
            return target == sum;

        if(memo[index].count(sum))
            return memo[index][sum];

        int res = 0;
        res += findSum(nums, memo, index+1, sum + nums[index], target);
        res += findSum(nums, memo, index+1, sum - nums[index], target);
        return memo[index][sum] = res;
    }

public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<unordered_map<int, int>> memo(nums.size());
        return findSum(nums, memo, 0, 0, S);
    }
};
