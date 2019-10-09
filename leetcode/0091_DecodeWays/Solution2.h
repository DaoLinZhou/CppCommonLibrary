//
// Created by Daolin on 2019/10/8.
//
#include "../commonHeader.h"

/**
 * 动态规划
 */

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size()+1;
        // 存储当前位置往后所有decoding的可能
        vector<int> memo = vector<int>(n+1, -1);

        // 当没有元素时, 只有一种可能
        memo[n] = 1;
        // 最后一个元素如果不为0 则有一种decoding的方法
        memo[n-1] = s[n-2] != '0';

        // 从后向前推导
        for(int i = n-2; i > 0; i--){

            int second = s[i] - '0';
            int first = s[i-1] - '0';

            // 如果以0开头
            if(first == 0)
                memo[i] = 0;
            else if(first*10 + second > 26)
                memo[i] = memo[i+1];
            else
                memo[i] = memo[i+1] + memo[i+2];
        }
        // memo[0] 是空闲的位置, 但这方便我们对vec进行访问
        return memo[1];
    }
};
