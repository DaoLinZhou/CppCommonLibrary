//
// Created by Daolin on 2020/8/30.
//

#ifndef ALGORITHM_SOLUTION_H
#define ALGORITHM_SOLUTION_H

#include "../commonHeader.h"

class Solution {
private:
    int m, n;
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size();
        n = image[0].size();
        int oldColor = image[sr][sc];
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<int, int>> queue;
        visited[sr][sc] = true;
        queue.push({sr, sc});

        while(!queue.empty()){
            int x = queue.front().first;
            int y = queue.front().second;
            queue.pop();
            image[x][y] = newColor;

            for(auto & i : d){
                int newx = x + i[0];
                int newy = y + i[1];
                if(inArea(newx, newy) && !visited[newx][newy] && image[newx][newy] == oldColor){
                    visited[newx][newy] = true;
                    queue.push({newx, newy});
                }
            }
        }

        return image;
    }
};

#endif //ALGORITHM_SOLUTION_H
