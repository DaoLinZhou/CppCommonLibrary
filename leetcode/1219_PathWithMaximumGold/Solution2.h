//
// Created by Daolin on 2019/10/6.
//
#include "../commonHeader.h"

class Solution {
private:
    int d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int row, col;

    bool inArea(int x, int y){
        return x >= 0 && x < row && y >= 0 && y < col;
    }

    int find(vector<vector<int>>& grid, int x, int y){
        int max_gold = 0;
        int cur_gold = grid[x][y];
        grid[x][y] = 0;     // 优化, 不使用visited数组, 而是访问之后把它设为0, 在退出前再赋值回去
        for(int i = 0; i < 4; i++){
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if(inArea(newx, newy) && grid[newx][newy] != 0)
                max_gold = max(max_gold,find(grid, newx, newy));
        }
        grid[x][y] = cur_gold;
        return cur_gold + max_gold;
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        row = grid.size();
        col = grid[0].size();
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(grid[i][j])
                    res = max(res, find(grid, i, j));

        return res;
    }
};