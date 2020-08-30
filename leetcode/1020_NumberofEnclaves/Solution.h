//
// Created by Daolin on 2020/8/29.
//

#ifndef ALGORITHM_SOLUTION_H
#define ALGORITHM_SOLUTION_H

#include "../commonHeader.h"

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        if(m == 0)
            return 0;
        n = grid[0].size();

        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        int res = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                int k = 0;
                if(grid[i][j] == 1 && !visited[i][j]){
                    if(dfs(grid, i, j, k)) // 如果不在边缘, 则总数增加岛屿格子数量
                        res += k;
                }
            }
        return res;
    }

private:
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;
    vector<vector<bool>> visited;

    bool inArea(int& x, int& y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool inBound(int& x, int& y){
        return x == 0 || x == m-1 || y == 0 || y == n-1;
    }

    /// 从grid[x][y] 位置开始进行floodfill
    /// 保证(x,y)合法, 且grid[x][y]是没有被访问过的陆地
    /// 返回岛屿是否不在边缘
    bool dfs(vector<vector<int>>& grid, int& x, int& y, int& n){
        n++; // 记录当前岛屿有多少格子
        bool res = !inBound(x, y);
        visited[x][y] = true;
        for(auto & i : d){
            int newx = x + i[0];
            int newy = y + i[1];
            if(inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == 1)
                res = dfs(grid, newx, newy, n) && res;
        }
        return res;
    }

};


#endif //ALGORITHM_SOLUTION_H
