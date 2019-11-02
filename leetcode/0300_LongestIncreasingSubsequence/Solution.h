//
// Created by Daolin on 2019/11/1.
//
#include "../commonHeader.h"

/// LIS(i) 表示以第i个数字为结尾的最长上升子序列的长度
/// LIS(i) 表示[0...i] 的范围内, 选择数字nums[i]可以获得的最长上升子序列的长度
/// 状态转移方程 : LIS(i) = max(1 + LIS(j) if nums[i] > nums[j]) for all j < i
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        // 记录每个位置的LIS, 初始时每个元素本身就是一个lis所以为1
        vector<int> memo(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++)
            for(int j = 0; j < i; j++)
                if(nums[j] < nums[i])
                    memo[i] = max(memo[i], 1 + memo[j]);
        int res = *max_element(memo.begin(), memo.end());
        return res;
    }
};
