//
// Created by Daolin on 2019/10/5.
//
#include "../commonHeader.h"

class Solution {
private:
    vector<int> memo;
    int row, col;
    int findPath(vector<vector<int>>& grid, int x, int y){
        if(x+1 == grid.size() && y+1 == grid[0].size())
            return grid[x][y];

        if(memo[x*col+y] == -1){
            if(x+1 == row)
                memo[x*col+y] =  grid[x][y] + findPath(grid, x, y+1);
            else if(y+1 == col)
                memo[x*col+y] =  grid[x][y] + findPath(grid, x+1, y);
            else
                memo[x*col+y] = grid[x][y] + min(findPath(grid, x, y+1), findPath(grid, x+1, y));
        }
        return memo[x*col+y];
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        memo = vector<int>(row*col, -1);
        return findPath(grid, 0, 0);
    }
};
