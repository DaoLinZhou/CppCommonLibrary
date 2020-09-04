//
// Created by Daolin on 2020/9/3.
//

#ifndef ALGORITHM_SOLUTION2_H
#define ALGORITHM_SOLUTION2_H
#include "../commonHeader.h"
class Solution {
    int zeros, m, n;
    int count, visitedNum;
    vector<vector<bool>> visited;
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool inArea(int& x, int& y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

public:

    int uniquePathsIII(vector<vector<int>>& grid) {
        count = 0;
        visitedNum = 0;
        m = grid.size(), n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        zeros = 2;
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

        dfs(grid, start_x, start_y);
        return count;
    }

    void dfs(vector<vector<int>>& grid, int x, int y){
        visitedNum++;
        visited[x][y] = true;
        if(grid[x][y] == 2){
            if(visitedNum == zeros)
                count++;
            visitedNum--;
            visited[x][y] = false;
            return;
        }

        for(int i = 0; i < 4; i++){
            int new_x = x + d[i][0];
            int new_y = y + d[i][1];
            if(inArea(new_x, new_y) && grid[new_x][new_y] != -1 && !visited[new_x][new_y]){
                dfs(grid, new_x, new_y);
            }
        }
        visitedNum--;
        visited[x][y] = false;
    }


};

#endif //ALGORITHM_SOLUTION2_H
