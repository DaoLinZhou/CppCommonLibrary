//
// Created by Daolin on 2019/11/17.
//
#include "../commonHeader.h"

class Solution {
public:
    void shift(vector<vector<int>>& grid){
        int next = grid[grid.size()-1][grid[0].size()-1];
        for(auto& line : grid){
            int temp = line[line.size()-1];
            for(int i = line.size()-1; i >= 1; i--)
                line[i] = line[i-1];
            line[0] = next;
            next = temp;
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(grid.empty() || grid[0].empty())
            return grid;
        int size = grid.size()*grid[0].size();
        k %= size;
        for(int i = 0; i < k; i++)
            shift(grid);
        return grid;
    }
};
