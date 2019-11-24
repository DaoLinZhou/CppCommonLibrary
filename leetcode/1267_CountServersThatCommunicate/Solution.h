//
// Created by Daolin on 2019/11/23.
//
#include "../commonHeader.h"

class Solution {
public:

    int r, c;
    bool inArea(int x, int y){
        return x >= 0 && x < r && y >=0 && y < c;
    }

    int dfs(int i, int j, vector<vector<bool>>& visited, const vector<vector<int>>& grid){
        visited[i][j] = true;
        int res = 1;
        for(int n = 0; n < grid.size(); n++){
            int n_x = n;
            int n_y = j;
            if(inArea(n_x, n_y) && !visited[n_x][n_y] && grid[n_x][n_y])
                res += dfs(n_x, n_y, visited, grid);
        }
        for(int n = 0; n < grid[0].size(); n++){
            int n_x = i;
            int n_y = n;
            if(inArea(n_x, n_y) && !visited[n_x][n_y] && grid[n_x][n_y])
                res += dfs(n_x, n_y, visited, grid);
        }

        return res;
    }

    int countServers(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!visited[i][j] && grid[i][j]){
                    int n = dfs(i, j, visited, grid);
                    if(n > 1)
                        res += n;
                }
            }
        }
        return res;
    }
};

