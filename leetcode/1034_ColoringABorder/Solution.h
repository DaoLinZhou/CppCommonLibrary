//
// Created by Daolin on 2020/8/30.
//

#ifndef ALGORITHM_SOLUTION_H
#define ALGORITHM_SOLUTION_H
#include "../commonHeader.h"

class Solution {
private:
    int m, n, oldColor;
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool inArea(int& x, int& y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool onBound(vector<vector<int>>& grid, vector<vector<bool>>& visited, int& x, int& y){
        if(x == 0 || x+1 == m || y == 0 || y+1 == n){
            return true;
        }

        for(auto & i : d){
            int newx = x + i[0];
            int newy = y + i[1];
            if(!visited[newx][newy] && grid[newx][newy] != oldColor)
                return true;
        }
        return false;
    }

public:

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        m = grid.size();
        n = grid[0].size();
        oldColor = grid[r0][c0];
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<int, int>> queue;
        visited[r0][c0] = true;
        queue.push({r0, c0});

        while(!queue.empty()){
            int x = queue.front().first;
            int y = queue.front().second;
            queue.pop();
            if(onBound(grid, visited, x, y)) {
                grid[x][y] = color;
            }

            for(auto & i : d){
                int newx = x + i[0];
                int newy = y + i[1];
                if(inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == oldColor){
                    visited[newx][newy] = true;
                    queue.push({newx, newy});
                }
            }
        }

        return grid;
    }

};

#endif //ALGORITHM_SOLUTION_H
