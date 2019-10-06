//
// Created by Daolin on 2019/10/5.
//
#include "../commonHeader.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {

        // 拷贝, 而不是在原本的vector上做更改
        vector<vector<int>> grid = g;

        int row = grid.size();
        int col = grid[0].size();

        // 处理最下侧的那一行
        for(int i = col-2; i >= 0; i --)
            grid[row-1][i] += grid[row-1][i+1];

        // 处理最右侧那一行
        for(int i = row-2; i >= 0; i --)
            grid[i][col-1] += grid[i+1][col-1];

        /// 逆推, 从右下角推到左上角
        for(int i = row-2; i >= 0; i --)
            for(int j = col-2; j >= 0; j --)
                grid[i][j] += min(grid[i][j+1], grid[i+1][j]);

        return grid[0][0];
    }
};
