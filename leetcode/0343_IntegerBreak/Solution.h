//
// Created by Daolin on 2019/10/7.
//
#include "../commonHeader.h"

/**
 * 使用记忆化搜索的方式
 */

class Solution{
private:
    vector<int> memo;

    int breakInteger(int n){

        if(memo[n] != -1)
            return memo[n];

        int res = 1;
        for(int i = 1; i < n; i++)
            res = max(res, max((n-i)*i, (n-i)*breakInteger(i)));

        memo[n] = res;
        return res;
    }

public:
    int integerBreak(int n){
        memo = vector<int>(n+1, -1);
        return breakInteger(n);
    }
};
