//
// Created by Daolin on 2019/9/30.
//

#include "../commonHeader.h"

/**
 * floodfill算法
 * 有点类似与求图的连通分量
 */

class Solution {
private:
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;
    vector<vector<bool>> visited;

    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    /// 从grid[x][y] 位置开始进行floodfill
    /// 保证(x,y)合法, 且grid[x][y]是没有被访问过的陆地
    void dfs(vector<vector<char>>& grid, int x, int y){
        visited[x][y] = true;
        for(int i = 0; i < 4; i++){
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if(inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == '1')
                dfs(grid, newx, newy);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        if(m == 0)
            return 0;
        n = grid[0].size();

        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        int res = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                // dfs会访问它周围的'1', 如果遍历到新的没被访问过的'1' 就说明是新的岛屿
                if(grid[i][j] == '1' && !visited[i][j]){
                    res ++;
                    dfs(grid, i, j);
                }
        return res;
    }
};
