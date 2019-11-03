//
// Created by Daolin on 2019/11/3.
//

/**
 * 给出两个字符串s1, s2, 求这两个字符串的最长公共子序列的长度
 */
#include "../commonHeader.h"
class Solution{
private:
    vector<vector<int>> memo;
    /// 计算s1[0...m] 和 s2[0...n]的最长公共子序列的长度
    int find(const string& s1, int m, const string& s2, int n){
        if(m < 0 || n < 0)
            return 0;
        if(memo[m][n] != -1)
            return memo[m][n];
        int res;
        if(s1[m] == s2[n])
            res = 1 + find(s1, m - 1, s2, n - 1);
        else
            res = max(find(s1, m - 1, s2, n), find(s1, m, s2, n - 1));
        return memo[m][n] = res;
    }
public:
    int lcs(const string& s1, const string& s2){
        int m = s1.size()-1;
        int n = s2.size()-1;
        memo = vector<vector<int>>(m+1, vector<int>(n+1, -1));
        return find(s1, m, s2, n);
    }
};
