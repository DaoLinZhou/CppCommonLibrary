//
// Created by Daolin on 2019/9/29.
//
#include "../commonHeader.h"

/**
 * 解题思路:
 *
 * 可以理解为深度遍历,
 * 每个元素的相邻4个元素是他的孩子节点, 这样的树形结构可以使用回溯法
 * 注意, 为了不重复访问应该添加一个visited判断元素是否被访问过
 *
 */

class Solution {
public:
    /// {y, x}
    int move[4][2] = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
    };
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        // 初始化visited
        vector<bool> item(col, false);
        vector<vector<bool>> visited(row, item);

        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                // 只有第一个元素一样才继续向下查找
                if(board[i][j] == word[0]){
                    visited[i][j] = true;
                    // j 对应x, i对应y, 找到直接返回true
                    if (find(board, j, i, word, 1, visited))
                        return true;
                    visited[i][j] = false;
                }
        return false;
    }

    // 寻找x,y开始 是否能找到word从start开始的substr
    bool find(vector<vector<char>>& board, const int& x, const int& y,
              const string& word, const int& start,
              vector<vector<bool>>& visited){
        if(start == word.size())
            return true;
        // 查找x, y周围是否有和word[start]一样的字母
        for(int i = 0; i < 4; i++){
            int newY = y + move[i][0];
            int newX = x + move[i][1];
            // 如果越界, 访问过, 不同 则跳过
            if(newX >= visited[0].size() || newX < 0 || newY >= visited.size() || newY < 0 ||
               visited[newY][newX] || board[newY][newX] != word[start])
                continue;
            // 存在, 递归查找
            visited[newY][newX] = true;
            if(find(board, newX, newY, word, start+1, visited))
                return true;
            visited[newY][newX] = false;
        }
        return false;
    }

};