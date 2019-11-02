//
// Created by Daolin on 2019/10/30.
//

#include "../commonHeader.h"

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(int& i: nums)
            sum += i;
        if(sum < abs(S) || (sum-S)%2 != 0) return 0;

        /// target 是不要的部分 所以剩余的和就是S+target, 相减就是S
        int target = (sum-S)/2;
        vector<int> memo(target+1, 0);
        memo[0] = 1;
        for (int num : nums)
            for(int j = target; j >= num; j--)
                memo[j] += memo[j - num];

        return memo[target];
    }
};
