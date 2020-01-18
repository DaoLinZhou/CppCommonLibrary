//
// Created by Daolin on 2019/11/25.
//
#include "../commonHeader.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int k = 0;
        // 如果一个元素是第一次出现, 则把它放到k+1这个位置上
        for(int i = 1; i < nums.size(); i++)
            if(nums[i] != nums[k])
                nums[++k] = nums[i];
        /// 由于k是index, 返回size时要+1
        return k+1;
    }
};