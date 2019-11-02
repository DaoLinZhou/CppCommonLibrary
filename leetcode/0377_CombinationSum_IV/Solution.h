//
// Created by Daolin on 2019/10/27.
//
#include "../commonHeader.h"

/// 实际上我最开始是通过思考树形问题来进行解答的
/// 这道题的思考方式和树很像, 改着改着就变为了 树+重叠子 的解题方式了

class Solution {
private:
    /// 寻找用nums的元素组成target的方法有多少
    int search(vector<int>& memo, const vector<int>& nums, int target){
        if(target == 0)
            return 1;
        if(target < 0)
            return 0;
        if(memo[target] != -1)
            return memo[target];
        int res = 0;
        /// 尝试对每个枝杈进行访问
        for(int i : nums)
            res += search(memo, nums, target - i);
        return memo[target] = res;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo = vector<int>(target+1, -1);
        return search(memo, nums, target);
    }
};