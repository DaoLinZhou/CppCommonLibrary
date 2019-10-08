//
// Created by Daolin on 2019/10/6.
//
#include "../commonHeader.h"

class Solution {
private:
    int d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int row, col;
    vector<vector<bool>> visited;

    bool inArea(int x, int y){
        return x >= 0 && x < row && y >= 0 && y < col;
    }

    int find(vector<vector<int>>& grid, int x, int y){
        int max_gold = 0;
        for(int i = 0; i < 4; i++){
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if(inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] != 0){
                visited[newx][newy] = true;
                max_gold = max(max_gold,find(grid, newx, newy));
                visited[newx][newy] = false;
            }
        }
        return grid[x][y] + max_gold;
    }


public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        row = grid.size();
        col = grid[0].size();
        visited = vector<vector<bool>>(row, vector<bool>(col, false));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j]){
                    visited[i][j] = true;
                    res = max(res, find(grid, i, j));
                    visited[i][j] = false;
                }
            }
        }
        return res;
    }
};
