//
// Created by Daolin on 2020/8/30.
//

#ifndef ALGORITHM_SOLUTION_H
#define ALGORITHM_SOLUTION_H

#include "../commonHeader.h"

class Solution {
private:
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    int getState(vector<vector<int>>& board){
        int i = 100000;
        int res = 0;

        for(auto& v : board){
            for(auto& e : v){
                res += i * e;
                i /= 10;
            }
        }
        return res;
    }

    bool inArea(int x, int y){
        return x >= 0 && x < 2 && y >= 0 && y < 3;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_set<int> visited;     // 维护是否访问过
        queue<pair<int, int>> zero;     // 维护0的位置
        queue<int> steps;               // 维护当前步骤
        queue<vector<vector<int>>> queue;   // 维护board的状态

        int startState = getState(board);
        if(123450 == startState) return 0;

        // 放入其实点到容器
        visited.insert(startState);
        queue.push(board);
        steps.push(0);
        for(int i = 0; i < 6; i++){     // 寻找到最开始0的位置
            if(board[i/3][i%3] == 0) {
                zero.push({i/3, i%3});
                break;
            }
        }

        while(!queue.empty()){
            // 获取图的状态
            vector<vector<int>> b = queue.front();
            queue.pop();

            // 获取 0 的位置
            int x = zero.front().first;
            int y = zero.front().second;
            zero.pop();

            // 获取当前步骤
            int step = steps.front();
            steps.pop();

            for(auto& offset : d){

                // 获取新的0的位置
                int new_x = x+offset[0];
                int new_y = y+offset[1];

                if(inArea(new_x, new_y)) {
                    swap(b[x][y], b[new_x][new_y]);

                    int stat = getState(b);
                    if(visited.count(stat) == 0) {  // 如果没被访问过
                        if(123450 == stat)  // 提前退出
                            return step+1;

                        // 维护容器
                        queue.push(b);
                        visited.insert(stat);
                        steps.push(step + 1);
                        zero.push({new_x, new_y});
                    }

                    swap(b[x][y], b[new_x][new_y]);
                }
            }
        }
        return -1;
    }
};


#endif //ALGORITHM_SOLUTION_H
