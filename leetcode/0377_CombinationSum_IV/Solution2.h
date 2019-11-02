//
// Created by Daolin on 2019/10/28.
//

#include "../commonHeader.h"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo = vector<int>(target+1, -1);
        memo[0] = 1;
        for(int i = 1; i < target+1; i++){
            long long res = 0;
            for(int j : nums)
                if(i >= j && memo[i-j] != -1)
                    res += memo[i-j];
            memo[i] = res;
        }
        return memo[target];
    }
};

