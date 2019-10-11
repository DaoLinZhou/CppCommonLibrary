//
// Created by Daolin on 2019/10/9.
//

#include "../commonHeader.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;

        if(n == 1)
            return nums[0];

        vector<int> memo(n, -1);

        /// 求 [1...n-1] 中可选取的最大和
        memo[n-1] = nums[n-1];
        for(int i = n-2; i >= 1; i--)
            for(int j = i; j < min(n, i+3); j++)
                memo[i] = max(memo[i], nums[j]+(j+2 < n ? memo[j+2] : 0));
        /// 记录最大和
        int a = memo[1];

        /// 重置数组
        for(int& i : memo)
            i = -1;

        /// 求 [0...n-2] 中可选取的最大和
        memo[n-2] = nums[n-2];
        for(int i = n-3; i >= 0; i--)
            for(int j = i; j < min(n-1, i+3); j++)
                memo[i] = max(memo[i], nums[j]+(j+2 < n-1 ? memo[j+2] : 0));
        /// 返回两个最大和中更大的那一个
        return max(a, memo[0]);
    }
};
