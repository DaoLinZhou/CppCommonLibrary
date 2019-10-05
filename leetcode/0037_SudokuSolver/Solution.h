//
// Created by Daolin on 2019/10/4.
//

#include <cstring>
#include "../commonHeader.h"

class Solution {
private:
    bool row[9][9];
    bool col[9][9];
    bool grid[9][9];

    bool find = false;

    /// 回溯求解
    void solver(vector<vector<char>>& board, vector<pair<int, int>>& empty, int index){
        if(index == empty.size()) {
            find = true;
            return;
        }
        // 要进行填充的位置
        int r = empty[index].first;
        int l = empty[index].second;

        for(char i = 0; i < 9; i++){
            if(!row[r][i] && !col[l][i] && !grid[(r/3)*3+(l/3)][i]){
                row[r][i] = true;
                col[l][i] = true;
                grid[(r/3)*3+(l/3)][i] = true;
                board[r][l] = i+'1';

                solver(board, empty, index+1);

                // 如果递归后发现找到了解就直接返回, 不再进行搜索, 因为默认只有一个解
                if(find) return;

                row[r][i] = false;
                col[l][i] = false;
                grid[(r/3)*3+(l/3)][i] = false;
                board[r][l] = '.';
            }
        }
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        /// 初始化三个记录的二维数组
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(grid, 0, sizeof(grid));

        /// 记录要进行填充的位置
        vector<pair<int, int>> empty;

        /// 对数独进行分析
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                if(board[i][j] != '.'){
                    int c = board[i][j]-'1';
                    row[i][c] = true;
                    col[j][c] = true;
                    grid[(i/3)*3+(j/3)][c] = true;
                }else{ /// 记录要进行填充的位置
                    empty.emplace_back(i, j);
                }

        solver(board, empty, 0);
    }
};
