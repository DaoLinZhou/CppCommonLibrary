//
// Created by Daolin on 2019/9/29.
//
#include "../commonHeader.h"

class Solution {
private:
    int d[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    int m, n;
    vector<vector<bool>> visited;
    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool searchWord(const vector<vector<char>>& board, const string& word, int index, int startx, int starty){
        if(index == word.size() - 1)
            return board[startx][starty] == word[index];

        if(board[startx][starty] == word[index]){
            visited[startx][starty] = true;
            for(int i = 0; i < 4; i++){
                int newX = startx + d[i][0];
                int newY = starty + d[i][1];

                if(inArea(newX, newY) && !visited[newX][newY] &&
                        searchWord(board, word, index+1, newX, newY))
                        return true;
            }
            visited[startx][starty] = false;
        }

        return false;
    }
public:
    bool exist(vector <vector<char>> &board, string word) {
        m = board.size();
        n = board[0].size();

        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                if(searchWord(board, word, 0, i, j))
                    return true;
        return false;
    }
};
