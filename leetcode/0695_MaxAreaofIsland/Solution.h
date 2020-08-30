//
// Created by Daolin on 2020/8/29.
//

#ifndef ALGORITHM_SOLUTION_H
#define ALGORITHM_SOLUTION_H

#include "../commonHeader.h"

class Solution {
public:
    int w, h;
    int direct[4][2] = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
    };

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        h = grid.size();
        w = grid[0].size();
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        for(int y = 0; y < h; y ++){
            for(int x = 0; x < w; x++){
                if(!visited[y][x] && grid[y][x])
                    maxArea = max(maxArea, dfs(x, y, grid, visited));
            }
        }
        return maxArea;
    }

    int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        visited[y][x] = true;
        int area = 1;
        for(int i = 0; i < 4; i++){
            int n_x = x + direct[i][0];
            int n_y = y + direct[i][1];
            if(inArea(n_x, n_y) && !visited[n_y][n_x] && grid[n_y][n_x]){
                area += dfs(n_x, n_y, grid, visited);
            }
        }
        return area;
    }

    bool inArea(int x, int y){
        return x >= 0 && x < w && y >= 0 && y < h;
    }

};

#endif //ALGORITHM_SOLUTION_H
