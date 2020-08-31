//
// Created by Daolin on 2020/8/30.
//

#ifndef ALGORITHM_SOLUTION_H
#define ALGORITHM_SOLUTION_H

#include "../commonHeader.h"

/**
 * floodFill 算法, 把锁想象成一张图 "0000", 有8个方向,
 * "0000" -> "1000"
 * "0000" -> "9000"
 * ....
 * 每一位有两种可能, 一共有4位
 * 所以每次有8种可能.即8个方向.
 * 根据这8个方向进行 广度优先 floodfill
 */

class Solution {
private:
    unordered_set<string> visited;
    unordered_set<string> deadends;

    void getPre(string& s, int index){
        if(s[index] == '0'){
            s[index] = '9';
        }else{
            s[index] --;
        }
    }

    void getNext(string& s, int index){
        if(s[index] == '9'){
            s[index] = '0';
        }else{
            s[index] ++;
        }
    }

public:
    int openLock(vector<string>& deadends, const string& target) {
        for(string& s:deadends)
            this->deadends.insert(s);
        if(this->deadends.count("0000") > 0)
            return -1;
        string start = "0000";
        if(target == start)
            return 0;
        return bfs(start, target);
    }

    int bfs(string& s, const string& target){
        queue<pair<string, int>> queue;
        queue.push({s, 0});
        visited.insert(s);

        while(!queue.empty()){
            string num = queue.front().first;
            int count = queue.front().second;
            queue.pop();

            for(int i = 0; i < 4; i++){
                getNext(num, i);
                if(deadends.count(num) == 0 && visited.count(num) == 0) {
                    if(num == target)
                        return count+1;
                    queue.push({num, count + 1});
                    visited.insert(num);
                }
                getPre(num, i);

                getPre(num, i);
                if(deadends.count(num) == 0 && visited.count(num) == 0) {
                    if(num == target)
                        return count+1;
                    queue.push({num, count + 1});
                    visited.insert(num);
                }
                getNext(num, i);
            }
        }
        return -1;
    }


};

#endif //ALGORITHM_SOLUTION_H
