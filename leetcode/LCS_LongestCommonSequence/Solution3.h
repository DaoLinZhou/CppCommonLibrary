//
// Created by Daolin on 2019/11/3.
//
#include "../commonHeader.h"

/// 和solution1,2 不同, 这里返回的是最长共同字符子串本身, 而不是计算长度
/// 因为这样更加直观

class Solution{
public:
    string lcs(const string& s1, const string& s2){
        int m = s1.size();
        int n = s2.size();
        bool flag = false;
        vector<vector<string>> memo(m, vector<string>(n, ""));
        for(int i = 0; i < m; i++)
            /// 当出现一次相等时, 后面的lcs就都是它
            if(s1[i] == s2[0] || flag) {
                memo[i][0] = s2[0];
                flag = true;
            }
        flag = false;
        for(int j = 0; j < n; j++)
            if(s1[0] == s2[j] || flag) {
                memo[0][j] = s1[0];
                flag = true;
            }
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                if(s1[i] == s2[j])
                    memo[i][j] = memo[i-1][j-1] + s1[i];
                else
                    memo[i][j] = memo[i][j-1].size() > memo[i-1][j].size() ? memo[i][j-1] : memo[i-1][j];
        return memo[m-1][n-1];
    }
};
