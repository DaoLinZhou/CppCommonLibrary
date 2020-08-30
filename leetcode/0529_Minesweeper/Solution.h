//
// Created by Daolin on 2020/8/30.
//

#ifndef ALGORITHM_SOLUTION_H
#define ALGORITHM_SOLUTION_H

#include "../commonHeader.h"

class Solution {
private:
    int m, n;
    int d[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    bool inArea(int& x, int& y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    // return 0 if no Mine around (x, y), else return the number of Mines
    int nextToMine(vector<vector<char>>& grid, int x, int y){
        int count = 0;
        for(auto & i : d){
            int newx = x+i[0];
            int newy = y+i[1];
            if(inArea(newx, newy) && grid[newx][newy] == 'M')
                count++;
        }
        return count;
    }

public:

    vector<vector<char>> updateBoard(vector<vector<char>>& grid, const vector<int>& click) {
        m = grid.size();
        n = grid[0].size();
        dfs(grid, click);
        return grid;
    }

    void dfs(vector<vector<char>>& grid, const vector<int>& click){
        int r0 = click[0];
        int c0 = click[1];

        if(grid[r0][c0] == 'M'){
            grid[r0][c0] = 'X';
            return;
        }else{
            int mineNum = nextToMine(grid, r0, c0);
            if(mineNum > 0) {
                grid[r0][c0] = '0' + mineNum;
                return;
            } else {
                grid[r0][c0] = 'B';
                for(auto & i : d){
                    int newx = r0+i[0];
                    int newy = c0+i[1];
                    if(inArea(newx, newy) && grid[newx][newy] == 'E')
                        updateBoard(grid, {newx, newy});
                }
            }
        }
    }

};

#endif //ALGORITHM_SOLUTION_H
