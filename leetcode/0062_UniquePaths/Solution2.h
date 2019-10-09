//
// Created by Daolin on 2019/10/8.
//
#include "../commonHeader.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
//        vector<vector<int>> grid = vector<vector<int>>(m, vector<int>(n, -1));
        int grid[m][n];
        grid[m-1][n-1] = 1;

        // 初始化最右和最下两条边
        for(int i = 0; i < m-1; i++)
            grid[i][n-1] = 1;
        for(int i = 0; i < n-1; i++)
            grid[m-1][i] = 1;

        for(int i = m-2; i >= 0; i --)
            for(int j = n-2; j >= 0; j --)
                grid[i][j] = grid[i+1][j] + grid[i][j+1];

        return grid[0][0];
    }
};
