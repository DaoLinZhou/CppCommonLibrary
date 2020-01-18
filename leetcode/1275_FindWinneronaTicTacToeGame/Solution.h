//
// Created by Daolin on 2020/1/17.
//
#include "../commonHeader.h"

class Solution {
public:

    bool checkWinners(vector<vector<char>>& vector, int &r, int &w) {
        int i = 0;
        for(; i < 3 && vector[i][w] == vector[r][w]; i++);
        if(i == 3) return true;
        for(i = 0; i < 3 && vector[r][i] == vector[r][w]; i++);
        if(i == 3) return true;
        if(r == w){
            for(i = 0; i < 3 && vector[i][i] == vector[r][w]; i++);
            if(i == 3) return true;
        }
        if(r+w == 2){
            for(i=0; i < 3 && vector[i][2-i] == vector[r][w]; i++);
            if(i == 3) return true;
        }
        return false;
    }

    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> grid(3, vector<char>(3, ' '));
        bool isX = true;
        for(int i = 0; i < moves.size(); i++){
            grid[moves[i][0]][moves[i][1]] = isX ? 'X' : 'O';
            if(checkWinners(grid, moves[i][0], moves[i][1]))
                return isX ? "A" : "B";
            isX = !isX;
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
