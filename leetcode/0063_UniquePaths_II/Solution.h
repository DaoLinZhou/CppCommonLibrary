//
// Created by Daolin on 2019/10/8.
//

#include "../commonHeader.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // 如果目的地或起始地被障碍物挡住
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;

        vector<vector<long long>> grid = vector<vector<long long>>(m, vector<long long>(n));

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                grid[i][j] = obstacleGrid[i][j] - 1;

        /// 已经判断过目的地没有障碍物
        grid[m-1][n-1] = 1;

        // 先计算右侧和底侧的路径
        for(int i = m-2; i >= 0; i--)
            if(grid[i][n-1] != 0)
                grid[i][n-1] = grid[i+1][n-1];
        for(int i = n-2; i >= 0; i--)
            if(grid[m-1][i] != 0)
                grid[m-1][i] = grid[m-1][i+1];

        for(int i = m-2; i >= 0; i --)
            for(int j = n-2; j >= 0; j --)
                if(grid[i][j] == -1)    // 只有在不是障碍物时才计算路径
                    grid[i][j] = grid[i+1][j] + grid[i][j+1];
        return grid[0][0];
    }
};
