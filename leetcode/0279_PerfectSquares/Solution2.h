//
// Created by Daolin on 2019/10/7.
//

#include "../commonHeader.h"

/**
 * 使用记忆化搜索以及递归进行查找
 * 效率比使用图低, 但可以作为动态规划和递归的练习
 */
class Solution {
private:

    int find(int n, vector<int>& memo){
        if(n == 0)
            return 0;

        if(memo[n] != -1)
            return memo[n];

        int res = n;    /// 最大为n, 因为n可以分为n个1
        /// 分为 n-i*i 和 i*i两部分, i*i的结果为1, 所以只需要递归寻找 n-i*i
        for(int i = 1; i*i <= n; i++)
            res = min(res, find(n-i*i, memo) + 1);

        memo[n] = res;
        return res;
    }

public:
    int numSquares(int n) {
        vector<int> memo = vector<int>(n+1, -1);
        return find(n, memo);
    }
};
