//
// Created by Daolin on 2020/1/17.
//
#include "../commonHeader.h"
class Solution {
public:

    vector<vector<int>> memo;

    bool isSub(vector<vector<int>>& matrix, int r, int c, int side) {
        int rMax = r + side-1, cMax = c + side - 1;
        if(rMax >= matrix.size() || cMax >= matrix[0].size())
            return false;
        for(int i = r; i <= rMax; i++)
            for(int j = c; j <= cMax; j++)
                if(matrix[i][j] == 0)
                    return false;
        return true;
    }

    int findSquares(vector<vector<int>>& matrix, int side){
        int res = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(memo[i][j] && isSub(matrix, i, j, side)) {
                    res++;
                }else{
                    memo[i][j] = 0;
                }
            }
        }
        return res;
    }

    int countSquares(vector<vector<int>>& matrix) {
        int side = min(matrix.size(), matrix[0].size());
        int ans = 0;
        memo = matrix;
        for(auto& v : matrix)
            for(auto& n : v)
                ans += n;
        for(int i = 2; i <= side; i++){
            int res = findSquares(matrix, i);
            if(res == 0)
                return ans;
            ans += res;
        }
        return ans;
    }
};
