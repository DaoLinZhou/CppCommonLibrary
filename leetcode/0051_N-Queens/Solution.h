//
// Created by Daolin on 2019/10/3.
//
#include "../commonHeader.h"

/**
 * 解题思路:
 *
 * 在做此题之前要先明白一些数学知识
 * 1. 在n*n的矩阵中, 有2*n-1个主对角线/次对角线
 * 2. 同一个次对角线(右上到左下)上x, y之和一样
 * 3. 同一个主对角线(左上到右下)上x, y之差一样,
 *  由于取差会有负值, -(n-1) 到 0 到 (n-1)
 *  所以在具体计算时, 要偏移n-1个单位, 让结果为正数
 */

class Solution {
private:
    vector<vector<string>> res;

    /// dia1 是次对角线, dia2 是主对角线
    vector<bool> col, dia1, dia2;

    /// 尝试在一个n皇后问题中, 摆放第index行的皇后的位置
    void putQueen(int n, int index, vector<int> &row){
        if(index == n){
            res.push_back(generateBoard(n, row));
            return;
        }

        for(int i = 0; i < n; i++){
            /// 尝试将第index行的皇后摆放在第i列
            if(!col[i] && !dia1[index+i] && !dia2[index-i+n-1]){
                row.push_back(i);
                col[i] = true;
                dia1[index+i] = true;
                dia2[index-i+n-1] = true;
                putQueen(n, index+1, row);
                col[i] = false;
                dia1[index+i] = false;
                dia2[index-i+n-1] = false;
                row.pop_back();
            }
        }

        return;
    }

    vector<string> generateBoard(int n, vector<int>& row){
        assert(row.size() == n);
        vector<string> board(n, string(n, '.'));
        for(int i = 0; i < n; i++)
            board[i][row[i]] = 'Q';
        return board;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        col = vector<bool>(n, false);
        dia1 = vector<bool>(2*n-1, false);
        dia2 = vector<bool>(2*n-1, false);

        vector<int> row;
        putQueen(n, 0, row);

        return res;
    }
};
