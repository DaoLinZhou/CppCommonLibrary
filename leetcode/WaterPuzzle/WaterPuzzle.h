//
// Created by Daolin on 2020/8/30.
//

#ifndef ALGORITHM_WATERPUZZLE_H
#define ALGORITHM_WATERPUZZLE_H

#include "../commonHeader.h"
class WaterPuzzle{

public:

    vector<int> pre;
    int end = -1;

    // 两个桶, 一个容量5, 一个容量3
    WaterPuzzle(){
        queue<int> queue;
        vector<bool> visited(100, false);
        pre = vector<int>(100, -1);

        queue.push(0);
        visited[0] = true;

        while(!queue.empty()){
            int cur = queue.front();
            queue.pop();
            int a = cur / 10;
            int b = cur % 10;

            vector<int> nexts;
            nexts.push_back(5 * 10 + b); // 把5桶倒满
            nexts.push_back(a * 10 + 3); // 把3桶倒满
            nexts.push_back(b);          // 把5桶倒光
            nexts.push_back(a * 10);     // 把3桶倒光

            int x = min(a, 3 - b);      // 从5桶导入3桶
            nexts.push_back((a-x)*10 + (b+x));

            int y = min(5 - a, b);      // 从3桶导入5桶
            nexts.push_back((a+y)*10 + (b-y));

            for(int next : nexts){
                if(!visited[next]){
                    queue.push(next);
                    visited[next] = true;
                    pre[next] = cur;

                    if(next / 10 == 4 || next % 10 == 4){
                        end = next;
                        return;
                    }
                }
            }
        }
    }

    vector<int> result(){
        vector<int> res;
        if(end == -1){
            return res;
        }

        int cur = end;
        while(cur != 0){
            res.push_back(cur);
            cur = pre[cur];
        }
        res.push_back(0);
        reverse(res.begin(), res.end());
        return res;
    }

};

#endif //ALGORITHM_WATERPUZZLE_H
