//
// Created by Daolin on 2019/10/1.
//
#include "../commonHeader.h"

/**
 * 解题思路:
 *
 * 使用floodfill算法, 如果染色区域没有碰到边界, 就把这片区域改为X
 *
 */

class Solution {
private:
    int d[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int row, col;
    vector<vector<bool>> visited;

    bool inArea(int x, int y){
        return x >= 0 && x < row && y >= 0 && y < col;
    }

    bool onBoard(int x, int y){
        return x == 0 || x+1 == row || y == 0 || y+1 == col;
    }

    bool surround(const vector<vector<char>>& board, int x, int y){
        visited[x][y] = true;

        // 标记区域是否不在边界
        bool flag = !onBoard(x, y);

        for(int i = 0; i < 4; i++){
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if(inArea(newx, newy) && board[newx][newy] == 'O' && !visited[newx][newy])
                flag = surround(board, newx, newy) && flag; /// 注意这里一定要让flag在后面, 如果在前面可能会因为flag是false而跳过函数执行
        }

        return flag;
    }

    void change(vector<vector<char>>& board, int x, int y){
        board[x][y] = 'X';
        for(int i = 0; i < 4; i++){
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if(inArea(newx, newy) && board[newx][newy] == 'O')
                change(board, newx, newy);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        row = board.size();
        if(row <= 2)
            return;
        col = board[0].size();
        if(col <= 2)
            return;

        visited = vector<vector<bool>>(row, vector<bool>(col, false));

        for(int i = 0; i < row; i ++)
            for(int j = 0; j < col; j++)
                if(board[i][j] == 'O' && !visited[i][j] && surround(board, i, j))
                    change(board, i, j);
    }
};
