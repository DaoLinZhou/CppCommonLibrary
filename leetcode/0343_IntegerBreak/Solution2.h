//
// Created by Daolin on 2019/10/7.
//
#include "../commonHeader.h"

class Solution{
public:
    int integerBreak(int n){
        /// memo[i] 表示将数字i分割后得到的最大乘积
        vector<int> memo = vector<int>(n+1, -1);
        memo[1] = 1;
        for(int i = 2; i <= n; i++)
            /// 求解memo[i], 从1开始尝试分割到i-1
            for(int j = 1; j <= i-1; j++)
                /// j + (i-j)
                /// 三种可能: memo[i], j*(i-j), j * memo[i-j]
                /// 因为 j * memo[i-j] 不总是大于 j*(i-j), 例如 2
                memo[i] = max(memo[i], j * max(i-j, memo[i-j]));
        return memo[n];
    }
};
