//
// Created by Daolin on 2019/10/9.
//
#include "../commonHeader.h"

class Solution {
private:

    vector<int> memo;

    /// 考虑抢劫nums[index...nums.size())这个范围的所有房子
    int tryRob(vector<int>& nums, int index){
        if(index >= nums.size())
            return 0;

        if(memo[index] != -1)
            return memo[index];

        int res = 0;
        /// 优化, 最多隔着两位进行选取, 如果隔着三个房子, 则可以选取中间的房子, 使得结果更大
        for(int i = index; i < min(index+3, (int)nums.size()); i++)
            res = max(res, nums[i] + tryRob(nums, i+2));
        memo[index] = res;
        return res;
    }

public:
    int rob(vector<int>& nums) {
        memo = vector<int>(nums.size(), -1);
        return tryRob(nums, 0);
    }
};
