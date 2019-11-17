//
// Created by Daolin on 2019/11/17.
//

#include "../commonHeader.h"

class Solution {
public:
    vector<vector<int>> memo;

    int find(vector<int>& nums, int index, int need){
        if(index == 0 && need == (nums[0]%3))
            return nums[0];
        else if(index == 0 && need == 0)
            return 0;
        else if(index == 0)
            return -1;

        if(memo[need][index] != -2)
            return memo[need][index];

        int res1 = find(nums, index-1, need);
        int temp = need - (nums[index]%3);
        if(temp < 0) temp += 3;
        int res2 = find(nums, index-1, temp);

        if(res2 != -1)
            res2 += nums[index];

        return memo[need][index] = max(res1, res2);
    }

    int maxSumDivThree(vector<int>& nums) {
        memo = vector<vector<int>>(3, vector<int>(nums.size(), -2));
        int res = find(nums, nums.size()-1, 0);
        return max(res, 0);
    }
};
