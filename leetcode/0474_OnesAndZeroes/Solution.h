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

    /// 从startIndex开始尝试寻找m个0, n个1能组合的最多的元素个数在 zerosAndOnes 中
    int dfs(vector<vector<vector<int>>>& memo, vector<pair<int, int>>& zerosAndOnes, int startIndex, int m, int n){
        if(startIndex == zerosAndOnes.size())
            return 0;

        if(memo[startIndex][m][n] != -1)
            return memo[startIndex][m][n];

        int zeros = zerosAndOnes[startIndex].first;
        int ones = zerosAndOnes[startIndex].second;

        int res = dfs(memo, zerosAndOnes, startIndex+1, m, n);
        if(zeros <= m && ones <= n)
            res = max(1+dfs(memo, zerosAndOnes, startIndex+1, m-zeros, n-ones), res);
        return memo[startIndex][m][n] = res;
    }

public:
    /// m-0, n-1
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> memo = vector<vector<vector<int>>>(strs.size(),
                vector<vector<int>>(m+1, vector<int>(n+1, -1)));

        vector<pair<int, int>> zerosAndOnes;
        for(string& s : strs){
            int zeros = countZeros(s);
            int ones = s.size()-zeros;
            zerosAndOnes.push_back({zeros, ones});
        }

        return dfs(memo, zerosAndOnes, 0, m, n);
    }
};
