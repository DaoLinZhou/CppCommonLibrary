//
// Created by Daolin on 2019/10/1.
//
#include "../commonHeader.h"

/**
 * 个人认为比较非常好地体现出解题思路的重要性的题目
 * 非常能体现算法思维
 *
 * 总边界开始 flood fill, 从低处往高处染色,
 * 如果高处的水能流到大海, 那么一定会经过边界, 所以只对边界进行flood fill就可以了
 * 最后把流向两个大海的位置合并, 重合的部分就是我们要的解
 */

class Solution {
private:
    int d[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int row, col;

    bool inArea(int x, int y){
        return x < row && x >= 0 && y < col && y >= 0;
    }

    void floodFill(vector<vector<int>>& matrix, int x, int y, vector<vector<bool>>& visited){
        visited[x][y] = true;

        for(int i = 0; i < 4; i++){
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            // 由低向高处染色, 因为高处的水一定会流向低处
            if(inArea(newx, newy) && matrix[x][y] <= matrix[newx][newy] && !visited[newx][newy])
                floodFill(matrix, newx, newy, visited);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {

        row = matrix.size();
        if(row == 0)
            return {};
        col = matrix[0].size();
        if(col == 0)
            return {};

        vector<vector<bool>> pacific = vector<vector<bool>>(row, vector<bool>(col, false));
        vector<vector<bool>> atlantic = vector<vector<bool>>(row, vector<bool>(col, false));

        // 从边界开始进行染色
        for(int i = 0; i < row; i++){
            floodFill(matrix, i, 0, pacific);
            floodFill(matrix, i, col-1, atlantic);
        }

        for(int i = 0; i < col; i++){
            floodFill(matrix, 0, i, pacific);
            floodFill(matrix, row-1, i, atlantic);
        }

        vector<vector<int>> res;
        /// 同时流向 pacific 和 atlantic 的就是我们要的答案
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});

        return res;
    }
};