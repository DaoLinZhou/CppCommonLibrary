//
// Created by Daolin on 2019/10/30.
//

#include "../commonHeader.h"

class Solution {
private:
    int res = 0;
    void findSum(vector<int>& nums, int index, int sum, int target){
        if(index == nums.size()){
            if(target == sum)
                res++;
            return;
        }
        findSum(nums, index+1, sum + nums[index], target);
        findSum(nums, index+1, sum - nums[index], target);
    }

public:
    int findTargetSumWays(vector<int>& nums, int S) {
        findSum(nums, 0, 0, S);
        return res;
    }
};
