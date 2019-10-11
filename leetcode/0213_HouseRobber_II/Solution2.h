//
// Created by Daolin on 2019/10/10.
//
#include "../commonHeader.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        /// 判断特殊情况
        if(n == 0)
            return 0;
        /// 如果只有一个, max1, max2 都为 0
        if(n == 1)
            return nums[0];

        int prev = 0, curr = 0, temp;
        for(int i = 0; i < n-1; i++){
            temp = curr;
            curr = max(prev + nums[i], curr);
            prev = temp;
        }

        int max1 = curr;

        /// 重置
        prev = curr = 0;
        for(int i = 1; i < n; i++){
            temp = curr;
            curr = max(prev+nums[i], curr);
            prev = temp;
        }
        int max2 = curr;
        return max(max1, max2);
    }
};
