//
// Created by Daolin on 2019/10/21.
//

#include "../commonHeader.h"

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(int i : nums)
            target += i;
        if(target % 2 == 1)
            return false;
        int n = nums.size();
        int C = target/2;

        vector<bool> memo(C+1, false);

        for(int i = 0; i <= C; i++)
            memo[i] = nums[0] == i;

        for(int i = 1; i < n; i++)
            for(int j = C; j >= nums[i]; j--)
                memo[j] = memo[j] || memo[j - nums[i]];
        return memo[C];
    }
};
