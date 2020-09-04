//
// Created by Daolin on 2020/9/3.
//

#ifndef ALGORITHM_SOLUTION_H
#define ALGORITHM_SOLUTION_H

#include "../commonHeader.h"


/**
 * 求起始点的哈密尔顿路径的数量
 */

class Solution {
    int zeros, m, n;
    int visitedNum;
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool inArea(int& x, int& y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

public:

    int uniquePathsIII(vector<vector<int>>& grid) {
        visitedNum = 0;
        int visited = 0;
        m = grid.size(), n = grid[0].size();
        zeros = 2;      // 算上起始点和终止点
        int start_x, start_y;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0)
                    zeros++;
                else if(grid[i][j] == 1){
                    start_x = i;
                    start_y = j;
                }
            }
        }

        return dfs(grid, start_x, start_y, visited);
    }

    int dfs(vector<vector<int>>& grid, int x, int y, int visited){
        int offset = (x * n) + y;
        visitedNum++;
        int res = 0;

        visited |= (1 << offset);
        if(grid[x][y] == 2){    // 如果到达终止点
            res = visitedNum == zeros;
        }else {
            for (int i = 0; i < 4; i++) {
                int new_x = x + d[i][0];
                int new_y = y + d[i][1];
                int next = new_x * n + new_y;
                if (inArea(new_x, new_y) && grid[new_x][new_y] != -1 &&
                    !(visited & (1 << next))) {
                    res += dfs(grid, new_x, new_y, visited);
                }
            }
        }
        visitedNum--;
        return res;
    }

};

#endif //ALGORITHM_SOLUTION_H
