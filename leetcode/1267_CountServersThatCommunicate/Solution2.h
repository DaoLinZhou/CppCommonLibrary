//
// Created by Daolin on 2019/11/24.
//
#include "../commonHeader.h"

class Solution {
public:

    bool isConnected(int i, int j, vector<vector<int>>& gird){
        for(int x = 0; x < gird.size(); x++)
            if(gird[x][j] == 1 && x != i)
                return true;
        for(int y = 0; y < gird[0].size(); y ++)
            if(gird[i][y] == 1 && y != j)
                return true;
        return false;
    }

    int countServers(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] && isConnected(i, j, grid))
                    res ++;
        return res;
    }
};
