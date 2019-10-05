//
// Created by Daolin on 2019/10/4.
//
#include "../commonHeader.h"

class Solution {
private:
    int fibHelper(int n, vector<int>& memo){
        if(n < 2)   /// n == 0 时返回0, n == 1时返回1
            return n;
        /// 优化: 如果要查询的fib值之前算过, 则不再重新计算, 只有没计算过时才进行计算
        if(memo[n] == -1)
            memo[n] = fibHelper(n-1, memo) + fibHelper(n-2, memo);
        return memo[n];
    }

public:
    int fib(int n) {
        vector<int> memo = vector<int>(n+1, -1);
        return fibHelper(n, memo);
    }
};
