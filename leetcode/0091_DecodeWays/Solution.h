//
// Created by Daolin on 2019/10/7.
//
#include "../commonHeader.h"

/**
 * 记忆化搜索 + 递归
 */

class Solution {
private:
    int decoding(const string& s, int index, vector<int>& memo){

        if(memo[index] != -1)
            return memo[index];

        if(s.size() == index)
            return 1;
        // 如果是 0 返回0 否则返回 1
        if(s.size() == 1 + index)
            return s[index] != '0' ? 1 : 0;

        int first = s[index] - '0';
        int second = s[index+1] - '0';

        /// 如果以0开头直接返回0
        if(first == 0)
            return 0;

        int res;
        if(first*10+second > 26)
            res = decoding(s, index+1, memo);
        else
            res = decoding(s, index+2, memo) + decoding(s, index+1, memo);

        return memo[index] = res;
    }
public:
    int numDecodings(string s) {
        vector<int> memo = vector<int>(s.size() + 1, -1);
        return decoding(s, 0, memo);
    }
};
