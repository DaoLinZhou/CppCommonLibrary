//
// Created by Daolin on 2020/8/30.
//

#ifndef ALGORITHM_SOLUTION_H
#define ALGORITHM_SOLUTION_H

#include "../commonHeader.h"
class Solution {
private:
    int m, n;
    int d[8][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    struct Block{
        int x;
        int y;
        int count;
        Block(int x, int y, int count) : x(x), y(y), count(count) {}
    };

    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1)
            return -1;
        if(m == 1 && n == 1)
            return 1;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<Block> queue;
        queue.push(Block(0, 0, 1));
        visited[0][0] = true;

        while(!queue.empty()){
            Block block = queue.front();
            queue.pop();

            for(auto& i: d){
                int newx = block.x + i[0];
                int newy = block.y + i[1];
                if(inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == 0){
                    if(newx == m-1 && newy == n-1)
                        return block.count + 1;
                    visited[newx][newy] = true;
                    queue.push({newx, newy, block.count+1});
                }
            }
        }
        return -1;
    }


};

#endif //ALGORITHM_SOLUTION_H
