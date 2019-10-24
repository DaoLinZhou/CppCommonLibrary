//
// Created by Daolin on 2019/10/21.
//

#include "../commonHeader.h"

class Solution {
private:
    vector<vector<int>> memo;
    bool tryPartition(const vector<int>& nums, int index, int target){
        if(target == 0)
            return true;
        if(target < 0 || index >= nums.size())
            return false;
        if(memo[index][target] != -1)
            return memo[index][target];
        memo[index][target] =  tryPartition(nums, index+1, target) || tryPartition(nums, index+1, target - nums[index]);
        return memo[index][target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(int i : nums)
            target += i;
        if(target % 2 == 1)
            return false;
        memo = vector(nums.size(), vector<int>(target/2+1, -1));
        return tryPartition(nums, 0, target/2);
    }
};
