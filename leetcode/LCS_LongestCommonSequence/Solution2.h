//
// Created by Daolin on 2019/11/3.
//

#include "../commonHeader.h"
class Solution{
public:
    int lcs(const string& s1, const string& s2){
        int m = s1.size();
        int n = s2.size();
        bool flag = false;
        if(m == 0 || n == 0)
            return 0;
        vector<vector<int>> memo(m, vector<int>(n));
        for(int i = 0; i < m; i++)
            if(s1[i] == s2[0] || flag)
                flag = memo[i][0] = 1;
        flag = false;
        for(int j = 0; j < n; j++)
            if(s1[0] == s2[j] || flag)
                flag = memo[0][j] = 1;
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(s1[i] == s2[j])
                    memo[i][j] = 1 + memo[i-1][j-1];
                else
                    memo[i][j] = max(memo[i][j-1], memo[i-1][j]);
            }
        }
        return memo[m-1][n-1];
    }
};
