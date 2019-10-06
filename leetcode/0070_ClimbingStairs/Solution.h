//
// Created by Daolin on 2019/10/5.
//
#include "../commonHeader.h"

class Solution {
private:
    vector<int> memo;

    int calcWays(int n){
        if(n == 0 || n == 1)
            return 1;
        if(memo[n] == -1)
            memo[n] = calcWays(n-1) + calcWays(n-2);
        return memo[n];
    }

public:
    int climbStairs(int n) {
        memo = vector<int>(n+1, -1);
        return calcWays(n);
    }
};
