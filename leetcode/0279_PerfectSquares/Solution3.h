//
// Created by Daolin on 2019/10/7.
//
#include "../commonHeader.h"

/**
 * 动态规划
 */
class Solution {
public:
    int numSquares(int n) {
        /// 最大为n, 找到的完全平方数的个数一定比n小
        vector<int> memo = vector<int>(n+1, n);

        memo[0] = 0;

        /// 求从1到n的所有数的最小numSquares
        for(int i = 1; i <= n; i++)
            for(int j = 1; j*j <= i; j ++)
                memo[i] = min(memo[i], 1+memo[i-j*j]);

        return memo[n];
    }
};
