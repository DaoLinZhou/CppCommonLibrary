//
// Created by Daolin on 2019/10/28.
//
#include "../commonHeader.h"

class Solution {
private:
    int countZeros(const string& s){
        int res = 0;
        for(char c : s)
            if(c == '0')
                res++;
        return res;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp = vector<vector<int>>(m+1, vector<int>(n+1, 0));

        vector<pair<int, int>> zerosAndOnes;
        for(string& s : strs){
            int zeros = countZeros(s);
            int ones = s.size()-zeros;
            zerosAndOnes.push_back({zeros, ones});
        }

        for(auto combo : zerosAndOnes) {
            int zeros = combo.first;
            int ones = combo.second;
            for (int i = m; i >= zeros; i--)
                for (int j = n; j >= ones; j--)
                    /// 每次都尝试进行更新, 从不选当前str和选择当前str的值进行对比
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
        }
        /// 当所有更新完成之后它就是最终的值
        return dp[m][n];
    }
};
