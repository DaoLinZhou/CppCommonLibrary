//
// Created by Daolin on 2020/5/16.
//

#include "../commonHeader.h"

/**
 * 思路: 汽车一直向前走, 走到没有油的时候就从 走过的加油站 中选一个油量最大的加油站加油
 * 颠倒了先加油再走的顺序, 而是先走再加油
 */

class Solution {
public:

    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> queue;
        int i = 0;
        for(; i < stations.size(); i++){
            if(stations[i][0] > startFuel)
                break;
            queue.push(stations[i][1]);
        }

        int res = 0;
        while(startFuel < target){
            if(queue.empty()){
                return -1;
            }

            res++;
            int newfuel = queue.top();
            queue.pop();
            startFuel += newfuel;
            for(; i < stations.size(); i++){
                if(stations[i][0] > startFuel)
                    break;
                queue.push(stations[i][1]);
            }
        }
        return res;
    }
};
