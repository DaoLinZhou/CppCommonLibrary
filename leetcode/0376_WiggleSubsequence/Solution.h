
//
// Created by Daolin on 2019/11/1.
//

#include "../commonHeader.h"

/// 状态转换, increase[i] 是从decrease中选出来的, 反之亦然

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        vector<int> increase(nums.size(), 1);
        vector<int> decrease(nums.size(), 1);

        int res = 1;

        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j ++) {
                if (nums[i] < nums[j])
                    decrease[i] = max(decrease[i], 1 + increase[j]);
                if (nums[i] > nums[j])
                    increase[i] = max(increase[i], 1 + decrease[j]);
                res = max(res, max(decrease[i], increase[i]));
            }
        }
        return res;
    }
};